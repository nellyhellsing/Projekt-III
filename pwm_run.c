/******************************************************************
*pwm_run.c: funktion till pwm_run.
*******************************************************************/
#include "gpio.h"

void pwm_run(void)
{
	adc_get_pwm_values(&a1, 1000);

	if (led1_pwm_enabled) led_on(&l1);
	if (led2_pwm_enabled) led_on(&l2);
	if (led3_pwm_enabled) led_on(&l3);
	if (led4_pwm_enabled) led_on(&l4);
	if (led5_pwm_enabled) led_on(&l5);

	delay_us(a1.pwm_on_us);

	led_off(&l1);
	led_off(&l2);
	led_off(&l3);
	led_off(&l4);
	led_off(&l5);
	
	delay_us(a1.pwm_off_us);
	return;
}
