/*
Autor: David W.
Date:26.05.2015
MSP430 Projekt Breaklight

define function for PWM 
Q&D :) should be optimized! 
if statment should only set the duty cycle and the output for the red led 
*/
#include <msp430g2553.h>

#define pwm_flash BIT0 // Red Led on Launchpad for test reasons
#define LED_GREEN   BIT6 // Green LED on Launchpad for test reasons

void set_pwm(int option)
{volatile int i;
  if(option == 1){
  P1SEL |= LED_GREEN;       // LED shows PWM
  P1DIR |= LED_GREEN + BIT0 ;
  TACCR0 = 1000;            // frequency for PWM
  TACCR1 = 1000;             // dutycycle 1:1
  TACCTL1 = OUTMOD2 | OUTMOD1 | OUTMOD0;    // TAO.1 Outmode_7
  TACTL = TASSEL1 | MC0 | TACLR;            // set timer and reset
 
  // loop forever
  for (;;) {
    // toggle bit 0 of P1
    P1OUT ^= pwm_flash;
    // delay for a while
    for (i = 0; i < 0x3000; i++);
  }
  }else{
   P1SEL |= LED_GREEN;       // LED showsPWM
  P1DIR |= LED_GREEN;
  TACCR0 = 1000;            // frequency
  TACCR1 = 500;             // duty cyle 1:2
  TACCTL1 = OUTMOD2 | OUTMOD1 | OUTMOD0;    // TAO.1 Outmode_7
  TACTL = TASSEL1 | MC0 | TACLR;            // set timer and reset
  
  }
}
