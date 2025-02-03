#include <stdio.h>
#include "pico/stdlib.h"
#include "U4C5-T2.h"

int led = 0;
static alarm_id_t debounce_alm;
struct repeating_timer timer;

void init_gpio() {
    uint ledMask = (0x01 << LED_VERMELHO) | (0x01 << LED_AMARELO) | (0x01 << LED_VERDE);
    gpio_init_mask(ledMask);
    gpio_set_dir_out_masked(ledMask);

    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);

    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true, &debounce);
}

uint64_t inicia_ciclo(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERMELHO, true);
    gpio_put(LED_AMARELO, true);
    gpio_put(LED_VERDE, true);
 
    led = 3;
    add_repeating_timer_ms(3000, repeat_callback, NULL, &timer);
}

static void debounce(uint gpio, uint32_t events) {
    cancel_alarm(debounce_alm);
    if(gpio == BOTAO_A && events == 0x04 && led == 0){
        debounce_alm = add_alarm_in_ms(DEBOUNCE_MS, inicia_ciclo, NULL, false);
    }
}

bool repeat_callback(struct repeating_timer *t) {   
    if(led == 3) gpio_put(LED_VERMELHO, false);
    if(led == 2) gpio_put(LED_AMARELO, false);
    if(led == 1) gpio_put(LED_VERDE, false);

    led--;
    if(led == 0) cancel_repeating_timer(&timer);
}

int main() {
    stdio_init_all();

    init_gpio();

    while (true) {

        uint32_t start_ms = to_ms_since_boot(get_absolute_time());
        printf("Tempo absoluto: %d\n", start_ms);

        sleep_ms(1000);
    }
}
