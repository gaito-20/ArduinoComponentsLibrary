#ifndef HARDWARE_H
#define HARDWARE_H

enum class Mode {
    INPUT,
    OUTPUT
};

enum class Value {
    LOW,
    HIGH
};

struct Pin {
private:
    Mode mode;
    Value value;
public:
    Pin() {
        mode = Mode::OUTPUT;
        value = Value::LOW;
    }

    Mode setMode(const Mode mode) {
        return this->mode = mode;
    }
    Mode getMode() const {
        return mode;
    }

    Value setValue(const Value value) {
        return this->value = value;
    }
    Value getValue() const {
        return value;
    }
};

struct Port {
    Pin pin[8];
};

#endif //HARDWARE_H
