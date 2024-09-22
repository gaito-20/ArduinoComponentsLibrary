#include "ArduinoUno.h"
#include "utils.h"

int main() {
    ArduinoUno* arduino = ArduinoUno::getInstance();

    arduino->setOutput(PD, 2);
    arduino->setInput(PD, 3);
    arduino->setInput(PD, 4);

    while (true) {
        if (arduino->getPin(PD, 3) == Value::LOW) {
            arduino->setPin(PD, 2, Value::HIGH);
        }
        if (arduino->getPin(PD, 4) == Value::LOW) {
            arduino->setPin(PD, 2, Value::LOW);
        }
        delay(100);
    }
}