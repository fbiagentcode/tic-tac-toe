#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

char winner;
char ttt[3][3];
char playerSYMBOL = 'X';

void cleanBOARD()
{   
    
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            ttt[i][j] = ' ';
        }
    }
    printf("\t\t |  | ");
    printf("\n\t\t------");
    printf("\n\t\t |  | ");
    printf("\n\t\t------");
    printf("\n\t\t |  | ");
}

void showBOARD()
{
    printf("\n");
    printf("------------");
    for(int i = 0; i<3; i++)
    {

        printf("\n");
        for(int j = 0; j<3; j++)
        {
            printf(" %c |", ttt[i][j]);
            
        }
        printf("\n------------");
    }
    printf("\n");

}


bool isEMPTY(int row, int col)
{
   
    if (ttt[row][col] == ' ')
    return true;
    else return false;
}



void playerMove(bool (*isempty)(int, int))
{
    bool moveSUCCESS = false, fillINpos;
    int row, col;
    while(true)
    {
        printf("\nENTER ROW: ");
        scanf("%d", &row);
        
        row--;
        printf("ENTER COLUMN: ");
        scanf("%d", &col);
        col--;
        
        fillINpos = isEMPTY(row, col);
        if (fillINpos)
        {
            ttt[row][col] = playerSYMBOL;
            break;
        }
        else
        printf("INVALID MOVE. ENTER AGAIN: ");
    }
}


void compMOVE(bool (*empty)(int, int))
{
    bool Fill_pos = false;
    
    int row = 0, col = 0;
    while(!Fill_pos)
    {
        row = rand() % 3;
        col = rand() % 3;   

        Fill_pos = isEMPTY(row, col);
        if (Fill_pos)
        {
            ttt[row][col] = 'O';
            break;
        }
        
        
    }
}




char winnerEXISTS()
{
    
    for(int i = 0; i<3; i++)
    {
        if (ttt[i][0] != ' ' && ttt[i][0] == ttt[i][1] && ttt[i][0] == ttt[i][2])
        {
            
            return ttt[i][0];
            
        }
        else if(ttt[0][i] != ' ' && ttt[0][i] == ttt[1][i] && ttt[0][i] == ttt[2][i])
        {
            return ttt[0][i];
            
        }
        else if(ttt[0][0] != ' ' && ttt[0][0] == ttt[1][1] && ttt[0][0] == ttt[2][2])
        {
            return ttt[0][0];
        }

        else if(ttt[0][2] != ' ' && ttt[0][2] == ttt[1][1] && ttt[0][2] == ttt[2][0])
        {
            return ttt[0][2];
        }
    }
    return ' ';
}


bool spacesLeft()
{
    bool isNOTfree = false;
    
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if (ttt[i][j] == ' ')
            {
                isNOTfree = true;
                break;
            }
        }
    }
    
    return isNOTfree;
}


int main()
{   
    char choice;
    srand(time(NULL));
    printf("WELCOME TO TIC TAC TOE! MAKE YOUR MOVE: \n");
    bool gameover = spacesLeft(), playerScore = 0, compScore = 0;
    
    do
    {
    
    char winnerFound = ' ';
    cleanBOARD();
    
    while(winnerFound == ' ')
    {
        
        
        playerMove(isEMPTY);
        showBOARD();
        winnerFound = winnerEXISTS();
        gameover = spacesLeft();
        if (gameover == 0) break;
        compMOVE(isEMPTY);
        showBOARD();
        winnerFound = winnerEXISTS();
       
    }

    if(winnerFound == playerSYMBOL)
    {
    printf("\nYOU WIN!", winnerFound);
    playerScore++;
    }
    else if(winnerFound == 'O')
    {
    printf("\nYOU LOST TO A 51 YEAR OLD COMPILER.");
    compScore++;
    }
    else printf("\nTIE.");
    
    printf("\nDO YOU WANT TO PLAY AGAIN? Y - yes\t N - no: ");
    scanf(" %c", &choice);
    }while(toupper(choice) == 'Y');
  printf("\nTHANKS FOR PLAYING.");
  printf("\n YOU WON %d TIMES", playerScore);
  printf("\nCOMPUTER WON %d TIMES.", compScore);

}
