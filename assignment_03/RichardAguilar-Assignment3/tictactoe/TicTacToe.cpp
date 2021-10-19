#include "TicTacToe.h"
#include <iostream>
#include <iomanip>

using namespace std;
//nested loop that initializes each index
TicTacToe::TicTacToe(){
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
         board[i][j] = '_';
      }
   }
}
//makes a move based on what xoMove returns
void TicTacToe::makeMove() {
   while (true) {
      if (xoMove('X')) {
         break;
      }
      else if (xoMove('O')) {
         break;
      }
   } 
} 

//prints the board
void TicTacToe::printBoard() const{
   cout<<"   0  1  2"<<endl;
   for(int i = 0; i < 3; i++){
      cout<<i<<"  ";
      for(int j = 0; j < 3; j++){
         cout<<board[i][j]<<"  ";
      }
      cout<<endl;
   }

}

//checks if input is valid
bool TicTacToe::validMove(int posX, int posY) const{
   if(board[posX][posY] == '_'){
      return true;
   }else{
      return false;
   }
}
//runs game for the player and returns whether a game is won or not
bool TicTacToe::xoMove(char player){
   //prints board and asks for input
   printBoard();
   cout<<"Player "<<player<<" Turn!!"<<endl;
   int posX, posY;
   //checks for valid input and then puts it in variables
   do{
      cout<<"Please where you want to put your position(i.e: 1 2): ";
      cin >> posX >> posY;
      if(!validMove(posX, posY)){ cout<<"INVALID POSITION PLEASE REENTER POSITION!"<<endl;}
   }while(!validMove(posX, posY));
   board[posX][posY] = player;
   //if there is a winner the game ends and winner screen
   if(gameStatus() == WIN){
      printBoard();
      cout<<"Player "<< player <<" is the Winner!!"<<endl;
      return true;
   }

   //continyes
   return false;
}
TicTacToe::Status TicTacToe::gameStatus() const{

   //checks each row for a possible winner 
   //top-left too bottom-right
   if((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')){
      
      return WIN;
   }
   //top-right too bottom left
   else if((board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')){
      
      return WIN;
   }
   //row 1
   else if((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')){
      
      return WIN;;
   }
   //row 2
   else if((board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')){
      
      return WIN;
   }
   //row 3
   else if((board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')){
      
      return WIN;
   }
   //col 1
   else if((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')){
      
      return WIN;
   }
   //col 2
   else if((board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')){
      
      return WIN;
   }
   //col 3
   else if((board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')){
      
      return WIN;
   }
   else{
      return CONTINUE;
   }
}