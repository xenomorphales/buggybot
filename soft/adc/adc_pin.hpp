#ifndef ADC_PIN_HPP
#define ADC_PIN_HPP

#include <device/input.hpp>
#include <board/adm2560.hpp>

template<u32 ID>
class ADCPin : public Input<u16> {
public:
  ADCPin(void) {
    static_assert(ID == -1, "ADC IN invalid");
  }

  u16 getValue(void) {
    return 0;
  }
};

template<>
class ADCPin<ADM2560::Pinmap::A8> : public Input<u16> {
public:
  ADCPin(void) {
  }

  u16 getValue(void) {
    u16 ret = 0;
    
    ADMUX = (1 << REFS0) | (0 << MUX4) | (0 << MUX3) | (0 << MUX2) | (0 << MUX1) | (0 << MUX0); 
    ADCSRB = (1 << MUX5);
    ADCSRA = (1 << ADEN) | (1 << ADSC) | (0 << ADIE) | (0 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
    
    while(ADCSRA & (1 << ADSC));
    
    ret = ADCL;
    ret |= ((u16)ADCH) << 8;

    for(volatile u16 i = 0 ; i < 500 ; i++);
    return ret;
  }
};

template<>
class ADCPin<ADM2560::Pinmap::A9> : public Input<u16> {
public:
  ADCPin(void) {
  }

  u16 getValue(void) {
    u16 ret = 0;
    
    ADMUX = (1 << REFS0) | (0 << MUX4) | (0 << MUX3) | (0 << MUX2) | (0 << MUX1) | (1 << MUX0); 
    ADCSRB = (1 << MUX5);
    ADCSRA = (1 << ADEN) | (1 << ADSC) | (0 << ADIE) | (0 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
    
    while(ADCSRA & (1 << ADSC));
    
    ret = ADCL;
    ret |= ((u16)ADCH) << 8;

    for(volatile u16 i = 0 ; i < 500 ; i++);
    return ret;
  }
};

template<>
class ADCPin<ADM2560::Pinmap::A10> : public Input<u16> {
public:
  ADCPin(void) {
  }

  u16 getValue(void) {
    u16 ret = 0;
    
    ADMUX = (1 << REFS0) | (0 << MUX4) | (0 << MUX3) | (0 << MUX2) | (1 << MUX1) | (0 << MUX0); 
    ADCSRB = (1 << MUX5);
    ADCSRA = (1 << ADEN) | (1 << ADSC) | (0 << ADIE) | (0 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
    
    while(ADCSRA & (1 << ADSC));
    
    ret = ADCL;
    ret |= ((u16)ADCH) << 8;

    for(volatile u16 i = 0 ; i < 500 ; i++);
    return ret;
  }
};

template<>
class ADCPin<ADM2560::Pinmap::A11> : public Input<u16> {
public:
  ADCPin(void) {
  }

  u16 getValue(void) {
    u16 ret = 0;
    
    ADMUX = (1 << REFS0) | (0 << MUX4) | (0 << MUX3) | (0 << MUX2) | (1 << MUX1) | (1 << MUX1); 
    ADCSRB = (1 << MUX5);
    ADCSRA = (1 << ADEN) | (1 << ADSC) | (0 << ADIE) | (0 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
    
    while(ADCSRA & (1 << ADSC));
    
    ret = ADCL;
    ret |= ((u16)ADCH) << 8;

    for(volatile u16 i = 0 ; i < 500 ; i++);
    return ret;
  }
};


#endif//ADC_PIN_HPP
