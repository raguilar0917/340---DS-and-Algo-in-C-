#include <iostream>

using namespace std;
void printArr(int [], int);
void LIS(int [], int);

int main(){
    int SIZE = 10;
    int sequence[10];

    cout<<"Please think of 10 integers for the program and enter them one at a time."<<endl;
    for(int i = 0; i < SIZE; i++){
        cout<<i+1<<": ";
        cin>>sequence[i];
    }
    cout<<"You entered: ";
    printArr(sequence, SIZE);
    cout<<" longest continously increasing subsequence in the inputed array is: ";
    LIS(sequence, SIZE);

    return 0;
}

void LIS(int arr[], int SIZE){
    // creates an array that holds the postion and number of elements in the subsequence
    // int result[2] = {position, counter}
    int result[2] = {0, 0};
    //counter to track how many numbers are continuosly larger
    int count = 1;
    
    for(int i = 0; i < SIZE; i++){
        
        //checks if current element is less the the next
        if(arr[i] < arr[i+1]){
            //if true the counter increases
            count++;
            
        }else{
            // if the condition in false then it checks whether the current counter is larger than recorded counter
            if(count > result[1]){
                //if the current counter is larger than the recorded values than the current values will replace the old ones
                result[0] = i - (count-1); // since the indx it began at is (i-(count-1)) away from count
                result[1] = count;// save the position
            }
            //resets the counter
            count = 1;
        }
    }

    /**
     * starts on the recorded element (result[0]) and increments the amount of counts (result[1])
     * and prints each element
     * */
    int indx = result[0];
    cout<<"[ ";
    for(int i  = 0; i < result[1]; i++){
        cout<<arr[indx]<<" ";
        indx++;
    }
    cout<<"]"<<endl;
}

void printArr(int arr[], int SIZE){
    cout<<"[";
    for(int i = 0; i < SIZE; i++){
        cout<<" "<<arr[i]<<" ";
    }
    cout<<" ]"<<endl;


}