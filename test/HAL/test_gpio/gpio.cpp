#include "HAL/hal_gpio.h"
#include <util/delay.h>
#include <unity.h>

IO::GPIO led{gpio13};

void setUp(void)
{
    led.setMode(IO::PinMode::OUTPUT);
}

void tearDown(void)
{
    led.setMode(IO::PinMode::INPUT);
}

void test_blink(void)
{
    led.setValue(IO::PinValue::HIGH);
    _delay_ms(100);

    TEST_ASSERT_EQUAL(IO::PinValue::HIGH, led.getValue());

    led.setValue(IO::PinValue::LOW);
    _delay_ms(100);

    TEST_ASSERT_EQUAL(IO::PinValue::LOW, led.getValue());
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_blink);
    return UNITY_END();
}