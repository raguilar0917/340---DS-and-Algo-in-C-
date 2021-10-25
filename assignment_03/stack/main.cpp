#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

void removeNonLetters(string&);//prototype function to remove all the non-letters in a string

int main() {
  ArrayStack<char>* stackPtr = new ArrayStack<char>();
  string Str, rStr, originalStr;

  cout<<"Please enter a string you want to check if it's a palindrome: ";
  getline(cin, Str);
  originalStr = Str;
  removeNonLetters(Str);
  cout<<Str<<endl;

  for(int i = 0; i < Str.length(); i++){
    stackPtr->push(Str[i]);
  }
  for(int i = 0; i < Str.length(); i++){
    rStr += stackPtr->peek();
    stackPtr->pop();
  }
  cout<<rStr<<endl;
  (Str == rStr)?(cout<<"''"<<originalStr<<"'' is a Palindrome"):(cout<<originalStr<<"is NOT a Palindrome");

}
void removeNonLetters(string& str){
    for(int i = 0; i < str.length(); i++){
        if(((str[i] < 'A') || (str[i] > 'Z')) && ((str[i] < 'a') || (str[i] > 'z'))){
            str.erase(i, 1);
            i--;
            
        }else{
            str[i] = tolower(str[i]);
        }
    }
}