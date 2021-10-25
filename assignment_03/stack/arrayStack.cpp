#include <cassert> // For assert
#include <iostream>
#include "ArrayStack.h" // Header file
template< class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1){
    CURRENT_MAX = DEFAULT_MAX;
    items = new ItemType[CURRENT_MAX];
}

// Copy constructor and destructor are supplied by the compiler
template< class ItemType>
bool ArrayStack<ItemType>::isEmpty() const{
return top < 0;
} // end isEmptY

template< class ItemType>
bool ArrayStack<ItemType>::push( const ItemType& newEntry){
    bool flag = false;
    if(top == CURRENT_MAX-1){
        flag = true;
        CURRENT_MAX *= 2;
        ItemType* tempItem = new ItemType[CURRENT_MAX];
        
        for(int i = 0; i < top+1; i++){
            tempItem[i] = items[i];
        }

        delete [] items;
        items = tempItem;
    }
    top++;
    items[top] = newEntry;
    return flag;
} // end push
template< class ItemType>
bool ArrayStack<ItemType>::pop(){
    bool result = false;
    if (!isEmpty()){
        top--;
        result = true;
    } // end if
    return result;
} // end pop
template< class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
 assert (!isEmpty()); // Enforce precondition
 // Stack is not empty; return top
return items[top];
}

template <class ItemType>
void ArrayStack<ItemType>::printStack(){
    std::cout<<"[ ";
    for(int i = 0; i < top; i++){
        std::cout<<items[i]<<" ";
    }
    std::cout<<" ]";
}