/********************************************************************************
* led_vector.c: Innehåller funktionsdefinitioner för implementering av dynamiska
*               vektorer för lagring och styrning över multipla lysdioder eller
*               andra utportar via strukten led_vector.
********************************************************************************/
#include "led_vector.h"

/********************************************************************************
* led_vector_init: Initierar angiven vektor till tom vid start.
*
*                  - self: Pekare till vektorn som ska initieras.
********************************************************************************/
void led_vector_init(struct led_vector* self)
{
	self->data = 0;
	self->size = 0;
	return;
}
/********************************************************************************
* led_vector_clear: Tömmer och nollställer angiven vektor.
*
*                   - self: Pekare till vektorn som ska tömmas.
********************************************************************************/
void led_vector_clear(struct led_vector* self)
{
	free(self->data);
	self->data = 0;
	self->size = 0;
	return;
}
/********************************************************************************
* led_vector_push: Lägger till ett nytt led-objekt längst bak i angiven vektor.
*                  Vid misslyckad minnesallokering returneras felkod 1.
*                  Annars om push-operationen lyckas returneras 0.
*
*                  - self   : Pekare till vektorn som ska tilldelas.
*                  - new_led: Det nya led-objekt som ska läggas till.
********************************************************************************/
int led_vector_push(struct led_vector* self,
                    struct led* new_led)
{	
	struct led* copy = (struct led*)realloc(self->data, sizeof(struct led) * (self->size + 1));
	if(!copy) return 1;
	copy[self->size++] = *new_led;
	self->data = copy;
	return 0;
}
/********************************************************************************
* led_vector_on: Tänder samtliga lysdioder lagrade i angiven vektor.
*
*                - self: Pekare till vektorn vars lysdioder ska tändas.
********************************************************************************/
void led_vector_on(struct led_vector* self)
{
	for (size_t i = 0; i < self->size; ++i)
	{
		led_on(&self->data[i]);
	}
}
/********************************************************************************
* led_vector_off: Släcker samtliga lysdioder lagrade i angiven vektor.
*
*                 - self: Pekare till vektorn vars lysdioder ska släckas.
********************************************************************************/
void led_vector_off(struct led_vector* self)
{
	for (size_t i = 0; i < self->size; ++i)
	{
		led_off(&self->data[i]);
	}
	return;
}

/********************************************************************************
* led_vector_blink_collectively: Genomför kollektiv (synkroniserad) blinkning
*                                av samtliga lysdioder lagrade i angiven vektor.
*
*                                - self          : Pekare till vektorn vars
*                                                  lysdioder ska blinkas.
*                                - blink_speed_ms: Lysdiodernas blinkhastighet
*                                                  mätt i millisekunder.
********************************************************************************/
void led_vector_blink_collectively(struct led_vector* self,
                                   const uint16_t blink_speed_ms)
{
	led_vector_on(self); // Tänder alla.
	delay_ms(blink_speed_ms);
	led_vector_off(self);
	delay_ms(blink_speed_ms);
	return;
}

/********************************************************************************
* led_vector_blink_sequentially: Genomför sekventiell blinkning av samtliga
*                                lysdioder lagrade i angiven vektor. Därmed
*                                blinkar lysdioderna i en sekvens en efter en.
*
*                                - self          : Pekare till vektorn vars
*                                                  lysdioder ska blinkas.
*                                - blink_speed_ms: Lysdiodernas blinkhastighet
*                                                  mätt i millisekunder.
********************************************************************************/
void led_vector_blink_sequentially(struct led_vector* self,
                                   const uint16_t blink_speed_ms)
{
	for (size_t i = 0; i < self->size; ++i)
	{
		led_on(&self->data[i]);
		delay_ms(blink_speed_ms);
		led_off(&self->data[i]);
	}
	return;
}