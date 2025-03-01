#include "PAC/pac_gpio.h"
#include <util/delay.h>
#include <unity.h>

void setUp(void)
{
    gpio_init(gpio13, 1);
}

void tearDown(void)
{
    gpio_init(gpio13, 0);
}

void test_blink(void)
{
    gpio_set(gpio13, 1);
    _delay_ms(100);

    TEST_ASSERT_TRUE(gpio_get(gpio13));

    gpio_set(gpio13, 0);
    _delay_ms(100);

    TEST_ASSERT_FALSE(gpio_get(gpio13));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_blink);
    return UNITY_END();
}