#ifndef _ARRAY_STACK
#define _ARRAY_STACK
#include "StackInterface.h"
template< class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
    private:
        int CURRENT_MAX;
        int DEFAULT_MAX = 6;
        ItemType* items; // Array of stack items
        int top; 
    public:
        ArrayStack(); // Default constructor
        bool isEmpty() const;
        bool push( const ItemType& newEntry);
        bool pop();
        ItemType peek() const;
        void printStack();
}; // end ArrayStack
#include "ArrayStack.cpp"
#endif