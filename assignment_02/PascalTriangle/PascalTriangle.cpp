#include <iostream>
using namespace std;
//pascal function that takes one input
void pascalTri(int);
//helper function that does combination formula n!/k!(n-k)!
int combination(int, int);

int main(){
    //user input that goes through a checker for proper input if invalid input it asks to give a new valid input
  int userInput;
  do{

    cout<<"Please enter a number that is less than 0 < X < 10: ";
    cin>>userInput;

    if(userInput > 10 || userInput <= 0){ cout<<"ERROR: INVALID INPUT!"<<endl;}

  }while(userInput > 10 || userInput <= 0);

  //calls pascal
  pascalTri(userInput);

  return 0;
}

//this the math for combination of each element in each line
int combination(int n, int k){
    int result = 1;

    if(k > (n-k))
        k = n-k;
    
    for(int i = 0; i < k; i++){
        result *= (n-i);
        result /= (i+1);

    }

    return result;
}

void pascalTri(int n){

    /**
     * the first loop represents the line of the pascal triangle
     * the nested loop represent each element in that line
     * it then prints out he element
     **/
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout<<combination(i, j)<<" ";
        }
        cout<<endl;
    }
 
}
