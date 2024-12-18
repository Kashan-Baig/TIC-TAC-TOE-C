#include <stdio.h>
#include <conio.h>
#include<windows.h>

#ifndef TC_H
#define TC_H

// #include <stdio.h>
// #include <sys/ioctl.h>
// // #include <termios.h>
// #include <unistd.h>

#define TC_NRM  "\x1B[0m"
#define TC_RED  "\x1B[1;31m"
#define TC_GRN  "\x1B[1;32m"
#define TC_YEL  "\x1B[1;33m"
#define TC_BLU  "\x1B[1;34m"
#define TC_MAG  "\x1B[1;35m"
#define TC_CYN  "\x1B[1;36m"
#define TC_WHT  "\x1B[1;37m"

#define TC_B_NRM  "\x1B[0m"
#define TC_B_RED  "\x1B[0;31m"
#define TC_B_GRN  "\x1B[0;32m"
#define TC_B_YEL  "\x1B[0;33m"
#define TC_B_BLU  "\x1B[0;34m"
#define TC_B_MAG  "\x1B[0;35m"
#define TC_B_CYN  "\x1B[0;36m"
#define TC_B_WHT  "\x1B[0;37m"

#define TC_BG_NRM "\x1B[40m"
#define TC_BG_RED " \x1B[41m"
#define TC_BG_GRN "\x1B[42m"
#define TC_BG_YEL "\x1B[43m"
#define TC_BG_BLU "\x1B[44m"
#define TC_BG_MAG "\x1B[45m"
#define TC_BG_CYN "\x1B[46m"
#define TC_BG_WHT "\x1B[47m"

#define tc_clear_screen() puts("\x1B[2J")

#endif

char board[3][3];
char playingChoices[2][100]={
    "play single player (vs computer)",
    "play dual player (vs another player)"
};
char difficultyLevel[2][100]={
    "Human level (medium)",
    "God level (hard)"
    
};
char playAgainChoice[2][100]={
    "Yes ! ",
    "No ! "
};
struct Score
{
    int Xwins;
    int Owins;
    int draws;
};

const char PLAYER1 = 'X' ;
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

void printBoard(int cursorRow, int cursorCol);
void resetBoard();
int checkFreespaces();
int playerMove(char player);
void computerMove(char computer,int difficulty);
char checkWinner();
void printWinner(char winner, struct Score *score);
void singlePlayer(char winner, struct Score *score);
void dualPlayer(char winner, struct Score *score);
int playChoice();
void printScore(struct Score *score);

void main(){
tc_clear_screen();
printf("%s-----------Welcome To Tic-Tac-Toe-----------%s\n\n",TC_BG_CYN,TC_BG_NRM);
Sleep(1000);
printf("%sMade by%s : \t %sHassan Shakil \t Kashan Baig %s\n\n",TC_B_CYN,TC_NRM,TC_B_RED,TC_NRM);
Sleep(1000);
struct Score score;
score.draws=0;
score.Owins=0;
score.Xwins=0;
int choice=playChoice(playingChoices);
int playAgain;
if (choice==0)
{
do
{
resetBoard();
char winner = ' ';
singlePlayer(winner,&score);
printf("Do you want to play again ? \n");
playAgain=playChoice(playAgainChoice);
} while (playAgain==0);

}
else if (choice==1)
{
do
{
resetBoard();
char winner = ' ';
dualPlayer(winner,&score);
printf("Do you want to play again ? \n");
playAgain=playChoice(playAgainChoice);
} while (playAgain==0);
}
else
{
    printf("\nGame quitted!");
}

}void printBoard(int cursorRow, int cursorCol) {
    printf("%s-------------------------------------------\n", TC_B_YEL);
    for (int i = 0; i < 3; i++) {
        printf("%s|             |             |             |%s\n", TC_B_YEL, TC_NRM);// extra line before 
        printf("%s|", TC_B_YEL);
        for (int j = 0; j < 3; j++) {
            if (i == cursorRow && j == cursorCol) {
                
                printf("   [  %c  ]   ", board[i][j] == ' ' ? ' ' : board[i][j]);
            } else if (board[i][j] == PLAYER1) {
                
                printf("      %s%c      ", TC_B_GRN, PLAYER1);
            } else if (board[i][j] == PLAYER2) {
                
                printf("      %s%c      ", TC_B_BLU, PLAYER2);
            } else {
                
                printf("             ");
            }
            printf("%s|", TC_B_YEL);//middle and last " | "
        }    
        printf("\n%s|             |             |             |%s\n", TC_B_YEL, TC_NRM);
        if (i < 2) {
            printf("%s|-------------|-------------|-------------|%s\n", TC_B_YEL, TC_NRM);// extra line after
        }
    }
    printf("%s-------------------------------------------\n", TC_B_YEL);
}

void resetBoard(){
    for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        board[i][j]= ' ';
    }
    
}

};


int checkFreespaces(){
int freeSpaces = 9;
for (int i = 0; i < 3 ; i++)
{
    for (int j = 0; j < 3 ; j++)
    {
    if (board[i][j] != ' ')
    {
        freeSpaces--;         
    }       
    }
}
return freeSpaces;
};
int playerMove(char player){
int cursorRow = 0, cursorCol = 0;
char key;
int occupiedPos=0;
do
{
tc_clear_screen();
printBoard(cursorRow, cursorCol);
if (occupiedPos)
{
    printf("%sPosition already Occupied ! , Try again %s\n",TC_BG_RED,TC_BG_NRM);
    occupiedPos=0;
}
printf("%s Player %s%c's %sturn %s\n",TC_B_MAG, player=='X' ? TC_B_GRN:TC_B_BLU,player,TC_B_MAG,TC_BG_NRM);
        key = _getch(); // Read key press
        // Detect arrow keys (multi-byte sequence in Windows)
        if (key == 0 || key == -32) {
            key = _getch(); // Read actual arrow key
            switch (key) {
                case 72: // Up arrow
                    cursorRow = (cursorRow > 0) ? cursorRow - 1 : 2;
                    break;
                    return 0;
                case 80: // Down arrow
                    cursorRow = (cursorRow < 2) ? cursorRow + 1 : 0;
                    break;
                    return 0;
                case 75: // Left arrow
                    cursorCol = (cursorCol > 0) ? cursorCol - 1 : 2;
                    break;
                    return 0;
                case 77: // Right arrow
                    cursorCol = (cursorCol < 2) ? cursorCol + 1 : 0;
                    break;
                    return 0;
            }
        } else if (key == 13) { // Enter key to place the marker
            if (board[cursorRow][cursorCol] == ' ') {
                board[cursorRow][cursorCol] = player;
                break;
                return 0;
            } else {
                occupiedPos = 1;    
            }
        } 
        else
        {
            return 1;
        }         
               
    }while (1);

};

void computerMove(char computer,int difficulty){
//check for immediate win
for (int row = 0; row < 3 ; row++)
{
    for (int col = 0; col < 3 ; col++)
    {
        if (board[row][col] == ' ')
        {
            board[row][col] = COMPUTER ; 
            if (checkWinner() == COMPUTER) // if checkwinner gives us O when we mark this
            {
                return;
            }
            board[row][col] = ' ' ; 
        }   
    }    
}
//check for immediate block
for (int row = 0; row < 3 ; row++)
{
    for (int col = 0; col < 3 ; col++)
    {
        if (board[row][col] == ' ')
        {
            board[row][col] = PLAYER1 ; 
            if (checkWinner() == PLAYER1) // if on playing X the checkwi gives us X
            {
                board[row][col] = COMPUTER ; 
                return;
            }
            board[row][col] = ' ' ; 
        }   
    }    
}
//hard mode
if (difficulty == 1)
{
        if (board[0][0] == COMPUTER || board[0][0] == PLAYER1)
    {
        if(board[2][2]== ' '){
        board[2][2]   = COMPUTER;
        return;   }
    }
    else if (board[2][2] == COMPUTER || board[2][2] == PLAYER1)
    {
        if(board[0][0]== ' '){
        board[0][0]   = COMPUTER;
        return;}
    }
    else if (board[2][0] == COMPUTER || board[2][0] == PLAYER1)
    {
        if(board[0][2]== ' '){
        board[0][2]   = COMPUTER;
        return;}
    }
    else if (board[0][2] == COMPUTER || board[0][2] == PLAYER1)
    {
        if(board[2][0]== ' '){
        board[2][0]   = COMPUTER;
        return;}
    }
    
    
    
    //play center
    if (board[1][1]== ' ')
    {
        board[1][1]= COMPUTER ;
        return;
    }
   }
//play for corner
    int corners[4][2]={
        {0,0},
        {0,2},
        {2,0},
        {2,2},
    };
    // /iterating over corners ! 
    for (int i = 0; i < 4; i++)
    {
    if (board[corners[i][0]][corners[i][1]]== ' ')
    {
        board[corners[i][0]][corners[i][1]]  = COMPUTER;
        return;   
    }
    
    }


//play first available move 
for (int row = 0; row < 3 ; row++)
{
    for (int col = 0; col < 3 ; col++)
    {
        if (board[row][col] == ' ')
        {
            board[row][col] = COMPUTER ;
            return;
        }   
    }    
}

};
char checkWinner(){
for (int i = 0; i < 3 ; i++)
{
    // checking rows
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
    {
        return board[i][0];
        
    }
    // checking columns
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
    {
        return board[0][i];
    }
}
    // checking diagonals
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[2][0] == board[1][1] && board[2][0] == board[0][2] ) )
    {
        return board[1][1];
    }
    return ' '; 
};
void printWinner(char winner, struct Score *score) {
    if (winner == PLAYER1) {
        printf("%sCongrats Player %c Wins!%s\n", TC_B_GRN, PLAYER1, TC_NRM);
        score->Xwins++;
        printScore(score);  // Corrected
    } else if (winner == PLAYER2) {
        printf("%sCongrats Player %c Wins!%s\n", TC_B_GRN, PLAYER2, TC_NRM);
        score->Owins++;
        printScore(score);  // Corrected
    } else if (winner == 'q') {
        printf("%sGame Quitted%s\n", TC_B_RED, TC_NRM);
        printScore(score);  // Corrected
    } else {
        printf("%sIt's a tie!%s\n", TC_B_YEL, TC_B_NRM);
        score->draws++;
        printScore(score);  // Corrected
    }
}
void singlePlayer(char winner,struct Score *score){
    
printf("%s-----------Welcome to Single player-----------%s\n",TC_BG_YEL,TC_BG_NRM);
int choice = playChoice(difficultyLevel);
printf("%d",choice);
if (choice != 1 && choice != 0)
{
    printf("\nGame quitted!");
    return;
}
do
{

if (playerMove(PLAYER1)==1)
{
    winner='q';
    break;
}
winner=checkWinner();
if (winner != ' ' || checkFreespaces()==0  )
{
    break;
}   
printBoard(-1,-1);

computerMove(COMPUTER,choice);
winner=checkWinner();
if (winner != ' ' || checkFreespaces()==0  )
{
    break;
}
} while (winner == ' ' && checkFreespaces() != 0);
tc_clear_screen();
printBoard(-1,-1);
printWinner(winner,score);
if (winner == 'O')
{
printf("\n%sSorry ! You lose!%s\n",TC_B_RED,TC_NRM);
}
if (winner == 'X')
{
    printf("\n%sGreat Job You Won!%s\n",TC_B_GRN,TC_NRM);
}
}
void dualPlayer(char winner, struct Score *score){
printf("%s-----------Welcome to dual player-----------%s\n",TC_BG_YEL,TC_BG_NRM);
do
{

if (playerMove(PLAYER1)==1)
{
    winner='q';
    break;
}
winner=checkWinner();
if (winner != ' ' || checkFreespaces()==0  )
{
    break;
}   
printBoard(-1,-1);
if (playerMove(PLAYER2)==1)
{
    winner='q';
    break;
}

winner=checkWinner();
if (winner != ' ' || checkFreespaces()==0  )
{
    break;
}
} while (winner == ' ' && checkFreespaces() != 0);
tc_clear_screen();
printBoard(-1,-1);
printWinner(winner,score);
}

int playChoice(char choices[2][100]){
char key;
int choiceRow=0;
int choice=-1;
do
{
for (int i = 0; i < 2 ; i++)
{
    if (choiceRow==i)
    {
        printf( "%s %d) --> %s%s\n", TC_GRN,i+1,choices[i],TC_NRM);        
    }
    else
    {
        printf( "%d) %s \n",i+1 ,choices[i]);
    }   
}
key = _getch(); // Read key press
        // Detect arrow keys (multi-byte sequence in Windows)
        if (key == 0 || key == -32) {
            key = _getch(); // Read actual arrow key
            switch (key) {
                case 72: // Up arrow
                    choiceRow = (choiceRow > 0) ? choiceRow - 1 : 1;
                    tc_clear_screen();
                    break;
                case 80: // Down arrow
                    choiceRow = (choiceRow < 1) ? choiceRow  + 1 : 0;
                    tc_clear_screen();
                    break;
            }}
            else if (key == 13) { // Enter key to place the marker    
                choice=choiceRow;   
                break;
            }
            else
            {
                break;
                choice=2;
            }
} while (choice!=choiceRow || choice==2 );
return choice ;
}
void printScore(struct Score *score){
printf("\n%sScore :%s \n%s-Player X's wins : %d%s  \n%s-Player O's wins : %d%s \n%s-Draws : %d%s \n\n", 
    TC_BG_CYN,
    TC_BG_NRM,
    TC_B_GRN,
    score->Xwins,      
    TC_B_NRM,
    TC_B_RED,
    score->Owins,      
    TC_B_NRM,
    TC_B_YEL,
    score->draws,      
    TC_B_NRM
    );
      }