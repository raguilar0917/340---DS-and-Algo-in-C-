#include <cassert> // For assert
#include <iostream>
using namespace std;
#include "ArrayStack.h" // Header file
template< class ItemType>
ArrayStack<ItemType>::ArrayStack(){
    top = -1;
    capacity = DEFAULT_SIZE;
    items = new ItemType[capacity];
} // end default constructor
// Copy constructor and destructor are supplied by the compiler
template< class ItemType>
bool ArrayStack<ItemType>::isEmpty() const{
    return top < 0;
} // end isEmpty

template< class ItemType>
bool ArrayStack<ItemType>::push( const ItemType& newEntry){
    //cout<<"data\nItem Entered: " << newEntry <<"\nTop: "<< top << "\nCapacity: " << capacity << endl << endl;
    bool flag = false;
    if(top == capacity-1){
        //cout<<"top greater"<<endl;
        capacity *= 2;
        items = new ItemType[capacity];
        top++;
        items[top]= newEntry;
        flag = true;
    }

    if(top < capacity-1){
        //cout<<"top lesser"<<endl;
        top++;
        items[top] = newEntry;
        flag = true;
    }
    return flag;
} // end push
template< class ItemType>
bool ArrayStack<ItemType>::pop()
{
bool result = false;
 if (!isEmpty())
 {
 top--;
 result = true;
 } // end if
return result;
} // end pop
template< class ItemType>
ItemType ArrayStack<ItemType>::peek() const{
    assert (!isEmpty()); // Enforce precondition
    // Stack is not empty; return top
    return items[top];
}

template <class ItemType>
int ArrayStack<ItemType>::sizeOfStack(){
    return top+1;
}