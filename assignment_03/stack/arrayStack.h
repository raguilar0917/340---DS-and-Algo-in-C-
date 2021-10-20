#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "StackInterface.h"

template <class ItemType>
class arrayStack : public StackInterface<ItemType>{
    private:
        int DEFAULT_SIZE = 6;
        int top;
        ItemType *items = new ItemType[DEFAULT_SIZE];

    public:
        arrayStack();
        bool pop();
        bool push(const ItemType& newEntry);
        bool isEmpty() const;
        ItemType peek() const;

};
#endif