#include <iostream>
#include "StackInterface.h"
#include "arrayStack.h"
using namespace std;

int main(){
    StackInterface<string>* stackPtr = new arrayStack<string>();
    stackPtr->push("1 2 3");
    //s.push(2);
    return 0;
}