#include <iostream>
#include <string>
#include "ArrayStack.h"
void removeNonLetters(string&);
bool isPalindrome(ArrayStack<char>* stackPtr, string str);
using namespace std;

int main() {
  bool flag = true;
  ArrayStack<char>* stackPtr = new ArrayStack<char>();

  string str = "A man, a plan, a canal: Panama";
  removeNonLetters(str);
  cout<<str<<endl;

  for(int i = 0; i < str.length(); i++){
    stackPtr->push(str[i]);
    cout<<stackPtr->sizeOfStack()<<": "<<stackPtr->peek()<<endl;
  }

  for(int i = 0; i < str.length(); i++){
    char a = stackPtr->peek();
    cout<<a;
    stackPtr->pop();
  }
  //cout<<isPalindrome(stackPtr, str)<<endl;

}
bool isPalindrome(ArrayStack<char>* stackPtr, string str){
  bool flag = true;
  int sizeOfStack = stackPtr->sizeOfStack();

  for(int i = 0; i < str.length(); i++){
    stackPtr->push(str[i]);
  }

  for(int i = 0; i < str.length(); i++){
    if(stackPtr->peek() == str[i]){
      cout<<stackPtr->peek()<<" == "<<str[i]<<endl;
      stackPtr->pop();
    }
    else{
      cout<<stackPtr->peek()<<" != "<<str[i]<<endl;

      flag = false;
      break;
    }
  }

  return flag;
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