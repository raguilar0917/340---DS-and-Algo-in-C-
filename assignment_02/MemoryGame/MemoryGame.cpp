#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
//above this is the code from given file


#include <sstream>
#include<chrono>
#include<thread>
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <iomanip>

#define cls() std::cout <<"\033[2J\033[1;1H";
using namespace std; 

string words[] = {"apple", "avocado", "apricot",
"banana", "blackberry", "blueberry", "boysenberry",
"cherry", "cantaloupe", "cranberry", "coconut", "cucumber", "currant",
"date", "durian", "dragonfruit",
"elderberry",
"fig",
"grapefruit", "guava", "grape",
"honeydew", "honeyberry",
"jackfruit",
"kiwi", "kumquat",
"lemon", "lime", "lychee", "longan",
"mango", "mangosteen", "mandarin",
"nectarine",
"orange", "olive",
"pineapple", "papaya", "plum", "passion-fruit", "peach", "pear",
   "persimmon", "prune", "pummelo", "pomegranate", "pluot", "plantain",
"raspberry", "rose-apple", "rambutan",
"strawberry", "star-fruit", "sapote", "soursop", "sugar-apple", "star-apple",
"tangerine", "tomato", "tamarind",
"watermelon"};


//prototypes for functions
bool checkWord(string, string [], int); //checks if a word is used alreadyy
string getWord(const string []);//gets a random word
void gameScreen(string);//prints the gamescreen
string generateWords(const string [], string [], int);//generates the string of random words
void printArr(string [], int);//prints array for debugging 
void checkAnswer(string [], string [], int, int &);//checks if the answer is correct
void breakApart(string [], string);//gets each individual word the user inputed omitting space


int main(){
    //the flag is the answer of the user on whether they want to play
    //thee flag is to prevent getline from being skipped
    char flag,flip = 0;
    //prompt
    cout<<"----------------------------------------------"<<endl;
    cout<<"Hello, welcome to my adaptive memory game\n"
        <<"You will be presented with a few words.\n"
        <<"You have a second to memorize those.\n"
        <<"Then you will be prompted to enter the words.\n"
        <<"For every word you enter correctly, you'll get 1 point.\n"
        <<"Otherwise, you'll be deducted 1 point."
        <<"If the number of words you enter doesn't match\n"
        <<"the number of challenged words, you'll be deducted 1 point.\n";
        cout<<"----------------------------------------------"<<endl;
    cout<<"Ready to begin (Y/N)?: ";
    cin>>flag;
    //if the flag says n then the program ends
    if(flag == 'n'){
         exit(0); 
    }else{
        //this block prepares for the user to play the game
        cls();
        cout<<"Get ready..."<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    //initialize the random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //userinput gets the string the user inputs
    //answerkey holds the string that will be printed to users
    string userInput, answerKey;
    //the key and input arrays hold the correct answer and the user answer
    //the reason why the array is 6 is because thats the total possible words that a user can get
    string key[6], input[6];
    int score = 20;
    int wordCount = 2;
    //do while loop runs the game until condition met
    do{

        //the string anserkey holds the string that will show the words to the user and then gameScreen prints it
        answerKey = generateWords(words, key, wordCount);
        gameScreen(answerKey);
        //wait 1 second and clear screen
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cls();
        
        //i put this hear because the getline wouldn't be called because of a buffer problem
        //the if block only works on the first loop
        if(flip==0){
            flip++;
           cin.ignore(1000, '\n');
        }
        //prompt and getLine function to get the whole user input
        cout<<"Please enter your answer: ";
         getline(cin, userInput);
        //if the input is q exit the game
        if(userInput == "q"){ break; }

        //calls break apart to put answers in a array and then to check them compared to the key
        breakApart(input, userInput);
        checkAnswer(key, input, wordCount, score);
        
        //for every 5 points the game difficulty increses
        if(score%5==0 && score > 0){ wordCount++; }

    }while(score != 21);

    //clears the screen and presents final score
    cls();

    if(score == 21){
        cout<<"EXCELLENT: YOU WIN!!"<<endl;
        cout<<"Thanks for playing!......"<<endl;
        cout<<"Your final score is......."<<score<<endl;
        cout<<"Bye...."<<endl;

    }else{
        cout<<"You left the game!!"<<endl;
        cout<<"Thanks for playing!......"<<endl;
        cout<<"Your final score is......."<<score<<endl;
        cout<<"Bye...."<<endl;
    }

}
/**
 * 
 * gets the list of words and chooses a random word. it then checks if the word is already used.
 * if so it will choose a different word. each time a word is chose it is concatinated to a string and added
 * to the anser key
 * 
 * */
string generateWords(const string words[], string key[], int wordCount){
    string prompt = "";

    for(int i = 0; i < wordCount; i++){
        
        do{
            key[i] = getWord(words);
            //cout<<i<<endl;

        }while(!checkWord(key[i], key, i));
        
        prompt.append(key[i]);
        if(i < wordCount){prompt.append(" ");}
    }

    return prompt;
}

/**
 * this function breaks apart the string that user inputs and gets each individual word splitting by every " " int the string
 * then it adds it to the user input array
 * */
void breakApart(string input[], string userInput){
    istringstream my_string(userInput);
    int indx = 0;
    while (my_string >> input[indx]){
        indx++;
        cout<<indx<<endl;
    }
}

/**
 * this is a helper function for the generate function
 * it will check if the word is already in the array
 * */
bool checkWord(string word, string key[], int SIZE){
    for(int i = 0; i < SIZE; i++){
        if(word == key[i]){
            return true;
        }
    }
    return true;
}

//this prints the game screen and takes the generated string as input
void gameScreen(string words){
    cout<<"*************************************\n"
    <<setw(29)<<"Memorize the following"<<"\n"
    <<"*************************************\n\n\n"
    <<setw(5)<<words<<"\n\n\n"
    <<"*************************************"
    <<endl;
}

//gets a randomized word out of the 61 given words
string getWord(const string words[]){
    int num = rand()%61;
    string a = words[num];
    return a;
}

//debug function to check whats in each array
void printArr(string arr[], int SIZE){
    cout<<"[";
    for(int i = 0; i < SIZE; i++){
        cout<<" "<<arr[i]<<" ";
    }
    cout<<" ]"<<endl;


}
//checks if there is an incorrect answer and adjusted a refrence to the score respectivley
void checkAnswer(string key[], string input[], int wordCount, int &score){
    bool flag = false;
    for(int i = 0; i < wordCount; i++){
        if(key[i] != input[i]){
            flag = true;
        }
    }
    if(flag){
        score-=1;
        cout<<"Checking your input .....\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"incorrect Answer\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"Your current score: "<<score<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"Ready ....."<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }else{
        score+=1;
        cout<<"Checking your input .....\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"Correct Answer\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"Your current score: "<<score<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"Ready ....."<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}