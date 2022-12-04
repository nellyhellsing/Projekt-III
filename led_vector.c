/********************************************************************************
* led_vector.c: Inneh�ller funktionsdefinitioner f�r implementering av dynamiska
*               vektorer f�r lagring och styrning �ver multipla lysdioder eller
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
* led_vector_clear: T�mmer och nollst�ller angiven vektor.
*
*                   - self: Pekare till vektorn som ska t�mmas.
********************************************************************************/
void led_vector_clear(struct led_vector* self)
{
	free(self->data);
	self->data = 0;
	self->size = 0;
	return;
}
/********************************************************************************
* led_vector_push: L�gger till ett nytt led-objekt l�ngst bak i angiven vektor.
*                  Vid misslyckad minnesallokering returneras felkod 1.
*                  Annars om push-operationen lyckas returneras 0.
*
*                  - self   : Pekare till vektorn som ska tilldelas.
*                  - new_led: Det nya led-objekt som ska l�ggas till.
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
* led_vector_on: T�nder samtliga lysdioder lagrade i angiven vektor.
*
*                - self: Pekare till vektorn vars lysdioder ska t�ndas.
********************************************************************************/
void led_vector_on(struct led_vector* self)
{
	for (size_t i = 0; i < self->size; ++i)
	{
		led_on(&self->data[i]);
	}
}
/********************************************************************************
* led_vector_off: Sl�cker samtliga lysdioder lagrade i angiven vektor.
*
*                 - self: Pekare till vektorn vars lysdioder ska sl�ckas.
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
* led_vector_blink_collectively: Genomf�r kollektiv (synkroniserad) blinkning
*                                av samtliga lysdioder lagrade i angiven vektor.
*
*                                - self          : Pekare till vektorn vars
*                                                  lysdioder ska blinkas.
*                                - blink_speed_ms: Lysdiodernas blinkhastighet
*                                                  m�tt i millisekunder.
********************************************************************************/
void led_vector_blink_collectively(struct led_vector* self,
                                   const uint16_t blink_speed_ms)
{
	led_vector_on(self); // T�nder alla.
	delay_ms(blink_speed_ms);
	led_vector_off(self);
	delay_ms(blink_speed_ms);
	return;
}

/********************************************************************************
* led_vector_blink_sequentially: Genomf�r sekventiell blinkning av samtliga
*                                lysdioder lagrade i angiven vektor. D�rmed
*                                blinkar lysdioderna i en sekvens en efter en.
*
*                                - self          : Pekare till vektorn vars
*                                                  lysdioder ska blinkas.
*                                - blink_speed_ms: Lysdiodernas blinkhastighet
*                                                  m�tt i millisekunder.
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