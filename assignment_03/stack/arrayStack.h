#ifndef _ARRAY_STACK
#define _ARRAY_STACK
#include "StackInterface.h"
const int DEFAULT_SIZE = 6;
template< class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
    private:
    int capacity;
    ItemType* items; // Array of stack items
    int top; 
    public:
    ArrayStack(); // Default constructor
    bool isEmpty() const;
    bool push( const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
    int sizeOfStack();
}; // end ArrayStack
#include "ArrayStack.cpp"
#endif