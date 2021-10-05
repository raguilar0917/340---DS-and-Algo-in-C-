// Copyright 2021 - Richard Aguilar
// Email: raguilar10@sfsu.edu
// This file is part of CSC 340 - Assignment <1>
/**
 * The following code ask for a 5 digit input and is checked  if it is a 5 digit integer
 * if it isn't you are asked for a new input. Once you enter the correct input the cout
 * seperates each digit individually.
 * 
**/
#include <iostream>
using namespace std;

int main(){
    int input;
    cout<<"Please enter a 5 digit integer: ";
    do{
        cin>>input;
        if(input > 100000 || input < 10000){
            cout<<"Error, Please enter a 5 digit integer: ";
        }
    }while(input > 100000 || input < 10000);

    //TODO: I'm sure this can be improved upon by using a for loop so it can be easily scalable for larger or smaller inputs.
    cout<<(input/10000)%10<<" "<<(input/1000)%10<<" "<<(input/100)%10<<" "<<(input/10)%10<<" "<<(input)%10<<endl;

    return 0;
}