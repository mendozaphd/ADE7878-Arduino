
//#include "Arduino.h"
#include "ADE78xx.h"

bool __init = false;
bool __init1 = false;
bool _initOK, irq1_flag, irq0_flag;
uint8_t irq1_pin, irq0_pin, pm0_pin, pm1_pin, rst_pin, ss_pin;
#define POWER_PIN 19

ADE78XX::ADE78XX()
{
}

ADE78XX::ADE78XX(int rst_pin_, int irq1_pin_, int pm0_pin_, int pm1_pin_, int ss_pin_, int irq0_pin_)
{
    irq1_pin = irq1_pin_;
    irq0_pin = irq0_pin_;
    pm0_pin = pm0_pin_;
    pm1_pin = pm1_pin_;
    rst_pin = rst_pin_;
    ss_pin = ss_pin_;
}

bool ADE78XX::init()
{
    pinMode(POWER_PIN, OUTPUT);
    digitalWrite(POWER_PIN, 0);
    delay(100);
    pinMode(irq1_pin, INPUT_PULLDOWN);
    // pinMode(irq0_pin, INPUT_PULLDOWN);
    pinMode(rst_pin, OUTPUT);
    pinMode(pm0_pin, OUTPUT);
    pinMode(pm1_pin, OUTPUT);
    digitalWrite(pm0_pin, 1);
    digitalWrite(pm1_pin, 0);
    pinMode(ss_pin, INPUT);
    reset();
    if (!digitalRead(pm0_pin) && digitalRead(pm1_pin))
    {
        Serial.println("PMs Bad");
        return false;
    }

    Wire.beginTransmission(CHIP_ADDRESS);
    byte dummy;
    Wire.write(&dummy, 0);
    if (Wire.endTransmission() == 0)
        Serial.println("Chip Founded Over I2C Bus");
    else
        Serial.println("Chip NOT Founded Over I2C Bus");

    __init = false;
    __init1 = false;
    attachInterrupt(digitalPinToInterrupt(irq1_pin), irq1_, CHANGE); // Wait for complet hardware reset
    attachInterrupt(digitalPinToInterrupt(irq0_pin), irq0_, CHANGE); // Wait for complet hardware reset
    unsigned long __timeout = millis();
    while ((millis() - __timeout) < 1000)
        if (__init)
            break;

    writeADERegister(CONFIG2, 1, I2C_LOCK); // Lock I2C port
    if (!readBitADERegister(CONFIG2, 1, 1))
    {
        Serial.println("I2C LOCK Bad");
        return false;
    }

    Serial.println(">>Status1 = 0b" + String(readADERegister(STATUS1, 4), BIN));
    Serial.println(">>Status0 = 0b" + String(readADERegister(STATUS0, 4), BIN));
    writeADERegister(STATUS1, 4, 0xFFFFFFFF); // clear all Int
    writeADERegister(STATUS0, 4, 0xFFFFFFFF); // clear all Int
    Serial.println("<<Status1 = 0b" + String(readADERegister(STATUS1, 4), BIN));
    Serial.println("<<Status0 = 0b" + String(readADERegister(STATUS0, 4), BIN));
    // writeBitADERegister(STATUS1, 4, 15, 1); //Set RST_DONE BIT
    __timeout = millis();
    while ((millis() - __timeout) < 1000) // Wait for IRQ1 change
        if (__init1)
            break;

    if (!__init1 && !__init)
    {
        Serial.println("Interrupts BAD");
        return false;
    }

    // Set High Pass Filter enable
    writeADERegister(HPFDIS, 3, 0x0);

    // 5. Initialize the CF1DEN, CF2DEN, and CF3DEN registers with the CFxDEN value of 1
    writeADERegister(CF1DEN, 2, 0x1);
    writeADERegister(CF2DEN, 2, 0x1);
    writeADERegister(CF3DEN, 2, 0x1);

    // Select the PGA gains in the phase currents, voltages, and neutral current channels: Bits [2:0] (PGA1), Bits [5:3] (PGA2) and Bits [8:6] (PGA3) in the Gain register.
    setPGA_Gain(PGA1_16);
    setPGA_Gain(PGA2_16);
    setPGA_Gain(PGA3_1);

    writeBitADERegister(CONFIG, 2, 0, 1); // Clear Bit 0 (INTEN) of the CONFIG register if a regular current transformer (CT) is used. Set Bit 0 (INTEN) of the CONFIG register to 1 if a Rogowski coil is used to enable the digital integrator.

    writeBitADERegister(COMPMODE, 2, 14, 1); // If fn=60 Hz, set Bit 14 (SELFREQ) in COMPMODE register (ADE7878 only).

    /*Initialize WTHR1 and WTHR0 registers based on Equation 25. Make VARTHR1 (ADE7858, ADE7868, and
ADE7878 only) and VATHR1 equal to WTHR1 and
VARTHR0 (ADE7858, ADE7868, and ADE7878 only) and VATHR0 equal to WTHR0.
*/
    // Configure WTHR registers to PMAX (24 bit registers into 32 bit register?)
    writeADERegister(WTHR0, 4, (PMAX & 0xFFFFFF));
    writeADERegister(WTHR1, 4, (PMAX << 24));

    // Configure VARTH registers to PMAX (24 bit registers into 32 bit register?)
    writeADERegister(VARTHR0, 4, (PMAX & 0xFFFFFF));
    writeADERegister(VARTHR1, 4, (PMAX << 24));

    // Configure VATH registers to PMAX (24 bit registers into 32 bit register?)
    writeADERegister(VATHR0, 4, (PMAX & 0xFFFFFF));
    writeADERegister(VATHR1, 4, (PMAX << 24));
    // writeADERegister(COMPMODE, 2, 0x1 << 9);

    // Initialize VLEVEL (ADE7878 only) and VNOM registers based on Equation 21 and Equation 42.
    // writeADERegister(VNOM, 4, 1579955);

    //
    int32_t aian = 0x20;
    setI_Gain(aian);
    setI_Gain(aian);
    setI_Gain(aian);
    readADERegister(AIRMS, 4);
    readADERegister(BIRMS, 4);
    readADERegister(CIRMS, 4);
    writeADERegister(VLEVEL, 4, 8000000);
    aian = 0xbef5c28f;
    setI_Gain(aian);
    setI_Gain(aian);
    setI_Gain(aian);
    // setV_Gain(0xbf733333);
    setV_Gain(0xbf739581);
    setV_Gain(0xbf739581);
    setV_Gain(0xbf739581);
    unsigned long sta = millis();
    for (int i = 0; i < 300; i++)
    {
        readADERegister(AIRMS, 4);
        readADERegister(BIRMS, 4);
        readADERegister(CIRMS, 4);
    }
    Serial.println("Tardo " + String(millis() - sta) + " ms");
    setMeterFormConfiguration(0);
    setThreePhaseMeasure();
    Serial.println("> ACCMODE= 0b" + String(readADERegister(ACCMODE, 1), BIN));

    Serial.println("> CompMode= 0b" + String(readADERegister(COMPMODE, 2), BIN));
    Serial.println("> CONfig= 0b" + String(readADERegister(CONFIG, 2), BIN));

    Serial.println(">>AIGAIN = 0b" + String(readADERegister(AIGAIN, 4), BIN));
    Serial.println(">>BIGAIN = 0b" + String(readADERegister(AIGAIN, 4), BIN));
    Serial.println(">>BIGAIN = 0b" + String(readADERegister(AIGAIN, 4), BIN));
    //  setI_Gain(0xfa0c110);

    /*         writeADERegister(AVGAIN, 4, 0xbf739581);
        writeADERegister(BVGAIN, 4, 0xbf739581);
        writeADERegister(CVGAIN, 4, 0xbf739581);

     */

    Serial.println(">>ACCmode = 0b" + String(readADERegister(ACCMODE, 1), BIN));

    // Serial.println(">>Config = 0b" + String(readADERegister(CONFIG, 2), BIN));

    // Serial.println(">>Gain = 0b" + String(readADERegister(Gain, 2), BIN));
    // Serial.println("Status1 = 0b" + String(readADERegister(STATUS1, 4), BIN));
    // Serial.println("Status0 = 0b" + String(readADERegister(STATUS0, 4), BIN));

    // lock RAM registers
    writeADERegister(0xE7FE, 1, 0xAD);
    writeADERegister(0xE7E3, 1, 0x80);

    // Start the DSP
    writeADERegister(Run, 2, START);

    // Read the energy registers xWATTHR, xFWATTHR,
    // xVARHR, xFVARHR, and xVAHR to erase their content
    // and start energy accumulation from a known state.

    readADERegister(AWATTHR, 4);
    readADERegister(BWATTHR, 4);
    readADERegister(CWATTHR, 4);
    readADERegister(AFWATTHR, 4);
    readADERegister(BFWATTHR, 4);
    readADERegister(CFWATTHR, 4);
    readADERegister(AVARHR, 4);
    readADERegister(BVARHR, 4);
    readADERegister(CVARHR, 4);
    readADERegister(AFVARHR, 4);
    readADERegister(BFVARHR, 4);
    readADERegister(CFVARHR, 4);
    readADERegister(AVAHR, 4);
    readADERegister(BVAHR, 4);
    readADERegister(CVAHR, 4);

    irq0_flag = false;
    irq1_flag = false;

    _initOK = true;
    return true;
}

bool ADE78XX::available()
{
    return readBitADERegister(Run, 2, 0);
}

void ADE78XX::reset()
{
    digitalWrite(rst_pin, 0);
    delay(30);
    digitalWrite(rst_pin, 1);
}

ICACHE_RAM_ATTR void ADE78XX::irq1_()
{
    // elap = millis() - tiempo;
    // Serial.print("Se activo el pin IRQ1 --- ");
    // detachInterrupt(irq1_pin);
    if (!digitalRead(irq1_pin))
        __init = true;
    else
        __init1 = true;

    Serial.println(digitalRead(irq1_pin) ? "IRQ1= HIGH" : "IRQ1= LOW");
    irq1_flag = true;
}

ICACHE_RAM_ATTR void ADE78XX::irq0_()
{
    Serial.println(digitalRead(irq0_pin) ? "IRQ0= HIGH" : "IRQ0= LOW");
    irq0_flag = true;
}

int32_t ADE78XX::readADERegister(uint16_t reg, uint8_t reg_len)
{
    uint8_t data[reg_len];
    uint32_t res = 0;
    Wire.beginTransmission(CHIP_ADDRESS);
    Wire.write(uint8_t(reg >> 8));
    Wire.write(uint8_t(reg & 0xFF));
    Wire.endTransmission(false);
    Wire.requestFrom((uint8_t)CHIP_ADDRESS, (uint8_t)4, (uint8_t) true);
    if (Wire.available() >= 1)
        for (int j = 0; j < reg_len; j++)
        {
            data[j] = Wire.read();
            // Serial.print(" Byte #" + String(j) + " = 0x" + String(data[j], HEX));
        }
    res |= data[0];
    if (reg_len > 1)
        for (int i = 1; i < reg_len; i++)
        {
            res = res << 8;
            res = res | data[i];
        }
    return res;
}

void ADE78XX::writeADERegister(uint16_t reg, uint8_t reg_len, int32_t val)
{
    Wire.beginTransmission(CHIP_ADDRESS);
    Wire.write(uint8_t(reg >> 8));
    Wire.write(uint8_t(reg & 0xFF));
    uint8_t dato;
    int shift = 8 * (reg_len - 1);
    if (reg_len > 1)
        for (int i = 0; i < reg_len; i++)
        {
            dato = val >> shift;
            // Serial.print(" >Dat #" + String(i) + " = 0x" + String(dato, HEX));
            Wire.write(dato);
            shift -= 8;
        }
    else
    {
        dato = val & 0xff;
        // Serial.println(" Dato= 0x" + String(dato, HEX));
        Wire.write(dato);
    }
    Wire.endTransmission();
}

void ADE78XX::modifyBitsInRegister(uint16_t reg, uint8_t reg_len, uint8_t start_posicion, int32_t value, int number_of_bits)
{

    int32_t data_ = readADERegister(reg, reg_len);
    //   Serial.println("Old Value = 0b" + String(data_, BIN));

    for (size_t i = start_posicion; i < (number_of_bits + start_posicion); i++)
        bitWrite(data_, i, bitRead(value, (i - start_posicion)));
    writeADERegister(reg, reg_len, data_);
    // Serial.println("Valor a escribir 0b =" + String(value, BIN));
    // Serial.println("New Value = 0b" + String(data_, BIN));
}

bool ADE78XX::readBitADERegister(uint16_t reg, uint8_t reg_len, uint8_t bit_posicion)
{
    return bitRead(readADERegister(reg, reg_len), bit_posicion);
}

void ADE78XX::writeBitADERegister(uint16_t reg, uint8_t reg_len, uint8_t bit_posicion, bool value)
{
    uint32_t value_ = readADERegister(reg, reg_len);
    //  Serial.println("Value A = 0b" + String(value_, BIN));
    bitWrite(value_, bit_posicion, value);
    //  Serial.println("Value D = 0b" + String(value_, BIN));
    writeADERegister(reg, reg_len, value_);
}

void ADE78XX::setPGA_Gain(uint32_t gain_)
{
    uint32_t PGA_value = readADERegister(Gain, 2);
    PGA_value = PGA_value | gain_;
    writeADERegister(Gain, 2, PGA_value);
}

void ADE78XX::setI_Gain(uint32_t gain_)
{
    writeADERegister(AIGAIN, 4, gain_);
    writeADERegister(BIGAIN, 4, gain_);
    writeADERegister(CIGAIN, 4, gain_);
    writeADERegister(NIGAIN, 4, gain_);
}

void ADE78XX::setV_Gain(uint32_t gain_)
{
    writeADERegister(AVGAIN, 4, gain_);
    writeADERegister(BVGAIN, 4, gain_);
    writeADERegister(CVGAIN, 4, gain_);
}

// get VRMS Phase A = 1, PhaseB = 2, Phase C = 3
float ADE78XX::getVRMS(int _phase)
{
    if (_phase < 1 || _phase > 3)
        return 0;
    // uint16_t __phase = AVRMS + (2 * (_phase - 1));
    // float vrms = readADERegister( AVRMS + (2 * (_phase - 1)), 4);
    // return vrms /= 1000;
    return (float(readADERegister(AVRMS + (2 * (_phase - 1)), 4)) / 1000);
}

// get IRMS Neutro = 0, Phase A = 1, PhaseB = 2, Phase C = 3
float ADE78XX::getARMS(int _phase)
{
    if (_phase < 1 || _phase > 4)
        return 0;
    uint16_t __phase = AIRMS + (2 * (_phase - 1));
    // Serial.println("Phase " + String(_phase) + " = Phase 0x" + String(__phase, HEX));
    return (float(readADERegister(__phase, 4)) / 100000);
}

// Return True if one  IRQPINX was activated to LOW, flag returns 1 if irq0 pin was activated, returns 2 if irq1 and 3 if both
bool ADE78XX::irq_event(uint8_t *flag)
{
    bool _flag = irq0_flag || irq1_flag;
    if (irq0_flag)
        *flag = 1;
    if (irq1_flag)
        *flag = 2;
    if (irq1_flag && irq0_flag)
        *flag = 3;
    irq0_flag = false;
    irq1_flag = false;
    return _flag;
}

void ADE78XX::checkIRQ0event()
{
    uint32_t _status = readADERegister(STATUS0, 4);
    Serial.println(">> Status0 bits = 0b" + String(_status, BIN));
}

void ADE78XX::checkIRQ1event()
{
    uint32_t _status = readADERegister(STATUS1, 4);
    Serial.println(">> Status1 bits = 0b" + String(_status, BIN));
}

void ADE78XX::setMeterFormConfiguration(uint8_t mode_)
{
    if (mode_ > 3)
        return;
    //writeADERegister(ACCMODE, 1, mode_ << 4);
    modifyBitsInRegister(ACCMODE, 1, 4, mode_, 2);
}

void ADE78XX::setThreePhaseMeasure()
{
    uint32_t __config = readADERegister(CONFIG, 2);
    // __config |= 0x2A00;
    __config |= 0x1501;
    writeADERegister(CONFIG, 2, __config);
}