#ifndef PIO_UNIT_TESTING

#include "HAL/hal_gpio.h"
#include <util/delay.h>


int main() {

    IO::GPIO led{gpio13};

    led.setMode(IO::PinMode::OUTPUT);

    while (1) {
        led.setValue(IO::PinValue::HIGH);
        _delay_ms(1000);
        led.setValue(IO::PinValue::LOW);
        _delay_ms(1000);
    }
}

#endif // PIO_UNIT_TESTING