#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;


int maxNumOfToys(int [], int, int);
void splitPrices(int [], string);

void bubbleSort(int [], int);
void swap(int*, int*);

int main(){
    int toyCount, balance, numOfToys;
    string toyPricesLine;

    cout<<"nter the dollar amount Mark can spend: ";
    cin>>balance;

    cout<<"Enter the number of items: ";
    cin>>numOfToys;
    const int SIZE = numOfToys;

    int toyPrices[SIZE];

    cout<<"Enter the toy prices: ";
    cin.ignore();
    getline(cin, toyPricesLine);

    splitPrices(toyPrices, toyPricesLine);
    bubbleSort(toyPrices, SIZE);


    cout<<"Maximum number of items Mark can buy: "<<maxNumOfToys(toyPrices, SIZE, balance)<<endl;

}

int maxNumOfToys(int toyPrices[], int SIZE, int balance){
    int toy_count = 0, spent = 0;

    for(int i = 0; i < SIZE; i++){
        if(spent + toyPrices[i] <= balance){
            spent += toyPrices[i];
            toy_count++;
        }else{

            break;
        }
    }
    return toy_count;
}
void splitPrices(int toyPrices[], string toyPricesLine){
    stringstream ss(toyPricesLine);
    string word;
    int i = 0;
    while(ss>>word){
        toyPrices[i] = stoi(word);
        i++;
    }
}

void swap(int* valA, int* valB){
    int temp = *valA;
    *valA = *valB;
    *valB = temp;
}
void bubbleSort(int toyPrices[], int SIZE){
    for(int i = 0; i < SIZE-1; i++){
        for(int j = 0; j < SIZE-i-1; j++){
            if(toyPrices[j] >  toyPrices[j+1]){
                swap(&toyPrices[j], &toyPrices[j+1]);
            }
        }
    }
}