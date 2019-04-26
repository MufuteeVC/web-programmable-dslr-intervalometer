/**
* This program will transmit a modulated infrared signal to a Nikon DSLR using
* a QED-123 IR LED
*/

#include "mbed.h"
#include "DslrIr.h"

DigitalIn trigger(p20);  /* Pull down trigger to enable shutter release */
DslrIr dslr(p21);

int main()
{
//    trigger.mode(PullUp);
    while(1) {
        if(!trigger) {
            dslr.trigger();
            wait(1);
        }
    }
}