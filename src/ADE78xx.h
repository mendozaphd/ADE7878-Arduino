
#ifndef _ADE78XX_H_
#define _ADE78XX_H_

#include <Arduino.h>
#include <Wire.h>
//#include <I2Cdev.h>
#include <ADE7878_reg.h>

#ifndef BUFFER_LENGTH
#define BUFFER_LENGTH 32
#endif

//
//#define I2CDEV_DEFAULT_READ_TIMEOUT 1000
class ADE78XX
{

public:
    ADE78XX();
    ADE78XX(int rst_pin_ = -1, int irq1_pin_ = -1, int pm0_pin_ = -1, int pm1_pin_ = -1, int ss_pin_ = -1, int irq0_pin_ = -1);
    bool init();
    void reset();

    int32_t readADERegister(uint16_t reg, uint8_t reg_len);
    void writeADERegister(uint16_t reg, uint8_t reg_len, int32_t val);
    bool readBitADERegister(uint16_t reg, uint8_t reg_len, uint8_t bit_posicion);
    void writeBitADERegister(uint16_t reg, uint8_t reg_len, uint8_t bit_posicion, bool value);
    void modifyBitsInRegister(uint16_t reg, uint8_t reg_len, uint8_t start_posicion, int32_t value, int number_of_bits);
    void setPGA_Gain(uint32_t gain_);
    void setV_Gain(uint32_t gain_);
    void setI_Gain(uint32_t gain_);
    bool available();
    // Return True if one  IRQPINX was activated to LOW, flag returns 1 if irq0 pin was activated, returns 2 if irq1 and 3 if both
    bool irq_event(uint8_t *flag);
    void checkIRQ0event();
    void checkIRQ1event();
    float getVRMS(int _phase);
    float getARMS(int _phase);
    void setMeterFormConfiguration(uint8_t mode_);
    void setThreePhaseMeasure();

private:
    static void irq0_();
    static void irq1_();
};

#endif