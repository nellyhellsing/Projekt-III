/********************************************************************
*gpio.h: funktionsdeklarationer och globala variabler.
********************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

#include "led.h"
#include "button.h"
#include "adc.h"


extern struct led l1, l2, l3, l4, l5;
extern struct button b1, b2, b3, b4, b5;
extern struct adc a1;
extern volatile bool led1_pwm_enabled,
                     led2_pwm_enabled,
                     led3_pwm_enabled,
					 led4_pwm_enabled,
					 led5_pwm_enabled;

void setup(void);
void pwm_run(void);

#endif /* GPIO_H_ */