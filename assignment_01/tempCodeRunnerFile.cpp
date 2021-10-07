#include <iostream>
using namespace std;

void cal(int arr[], int length) {
    for (int i=0; i<length; i++)
        arr[i] *= 2;
}

int main(){
    int x = 4;
    double y = x;
    cout<<y;
}