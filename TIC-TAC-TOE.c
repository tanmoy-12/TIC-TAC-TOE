#include<stdio.h>
char board[]={'0','1','2','3','4','5','6','7','8','9'},choice,mark;
int result,count,player=1,input,status=-1;
int Board(); //To print the board
int checkwin(); //To check staatus of the game
void Choice_X(); //If the choice of player 1 is X
void Choice_O(); //If player 1 chooses O
void system();

void main()
{
    Board();
    printf("Enter the mark of your choice : ");
    scanf("%c",&choice);
    //choice Checking //
    if(choice=='X') 
    {
        Choice_X();
    }
    else if(choice=='O')
    {
        Choice_O();
    }
    else
    {
        printf("Invalid Choice ! \n");
    }

}

void Choice_X()
{
    while(status==-1)
        {
            player=(player%2==0) ? 2:1; //To change players
            mark=(player==1) ? 'X' : 'O';
            printf("Enter the position of your choice for player %d : ",player);
            scanf("%d",&input);
            if(input<1 || input>9) //To avoid mistakes
            {   printf("Invalid Input ! \n");
                continue;
            }
            else 
                {
                    if(board[input]=='X' || board[input]=='O')
                    {
                        printf("The place is already filled ! \n");
                        continue;
                    }
                    board[input]=mark;
                    Board();
                }
            result=checkwin();
            if(result==1)
            {
                printf("Congratulations! || Player %d is winner !",player);
                return;
            }
            else if(result==0)
            {
                printf("The match is draw || Better Luck next time \n");
                return;
            }
            player++;
        }
}

void Choice_O()
{
    while(status==-1)
        {
            player=(player%2==0) ? 2:1; //To change players
            mark=(player==1) ? 'O' : 'X';
            printf("Enter the position of your choice for player %d : ",player);
            scanf("%d",&input);
            if(input<1 || input>9)//To avoid errors
            {
                printf("Invalid Input ! \n");
                continue;
            }
            else 
                {
                    if(board[input]=='X' || board[input]=='O')
                    {
                        printf("The place is already filled ! \n");
                        continue;
                    }
                    board[input]=mark;
                    Board();
                }
            result=checkwin();
            if(result==1)
            {
                printf("Player %d is winner !",player);
                return;
            }
            else if(result==0)
            {
                printf("The match is draw || Better Luck next time \n");
                return;
            }
            player++;
        }
}

//To draw the board and take input from the user//
int Board()
{
    system("cls");
    printf(" --TIC-TAC-TOE-- \n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
    printf("     |     |     \n");
    return 0;
}

//To check if the game is in wining condition or it will be draw
int checkwin()
{
    if(board[1]==board[2] && board[2]==board[3])
    return 1;
    if(board[2]==board[5] && board[5]==board[8])
    return 1;
    if(board[3]==board[6] && board[6]==board[9])
    return 1;
    if(board[1]==board[4] && board[4]==board[7])
    return 1;
    if(board[4]==board[5] && board[5]==board[6])
    return 1;
    if(board[7]==board[8] && board[8]==board[9])
    return 1;
    if(board[1]==board[5] && board[5]==board[9])
    return 1;
    if(board[3]==board[5] && board[5]==board[7])
    return 1;
    count=0;
    for(int i=1;i<=9;i++)
    {
        if(board[i]=='X' || board[i]=='O')
        {
            count++;
        }
    }
    if(count==9)
    {
        return 0;
    }
    else
    return -1;
}