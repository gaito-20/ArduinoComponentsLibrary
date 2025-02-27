#ifndef UTILS_H
#define UTILS_H

#include <util/delay.h>

inline void delay(int ms) {
    for (int i = 0; i < ms; i++) {
        _delay_ms(1);
    }
}

template<class T>
class List {
private:
    T* item;
    List* next = nullptr;
public:
    List() : item(nullptr) {};
    explicit List(T* item) : item(item) {};

    void addItem(T* item_);
    int size() const;

    T* getItem() const { return item; };
    List* getNext() const { return next; };
};

template<class T>
void List<T>::addItem(T* item_) {
    if (item == nullptr) {
        item = item_;
        return;
    }
    if (next != nullptr) {
        next->addItem(item_);
    }
    next = new List(item_);
}

template<class T>
int List<T>::size() const {
    int size = 0;
    for (List* item = this->next; item != nullptr; item = item->next) {
        size++;
    }
    return size;
}

#endif //UTILS_H
