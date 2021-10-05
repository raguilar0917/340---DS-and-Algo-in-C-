#include "TicTacToe.h"

using namespace std;


void TicTacToe::makeMove() {
   printBoard();

   while (true) {
      if (xoMove('X')) {
         break;
      }
      else if (xoMove('O')) {
         break;
      }
   } 
} 
