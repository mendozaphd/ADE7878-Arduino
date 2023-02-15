#include <Arduino.h>
#include <Wire.h>
#include <Ticker.h>
#include <ADE78xx.h>


Ticker power;

#define SQRT3 sqrt(3)

#define LED_RED 26
#define LED_BLUE 25
#define LED_GREEN 27
int leds[3] = {LED_RED /*ROJO*/, LED_GREEN /*GREEN*/, LED_BLUE /*BLUE*/};

#define CHECKHSUM 0xE51F
#define CONFIG2 0xEC01

#define I2CDEV_SERIAL_DEBUG 1
#define CHIP_ADDRESS 0x38

#define POWER_PIN 19
#define RESET 13
#define I2C_SDA 18
#define I2C_SCL 5
#define PM0 14
#define PM1 12
#define SS 15
#define IRQ1 22
#define IRQ0 23

ADE78XX medidor(RESET, IRQ1, PM0, PM1, SS, IRQ0);

unsigned long tiempo, elap;
void IRAM_ATTR irq();
void initI2C(), tick();

 typedef struct struct_message
 {
   float valor[30];
 } struct_message;

struct_message energia;

void setup()
{

  Serial.begin(115200);

  for (int i = 0; i < 3; i++)
    pinMode(leds[i], OUTPUT);
  digitalWrite(LED_RED, 1);
  delay(10);

  // while (!Serial)
  //   ;


  if (!Wire.begin(I2C_SDA, I2C_SCL)) // inicializa i2c
    Serial.println("Algo salio mal con el I2C");

  tiempo = millis();

  if (medidor.init())
  {
    Serial.println("Init OK");
    digitalWrite(LED_RED, 0);
    digitalWrite(LED_GREEN, 1);
  }

  // medidor.setMeterFormConfiguration(3);

  // power.attach(2, tick);
}

bool start;
uint8_t _bu[4];
int cambia = 0;
int modo = 1;

// float valores[30];
void loop()
{
  if (medidor.available())
  {
    digitalWrite(LED_GREEN, 1);
    // cambia++;
    // if (cambia > 10)
    // {
    //   Serial.println("Cambiando a modo " + String(modo));
    //   cambia = 0;
    //   medidor.setMeterFormConfiguration(modo);
    //   // medidor.modifyBitsInRegister(ACCMODE, 1, 4, modo,2);
    //   modo++;
    //   if (modo > 3)
    //     modo = 0;
    // }
    // Serial.print("  VRMS_A = " + String(SQRT3 * medidor.getVRMS(1)));
    // Serial.print("  VRMS_B = " + String(SQRT3 * medidor.getVRMS(2)));
    // Serial.print("  VRMS_C = " + String(SQRT3 * medidor.getVRMS(3)));
    energia.valor[0] = medidor.getVRMS(1);
    energia.valor[1] = medidor.getVRMS(2);
    energia.valor[2] = medidor.getVRMS(3);
    // energia.valor[3] = medidor.getVRMS(4);

    energia.valor[4] = medidor.getARMS(1);
    energia.valor[5] = medidor.getARMS(2);
    energia.valor[6] = medidor.getARMS(3);
    energia.valor[7] = medidor.getARMS(4);

    Serial.print(" A> Vrms= " + String(energia.valor[0]));
    Serial.print(" Arms " + String(energia.valor[4]));

    Serial.print(" B> Vrms= " + String(energia.valor[1]));
    Serial.print(" Arms " + String(energia.valor[5]));

    Serial.print(" C> Vrms= " + String(energia.valor[2]));
    Serial.print(" Arms " + String(energia.valor[6]));

    Serial.print(" N> Arms " + String(energia.valor[7]));

    Serial.print(" Angle0= " + String(medidor.readADERegister(ANGLE0, 2), DEC));
    Serial.print(" Angle1= " + String(medidor.readADERegister(ANGLE1, 2), DEC));
    Serial.print(" Angle2= " + String(medidor.readADERegister(ANGLE2, 2), DEC));
    // Serial.print(" Count =" + String(cambia) + "<");
    Serial.println();
    digitalWrite(LED_GREEN, 0);
    // delay(200);
  }
  else
  {
    digitalWrite(LED_GREEN, 0);
    digitalWrite(LED_RED, 1);
  }
  uint8_t irq = 0;

  if (medidor.irq_event(&irq) && medidor.available()) //interrupciones
  {
    Serial.println("Se acrivo la int=" + String(irq));
    switch (irq)
    {
    case 1:
      medidor.checkIRQ0event();
      break;
    case 2:
      medidor.checkIRQ1event();
      break;
    case 3:
      medidor.checkIRQ0event();
      medidor.checkIRQ1event();
      break;
    }
  }
}
