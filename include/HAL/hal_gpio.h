#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <PAC/pac_gpio.h>

namespace IO {
    enum class PinMode {
        INPUT = 0,
        OUTPUT = 1
    };

    enum class PinValue {
        LOW = 0,
        HIGH = 1
    };

    class GPIO {
        gpio_t pin;
    public:
        explicit GPIO(gpio_t& pin) : pin(pin) {};

        void setMode(PinMode mode) {
            gpio_init(pin, static_cast<uint8_t>(mode));
        }

        void setValue(PinValue value) {
            gpio_set(pin, static_cast<uint8_t>(value));
        }

        PinValue getValue() {
            return static_cast<PinValue>(gpio_get(pin) != 0);
        }
    };
}

#endif //HAL_GPIO_H