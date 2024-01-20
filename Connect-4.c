#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>


// make_move(board , column , player) updates the board following a move
// by the given player in the given column; returns false if the move
// was illegal because the column was full
// requires: 0 <= column < 7
// player is either 'X' or 'O


bool make_move(char board[6][7] , int column , char player)
{
  while(board[0][column]==' ')
  {
  for(int i = 5;i>=0;i--)
  {
   if(board[i][column] == ' ')
   {
    board[i][column] = player;
	  break;
   }
  }
  printf("  0   1   2   3   4   5   6  \n");
  printf("|---|---|---|---|---|---|---|\n");
  for(int i=0;i<6;i++)
  {
  for(int j=0;j<7;j++)
  {
    printf("| %c ", board[i][j]);  //Extra space before %c 
  }
  printf("|\n");
  printf("|---|---|---|---|---|---|---|\n");
 }
 return true;
 break;
 }
 return false;
}


// check_win(board) returns true if the given player has 4 connected
// pieces on the board


bool check_win(char board[6][7] , char player)
{
 //Horizontal Wins
 for(int i=0;i<6;i++)
 {
  for(int j=0;j<4;j++)
  {
   int count = 0;
   for(int k=0;k<4;k++)
   {
    if(board[i][j+k]==player)
	count++;
   }
   if(count==4)
   {
   return 1;
   }
  }
 }
 
 //Vertical Wins
 for(int i=0;i<7;i++)
 {
  for(int j=0;j<3;j++)
  {
   int count = 0;
   for(int k=0;k<4;k++)
   {
    if(board[j+k][i]==player)
	count++;
   }
   if(count==4)
   {
   return 1;
   }
  }
 }
 
 //right diagonal Win
 for(int i=3;i<7;i++)
 {
  for(int j=0;j<6;j++)
  {
   if(board[i][j]==player && board[i-1][j+1]==player && board[i-2][j+2]==player && board[i-3][j+3]==player)
   {
    return 1;
   }
  }
 }
 
  //Left diagonal Win
 for(int i=3;i<7;i++)
 {
  for(int j=3;j<6;j++)
  {
   if(board[i][j]==player && board[i-1][j-1]==player && board[i-2][j-2]==player && board[i-3][j-3]==player)
   {
    return 1;
   }
  }
 }
  return 0;
}
 
 

int main(void)
{
 int rows = 6;
 int column = 7;
 char stage[6][7] = {};
 int m,n;
 char p1 = 'X', p2 = 'O';
 int turn=0;
 int result;
 
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<column;j++)
  {
    stage[i][j] = ' ';
  }
 }
 
 //Printing stage
 
 printf("  0   1   2   3   4   5   6  \n");
 printf("|---|---|---|---|---|---|---|\n");
 for(int i=0;i<rows;i++)
 {
  for(int j=0;j<column;j++)
  {
    printf("| %c ", stage[i][j]);  //Extra space before %c 
  }
  printf("|\n");
  printf("|---|---|---|---|---|---|---|\n");
 }
 
 while(turn<=42)
 {
 printf("Player 1!! Please choose the column you would like to put the piece:\n");
 scanf("%d",&m);
 
 while(m<0 || m>6)
 {
  printf("Invalid try again!!\n");
  scanf(" %d",&m);
 }
 
 while(make_move(stage,m,p1)==false)
 {
  printf("column is full! Try again:\n");
  scanf("%d",&m);
 }
 turn++; 
 result = check_win(stage,p1);
 if(result==true)
 {
  printf("Player 1 wins!!\n");
  turn = 43;
 }
 
 
 printf("Player 2!! Please choose the column you would like to put the piece:\n");
 scanf("%d",&n);
 
 while(n<0 || n>6)
 {
  printf("Invalid try again!!\n");
  scanf("%d",&n);
 }
 
 while(make_move(stage,n,p2)==false)
 {
  printf("column is full! Try again:\n");
  scanf("%d",&n);
 }
 turn++; 
 if(check_win(stage,p2)==true)
 {
  printf("Player 2 wins!!\n");
  turn=43;
 }
}
 
 return 0;
}
