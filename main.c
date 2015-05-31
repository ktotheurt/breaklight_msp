/* 
Author:David W.
ADC sets pwm 1 or 0 

*/
#include <msp430g2553.h>

#define LED_GREEN   BIT6
#define TASTE_S2    BIT3

int set_pwm(); // function declaration
int main(void) {

  // stop watchdog timer
  WDTCTL = WDTPW | WDTHOLD;
  
  BCSCTL1 = CALBC1_1MHZ;    // set system clock
  DCOCTL = CALDCO_1MHZ;
 
  
 set_pwm(1);
 
 
}
