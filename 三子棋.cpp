#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define ROW 3
#define COL 3
char board[ROW][COL]={0};
void init_board()
{
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            board[i][j]=' ';
}

// void display_board()
// {
//     for(int i=0;i<ROW;i++)
//     {
//         for(int j=0;j<COL;j++)
//         {
//             printf("%c",board[i][j]);
//             printf("_|_");
//         }
//     printf("\n");
//     }
// }
void display_board()
{
	int i = 0;
	for(i = 0;i < ROW;i++)
	{
		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		if(i != ROW-1)   
		{
			printf("---|---|---\n");
		}
	}
	return ;
} 

void comptutr_move(char board[ROW][COL])
{
    srand((unsigned)time(NULL));
    int a=rand()%3;
    int b=rand()%3;
    int succss_flag=0;
    //int empty_flag =is_full(board);
    while(succss_flag==0)
    {
        if(board[a][b]==' ')
        {
            board[a][b]='X';
            succss_flag=1;
        }
        else
        {
            a=rand()%3;
            b=rand()%3;
        }
        
    }
}
void play_move(char board[ROW][COL])
{
    printf("Please input a row,row number must <3\n");
    int row,col;
    scanf("%d",&row);
    printf("Please input a col,col number must <3\n");
    scanf("%d",&col);
    if(row<3&&row>=0&&col<3&&col>=0)
    {
        board[row][col]='O';
    }
    else
    {
        printf("error!");
    }
    
}
int is_full(char board[ROW][COL])
{
    int count=0;
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(board[i][j]==' ')
            {
                count+=1;
            }
        }
    }
    if (count==0) return 1; //1是满
    if (count!=0) return 0; //0是空
}
char is_win()
{
	int i = 0;
	for(i=0;i<ROW;i++)
	{
		if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][1] != ' '))
		{
			return board[i][1];
		}
	}
	for(i=0;i<COL;i++)
	{
		if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[1][i] != ' '))
		{
			return board[1][i];
		}
	}
	if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1] != ' '))
	{
		return board[1][1];
	}
	if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' '))
	{
		return board[1][1];
	}
	 
	if(is_full(board))
	{
		return 'Q';
	} 
	 
	return ' ';
}

int main()
{
    init_board();
    display_board();
    char c=' ';
    while(1)
    {
        printf("Computer move\n");
        printf("***********\n");
        comptutr_move(board);
        display_board();
        c=is_win();
        if(c!=' '){printf("computer win"); break;}
        printf("***********\n");
        printf("Play move\n");
        play_move(board);
        display_board();
        c=is_win();
        if(c!=' '){printf("Players win");break;}
    }
}

