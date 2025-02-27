#ifndef PAC_GPIO_H
#define PAC_GPIO_H

#include <avr/io.h>

#define clr_bit(reg, bit) reg &= ~(1 << bit)
#define set_bit(reg, bit) reg |= (1 << bit)
#define toggle_bit(reg, bit) reg ^= (1 << bit)

typedef struct {
    volatile uint8_t *port; // Data Register
    volatile uint8_t *ddr;  // Data Direction Register
    volatile uint8_t *pin;  // Input Pins
    uint8_t mask;
} gpio_t;

#define GPIO_ADDR(port, pin) {&PORT ## port, &DDR ## port, &PIN ## port, 1 << pin}

__attribute__((unused)) static gpio_t gpio0 = GPIO_ADDR(D, 0);
__attribute__((unused)) static gpio_t gpio1 = GPIO_ADDR(D, 1);
__attribute__((unused)) static gpio_t gpio2 = GPIO_ADDR(D, 2);
__attribute__((unused)) static gpio_t gpio3 = GPIO_ADDR(D, 3);
__attribute__((unused)) static gpio_t gpio4 = GPIO_ADDR(D, 4);
__attribute__((unused)) static gpio_t gpio5 = GPIO_ADDR(D, 5);
__attribute__((unused)) static gpio_t gpio6 = GPIO_ADDR(D, 6);
__attribute__((unused)) static gpio_t gpio7 = GPIO_ADDR(D, 7);

__attribute__((unused)) static gpio_t gpio8 = GPIO_ADDR(B, 0);
__attribute__((unused)) static gpio_t gpio9 = GPIO_ADDR(B, 1);
__attribute__((unused)) static gpio_t gpio10 = GPIO_ADDR(B, 2);
__attribute__((unused)) static gpio_t gpio11 = GPIO_ADDR(B, 3);
__attribute__((unused)) static gpio_t gpio12 = GPIO_ADDR(B, 4);
__attribute__((unused)) static gpio_t gpio13 = GPIO_ADDR(B, 5);

__attribute__((unused)) static gpio_t gpioA0 = GPIO_ADDR(C, 0);
__attribute__((unused)) static gpio_t gpioA1 = GPIO_ADDR(C, 1);
__attribute__((unused)) static gpio_t gpioA2 = GPIO_ADDR(C, 2);
__attribute__((unused)) static gpio_t gpioA3 = GPIO_ADDR(C, 3);
__attribute__((unused)) static gpio_t gpioA4 = GPIO_ADDR(C, 4);
__attribute__((unused)) static gpio_t gpioA5 = GPIO_ADDR(C, 5);

void gpio_init(gpio_t& gpio, uint8_t mode);
void gpio_set( gpio_t& gpio, uint8_t value);
uint8_t gpio_get(gpio_t& gpio);

#endif //PAC_GPIO_H