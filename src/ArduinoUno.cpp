#include "ArduinoUno.h"
#include <avr/io.h>

ArduinoUno::ArduinoUno() { init(); };
ArduinoUno* ArduinoUno::arduinoUno = nullptr;

ArduinoUno *ArduinoUno::getInstance() {
    if (arduinoUno == nullptr) {
        arduinoUno = new ArduinoUno();
    }
    return arduinoUno;
}

void ArduinoUno::init() const {
    uint8_t ddrb = 0x00;
    uint8_t ddrc = 0x00;
    uint8_t ddrd = 0x00;
    uint8_t portb = 0x00;
    uint8_t portc = 0x00;
    uint8_t portd = 0x00;

    for (int i = 0; i < 8; i++) {
        if (ports[PB].pin[i].getMode() == Mode::OUTPUT) {
            ddrb |= (1 << i);
        } else {
            portb |= (1 << i);
        }
        if (ports[PC].pin[i].getMode() == Mode::OUTPUT) {
            ddrc |= (1 << i);
        } else {
            portc |= (1 << i);
        }
        if (ports[PD].pin[i].getMode() == Mode::OUTPUT) {
            ddrd |= (1 << i);
        } else {
            portd |= (1 << i);
        }
    }

    DDRB = ddrb;
    DDRC = ddrc;
    DDRD = ddrd;
    PORTB = portb;
    PORTC = portc;
    PORTD = portd;
}

void ArduinoUno::update() const {
    for (int i = 0; i < 8; i++) {
        if (ports[PB].pin[i].getMode() == Mode::OUTPUT) {
            if (ports[PB].pin[i].getValue() == Value::HIGH) {
                PORTB |= (1 << i);
            } else {
                PORTB &= ~(1 << i);
            }
        }

        if (ports[PC].pin[i].getMode() == Mode::OUTPUT) {
            if (ports[PC].pin[i].getValue() == Value::HIGH) {
                PORTC |= (1 << i);
            } else {
                PORTC &= ~(1 << i);
            }
        }

        if (ports[PD].pin[i].getMode() == Mode::OUTPUT) {
            if (ports[PD].pin[i].getValue() == Value::HIGH) {
                PORTD |= (1 << i);
            } else {
                PORTD &= ~(1 << i);
            }
        }
    }
}

void ArduinoUno::setOutput(int port, int pin) {
    ports[port].pin[pin].setMode(Mode::OUTPUT);
    init();
}

void ArduinoUno::setInput(int port, int pin) {
    ports[port].pin[pin].setMode(Mode::INPUT);
    init();
};

void ArduinoUno::turnOnLED() {
    ports[PB].pin[5].setValue(Value::HIGH);
    update();
}

void ArduinoUno::turnOffLED() {
    ports[PB].pin[5].setValue(Value::LOW);
    update();
}

void ArduinoUno::setPin(int port, int pin, Value value) {
    ports[port].pin[pin].setValue(value);
    update();
}

Value ArduinoUno::getPin(int port, int pin) {
    switch (port) {
        case PB:
            return ports[port].pin[pin].setValue(static_cast<Value>((PINB & (1 << pin))));
        case PC:
            return ports[port].pin[pin].setValue(static_cast<Value>((PINC & (1 << pin))));
        case PD:
            return ports[port].pin[pin].setValue(static_cast<Value>((PIND & (1 << pin))));
        default: return Value::LOW;
    }

}

void ArduinoUno::addComponent(Component *component) {
    components.addItem(component);
}
