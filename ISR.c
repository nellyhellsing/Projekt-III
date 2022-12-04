/********************************************************************
* ISR:ISR= interrupt service rutin, dvs funktion som äger rum vid avbrott
********************************************************************/
#include "gpio.h"
/*PCI-avbrott för tryckknappar anslutna till pin 11-13.*/
ISR (PCINT0_vect) // B
{
	if (button_is_pressed(&b3))
	{
		led3_pwm_enabled = !led3_pwm_enabled;	
	}
	else if (button_is_pressed(&b4))
	{
		led4_pwm_enabled = !led4_pwm_enabled;
		
	}
	else if (button_is_pressed(&b5))
	{
		led5_pwm_enabled  = !led5_pwm_enabled;
	}
	return;
}
/*PCI-avbrott för tryckknappar anslutna till pin 2-3.*/
ISR (PCINT2_vect)
{
	if (button_is_pressed(&b1))
	{
		led1_pwm_enabled = !led1_pwm_enabled;
	}
	else if (button_is_pressed(&b2))
	{
		led2_pwm_enabled = !led2_pwm_enabled;
	}
	return;
}
