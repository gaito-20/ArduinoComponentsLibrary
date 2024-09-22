#ifndef LED_H
#define LED_H

#include <ArduinoUno.h>
#include <Component.h>

class LED : public Component {
    int port;
    int pin;
public:
    LED(ArduinoUno* board, int port, int pin) : Component(board), port(port), pin(pin) {
        board->addComponent(this);
        board->setOutput(port, pin);
    };

    void turnOn() const {
        board->setPin(port, pin, Value::HIGH);
    }

    void turnOff() const {
        board->setPin(port, pin, Value::LOW);
    }

    void toggle() const {
        board->setPin(port, pin, board->getPin(port, pin) == Value::LOW ? Value::HIGH : Value::LOW);
    }

    void update() override {
        toggle();
    };

};

#endif //LED_H
