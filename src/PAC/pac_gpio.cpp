#include "PAC/pac_gpio.h"

void gpio_init(gpio_t& gpio, uint8_t mode)
{
    *gpio.ddr = mode ? (uint8_t)(*gpio.ddr | gpio.mask) : (uint8_t)(*gpio.ddr & ~gpio.mask);
}

void gpio_set(gpio_t& gpio, uint8_t value)
{
    *gpio.port = value ? (uint8_t)(*gpio.port | gpio.mask) : (uint8_t)(*gpio.port & ~gpio.mask);
}

uint8_t gpio_get(gpio_t& gpio)
{
    return (uint8_t)(*gpio.pin & gpio.mask);
}