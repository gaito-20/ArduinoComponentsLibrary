#ifndef ARDUINOUNO_H
#define ARDUINOUNO_H

#include <Component.h>
#include <Hardware.h>
#include <utils.h>

#define PB 0
#define PC 1
#define PD 2
#define ARDUINO_UNO_NUMBER_PORTS 3

class ArduinoUno {
private:
    Port ports[ARDUINO_UNO_NUMBER_PORTS];
    List<Component> components;

    ArduinoUno();
    static ArduinoUno* arduinoUno;

    /**
    * Initialization of the GPIO pins
    *
    * Default: output pins are turned off, input pins have internal pull-up resistors enabled
    */
    void init() const;
public:
    ArduinoUno(ArduinoUno& other) = delete;
    void operator=(const ArduinoUno& other) = delete;
    ~ArduinoUno() { delete arduinoUno; };
    static ArduinoUno* getInstance();
    void update() const;

    void setOutput(int port, int pin);
    void setInput(int port, int pin);

    void turnOnLED();
    void turnOffLED();

    void setPin(int port, int pin, Value value);
    Value getPin(int port, int pin);

    void addComponent(Component* component);
};


#endif //ARDUINOUNO_H
