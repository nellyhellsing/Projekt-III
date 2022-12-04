/************************************************************************
* setup.c: Innehåller funktionsdeklarationer och globala variabler.                                                                    
************************************************************************/
#include "gpio.h"

struct led l1, l2, l3, l4, l5;
struct button b1, b2, b3, b4, b5;
struct adc a1;

volatile bool led1_pwm_enabled = false;
volatile bool led2_pwm_enabled = false;
volatile bool led3_pwm_enabled = false;
volatile bool led4_pwm_enabled = false;
volatile bool led5_pwm_enabled = false;

/*Initierar LEDs, tryckknappar och potentiometer. Och aktiverar PCI-avbrott.*/
void setup(void)
{
	led_init(&l1, 6);
	led_init(&l2, 7);
	led_init(&l3, 8);
	led_init(&l4, 9);
	led_init(&l5, 10);

	button_init(&b1, 2);
	button_init(&b2, 3);
	button_init(&b3, 11);
	button_init(&b4, 12);
	button_init(&b5, 13);

	adc_init(&a1, A0);

	button_enable_interrupt(&b1);
	button_enable_interrupt(&b2);
	button_enable_interrupt(&b3);
	button_enable_interrupt(&b4);
	button_enable_interrupt(&b5);
	
	return;

}

