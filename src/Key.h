#ifndef KEY_H
#define KEY_H

#include <ArduinoUno.h>
#include <Component.h>


class ArduinoUno;

class Key : public Component {
    int port;
    int pin;
public:
    Key(ArduinoUno* board, int port, int pin) : Component(board), port(port), pin(pin) {
        board->addComponent(this);
        board->setInput(port, pin);
    };

    void pressed() const {
        notify();
    }
};



#endif //KEY_H
