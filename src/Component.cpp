#include "Component.h"

void Component::notify() const {
    auto subscriber = subscribers.getItem();
    auto next = subscribers.getNext();

    while (subscriber != nullptr) {
        subscriber->update();
        if (next == nullptr) { break; }
        subscriber = next->getItem();
        next = next->getNext();
    }
}

Component* Component::addSubscriber(Component *component) {
    subscribers.addItem(component);
    return this;
}
