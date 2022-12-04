/********************************************************************************
* led_vector.h: Inneh�ller funktionalitet f�r implementering av dynamiska
*               vektorer f�r lagring och styrning �ver multipla lysdioder eller
*               andra utportar, realiserat via strukten led_vector samt
*               associerade funktioner.
********************************************************************************/
#ifndef LED_VECTOR_H_
#define LED_VECTOR_H_

#include "misc.h"
#include "led.h"

/********************************************************************************
* led_vector: Dynamisk vektor f�r lagring och styrning av led-objekt, vilket
*             kan utg�ras av lysdioder eller andra digitala utportar.
********************************************************************************/
struct led_vector
{
	struct led*data;
	size_t size;
};

/*funktionsdeklarationer*/
void led_vector_init(struct led_vector* self);

void led_vector_clear(struct led_vector* self);

int led_vector_push(struct led_vector* self,
                    struct led* new_led);
					
void led_vector_on(struct led_vector* self);

void led_vector_off(struct led_vector* self);

void led_vector_blink_collectively(struct led_vector* self,
                                   const uint16_t blink_speed_ms);

void led_vector_blink_sequentially(struct led_vector* self,
                                   const uint16_t blink_speed_ms);

#endif /* LED_VECTOR_H_ */