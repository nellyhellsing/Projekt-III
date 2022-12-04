/******************************************************************
*main.c: PWM-styrning av fem leds, som ska aktiveras av tilldelad
tryckknapp.
*******************************************************************/
#include "gpio.h"
/******************************************************************
*main: Anropar funktionen setup och pwm_run.
*******************************************************************/

int main(void)
{
  setup();
	
	while (1)
	{
		pwm_run();
		
	}

	return 0;
}
