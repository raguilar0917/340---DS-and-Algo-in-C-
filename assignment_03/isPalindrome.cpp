#include <iostream>
#include <string>

using namespace std;
void removeNonLetters(string&);
bool isPalindrome(string, int , int);

int main(){
    string input;
    cout<<"Please enter a string to check if it's a palindrome: ";
    getline(cin, input);

    string str = input;
    removeNonLetters(str);
    cout<<str<<endl;
    (isPalindrome(str, 0, str.length()-1))?cout<<"''"<<input <<"'' is a palindrome"<<endl : cout<<input <<"'' is not a palindrome"<<endl;
}
bool isPalindrome(string str, int begin, int end){
    cout<<"Begin: "<<begin<<endl;
    cout<<"End: "<<end<<endl;

    if(begin == end){
        cout<<"enter"<<endl;
        return true;
    }

    if(begin == str.length()-1 && end == 0){
        return true;
    }

    if(str[0] != str[str.length()-1]){
        return false;
    }
    if(str[begin] == str[end]){
        cout<<str[begin]<<" == "<<str[end]<<endl;
        return isPalindrome(str, begin+1, end-1);
    }else{
        cout<<str[begin]<<" != "<<str[end]<<endl;
        return false;
    }

    
    


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