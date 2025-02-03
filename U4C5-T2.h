#ifndef __U4C5_T2_H_
#define __U4C5_T2_H_

#define LED_VERMELHO    11
#define LED_AMARELO   12
#define LED_VERDE       13

#define BOTAO_A         5

#define DEBOUNCE_MS     100

void init_gpio();
uint64_t inicia_ciclo(alarm_id_t id, void *user_data);
static void debounce(uint gpio, uint32_t events);
bool repeat_callback(struct repeating_timer *t); 

#endif