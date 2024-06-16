#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

void print_matrix(void);
void reset_matrix(void);
int  detect_key(void);
void move_up();
void move_down();
void move_left();
void move_right();

void swap(char*,char*);
int check_space(void);

void gotoxy(int, int);
char matrix[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

int main(void)
  {       system("COLOR 3");
    
    char start;
    printf(" To enter into the game press Y\n To exit the game enter E\n");
    scanf("%c", &start);

    if ((start == 'Y') || (start == 'y'))
    {    
        printf("Welcome!");
        reset_matrix();
     while(1){
        int keyval;
        system("cls");
        print_matrix();
        keyval=detect_key();
       
        if(keyval==500)
         break;
     }
    }

    return 0;
}

void print_matrix(void)
{  system("COLOR 2");

    gotoxy(20, 10);
    printf("___________________\n");
    gotoxy(20, 11);
    printf("|     |     |     |\n");
    gotoxy(20, 12);
    printf("|  %c  |  %c  |  %c  |\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    gotoxy(20, 13);
    printf("|_____|_____|_____|\n");
    gotoxy(20, 14);
    printf("|     |     |     |\n");
    gotoxy(20, 15);
    printf("|  %c  |  %c  |  %c  |\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    gotoxy(20, 16);
    printf("|_____|_____|_____|\n");
    gotoxy(20, 17);
    printf("|     |     |     |\n");
    gotoxy(20, 18);
    printf("|  %c  |  %c  |  %c  |\n", matrix[2][0], matrix[2][1], matrix[2][2]);
    gotoxy(20, 19);
    printf("|_____|_____|_____|\n\n");
    gotoxy(5, 30);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void reset_matrix()
{
    srand(time(0));
    int empty;
    int free_space = 9;

    while (free_space != 1)
    {
        int i, j;
        static int z=48;
        i = rand() % 3;
        j = rand() % 3;

     
        if (matrix[i][j] == ' ')
           {     z++;
              matrix[i][j] = z;
               
           }
        free_space = check_space();
        
    }

}

int check_space(){
    int space=0;
    for (int k = 0; k < 3; k++)
        {
            for (int l = 0; l < 3; l++)
            {
                if (matrix[k][l] == ' ')
                    space++;
            }
        }
        return space;
}

void swap(char *a,char *b){
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int detect_key(void){
    char key;
    fflush(stdin);
    key=getch();
    switch (key)
    {
    case '2':move_down();
               break;
    case '4': move_left();
                break;
    case '8': move_up();
                break;
    case '6': move_right();
                break;
    case 'e': return 500;
                break;
    case 'E': return 500;
              break;
     default:  printf("\ninvalid key\n");
              break;
    }
}

void move_down(){
    int down;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
              if(matrix[i][j]==' ')
            {  down=3*i+j+1-3;
                  if(down>0)
                  { swap(&matrix[i][j],&matrix[i-1][j]);
                   break;}
            }
        }
    }  

}
void move_up(){
     int up,x=0;
   
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
              if(matrix[i][j]==' ')
            {  up=3*i+j+1+3;
                  if(up<10 && x<1)
                  { swap(&matrix[i][j],&matrix[i+1][j]);
                     x++;
                   break;
                   }
            }
        }
    }  
     
}

void move_left(){
     int left;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
              if(matrix[i][j]==' ')
            {  left=j+1;
                  if(left<3)
                {  swap(&matrix[i][j],&matrix[i][j+1]);
                  break;}
            }
        }
        
    }  
}

void move_right(){
     int right;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
              if(matrix[i][j]==' ')
            {  right=j+1;
                  if(right>1)
                {  swap(&matrix[i][j],&matrix[i][j-1]);
                  break;}
            }
        }
        
    }  
}








