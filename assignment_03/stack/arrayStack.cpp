#include "arrayStack.h"
#include <iostream>
#include <cassert>
using namespace std;

template<class ItemType>
arrayStack<ItemType>::arrayStack() : top(-1){

}
template<class ItemType>
bool arrayStack<ItemType>::pop(){
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    } // end if
    return result;
}

template<class ItemType>
bool arrayStack<ItemType>::isEmpty() const{
    return top<0;
}

template<class ItemType>
bool arrayStack<ItemType>::push(const ItemType& newEntry){
    bool flag = false;
    if(top < DEFAULT_SIZE-1){
        top++;
        items[top]=newEntry;
        flag=true;
    }
    return flag;
}


template<class ItemType>
ItemType arrayStack<ItemType>::peek() const{
    assert(!isEmpty());

    return items[top];
}