#include <iostream>
#include <sstream>


using namespace std;


int maxNumOfToys(int [], int, int); //Function to solve problem
void splitPrices(int [], string); //Helper function to split the prices received from getliine()

void bubbleSort(int [], int); //bubblesort to help with solution
void swap(int*, int*);//swap to help bubblesort

int main(){
    int toyCount, balance, numOfToys;
    string toyPricesLine;

    cout<<"Enter the dollar amount Mark can spend: ";
    cin>>balance;//saves the money person can spend

    cout<<"Enter the number of items: ";
    cin>>numOfToys;//gets the number of toys an makes an array from that
    const int SIZE = numOfToys;

    int toyPrices[SIZE];

    cout<<"Enter the toy prices: ";
    cin.ignore();//cin ignore because it kept skipping over the getline()
    getline(cin, toyPricesLine);

    splitPrices(toyPrices, toyPricesLine);
    bubbleSort(toyPrices, SIZE);


    cout<<"Maximum number of items Mark can buy: "<<maxNumOfToys(toyPrices, SIZE, balance)<<endl;

}

int maxNumOfToys(int toyPrices[], int SIZE, int balance){

    /**
     * the logic behind it is that it sorts the prices and then adds each toy to
     *  spend until it exceeeds the balance and the returns the amount of toys it purchased
     * 
     */


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
    //splits prices using sstream
    stringstream ss(toyPricesLine);
    string word;
    int i = 0;
    while(ss>>word){
        toyPrices[i] = stoi(word);
        i++;
    }
}

void swap(int* valA, int* valB){
    //swap
    int temp = *valA;
    *valA = *valB;
    *valB = temp;
}
void bubbleSort(int toyPrices[], int SIZE){
    //standard bubble sort
    for(int i = 0; i < SIZE-1; i++){
        for(int j = 0; j < SIZE-i-1; j++){
            if(toyPrices[j] >  toyPrices[j+1]){
                swap(&toyPrices[j], &toyPrices[j+1]);
            }
        }
    }
}