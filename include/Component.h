#ifndef COMPONENT_H
#define COMPONENT_H

#include <utils.h>


class ArduinoUno;

class Component {
protected:
    ArduinoUno* board;
    List<Component> subscribers;
public:
    explicit Component(ArduinoUno* board) : board(board) {};
    virtual ~Component() = default;
    void notify() const;
    virtual void update() {};

    Component* addSubscriber(Component* component);
};

#endif //COMPONENT_H
