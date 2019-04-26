/**
* MBED code functionality, including idea of modulating PWM signal, taken from
* https://os.mbed.com/users/viswesr/code/DSLR_Camera_IR_Remote/
* As the given values did not work on the Nikon D3300, they were modified,
* parameterized, and put into library form.
* 
* Inspiration, default values, and an Arduino validation signal were taken from
* https://bayesianadventures.wordpress.com/2013/08/09/nikon-ml-l3-ir-remote-hack/
*
* Library instructions were taken from https://os.mbed.com/cookbook/Writing-a-Library
*/

#include "DslrIr.h"

DslrIr::DslrIr(PinName pin) : _pin(pin) 
{
    _pin.period_us(PWM_PERIOD);                // set PWM period for Carrier Frequency of 38.4 KHz
    _pin = 0;
}




void DslrIr::trigger()
{
    _pin = ACTIVE_DUTY_CYCLE;
    wait_us(SEQ_ON_1_PERIOD);
    _pin = 0;
    wait_us(SEQ_OFF_1_PERIOD);
    _pin = ACTIVE_DUTY_CYCLE;
    wait_us(SEQ_ON_2_PERIOD);
    _pin = 0;
    wait_us(SEQ_OFF_2_PERIOD);
    _pin = ACTIVE_DUTY_CYCLE;
    wait_us(SEQ_ON_3_PERIOD);
    _pin = 0;
    wait_us(SEQ_OFF_3_PERIOD);
    _pin = ACTIVE_DUTY_CYCLE;
    wait_us(SEQ_ON_4_PERIOD);
    _pin = 0;
    wait_us(SEQ_OFF_4_PERIOD);  // Repeat after 63.2 us
    _pin = ACTIVE_DUTY_CYCLE;
    _pin = ACTIVE_DUTY_CYCLE;
    wait_us(SEQ_ON_1_PERIOD);
    _pin = 0;
    wait_us(SEQ_OFF_1_PERIOD);
    _pin = ACTIVE_DUTY_CYCLE;
    wait_us(SEQ_ON_2_PERIOD);
    _pin = 0;
    wait_us(SEQ_OFF_2_PERIOD);
    _pin = ACTIVE_DUTY_CYCLE;
    wait_us(SEQ_ON_3_PERIOD);
    _pin = 0;
    wait_us(SEQ_OFF_3_PERIOD);
    _pin = ACTIVE_DUTY_CYCLE;
    wait_us(SEQ_ON_4_PERIOD);
    _pin = 0;
}