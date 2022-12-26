#include "constants.h"
void configOsc(void)
{
    /*select frquency of internal osc freqency to be 16MHz*/
    OSCCONbits.IRCF3 = HI;
    OSCCONbits.IRCF2 = HI;
    OSCCONbits.IRCF1 = HI;
    OSCCONbits.IRCF0 = HI;
    
    //select internal oscillator
    OSCCONbits.SCS1 = HI;
    OSCCONbits.SCS0 = LO;
}
