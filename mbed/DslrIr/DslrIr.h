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

#ifndef DSLR_IR_H_
#define DSLR_IR_H_

#include "mbed.h"

class DslrIr {
public:
    DslrIr(PinName pin);
    void trigger();
 
private:
    PwmOut _pin;
    
    const static float ACTIVE_DUTY_CYCLE = 15.0/24;
    const static int PWM_PERIOD = 25;    
    const static int SEQ_ON_1_PERIOD = 2160;
    const static int SEQ_OFF_1_PERIOD = 27840;
    const static int SEQ_ON_2_PERIOD = 550;
    const static int SEQ_OFF_2_PERIOD = 1550;
    const static int SEQ_ON_3_PERIOD = 550;
    const static int SEQ_OFF_3_PERIOD = 3558;
    const static int SEQ_ON_4_PERIOD  = 550;
    const static int SEQ_OFF_4_PERIOD = 63000;
    const static int SEQ_ON_1_PERIOD2 = 2160;
    const static int SEQ_OFF_1_PERIOD2 = 27850;
    const static int SEQ_ON_2_PERIOD2 = 530;
    const static int SEQ_OFF_2_PERIOD2 = 1550;
    const static int SEQ_ON_3_PERIOD2 = 530;
    const static int SEQ_OFF_3_PERIOD2 = 3550;
    const static int SEQ_ON_4_PERIOD2  = 530;
};

#endif