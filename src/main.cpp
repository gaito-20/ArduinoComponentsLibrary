#include <ArduinoUno.h>
#include <Key.h>
#include <LED.h>

int main() {
    ArduinoUno* arduino = ArduinoUno::getInstance();

    // arduino->addComponent(Key(PD3));
    // arduino->addComponent(LED(PD2));
    // arduino->addComponent(Key(PD4));

    auto key1 = new Key(arduino, PD, 3);
    auto key2 = new Key(arduino, PD, 4);
    auto led = new LED(arduino, PD, 2);

    key1->addSubscriber(led);
    key2->addSubscriber(led);

    while (true) {
        if (arduino->getPin(PD, 3) == Value::LOW) {
            key1->pressed();
        }
        if (arduino->getPin(PD, 4) == Value::LOW) {
            key2->pressed();
        }

        // if (arduino->getPin(PD, 3) == Value::LOW) {
        //     arduino->setPin(PD, 2, Value::HIGH);
        // }
        // if (arduino->getPin(PD, 4) == Value::LOW) {
        //     arduino->setPin(PD, 2, Value::LOW);
        // }
        delay(100);
    }
}
