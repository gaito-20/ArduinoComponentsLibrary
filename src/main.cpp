#include "PAC/gpio.h"
#include <util/delay.h>

int main() {
    gpio_init(gpio13, 1);

    while (1) {
        gpio_set(gpio13, 1);
        _delay_ms(1000);
        gpio_set(gpio13, 0);
        _delay_ms(1000);
    }
}
