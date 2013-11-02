#include <stdio.h>
//protypes here
void printgrid();
void cleargrid();
int returnlocation();
//global variables declared here
char grid[8][8];

int main()
{
    cleargrid();
    printgrid();
    return 0;
}

void printgrid()
{
    printf("       A             B             C \n");
    printf("     a b c         a b c         a b c \n");
    printf("   1 %c %c %c       1 %c %c %c       1 %c %c %c \n",grid[0][0],grid[0][1],grid[0][2],grid[1][0],grid[1][1],grid[1][2],grid[2][0],grid[2][1],grid[2][2]);
    printf("1  2 %c %c %c       2 %c %c %c       2 %c %c %c \n",grid[0][3],grid[0][4],grid[0][5],grid[1][3],grid[1][4],grid[1][5],grid[2][3],grid[2][4],grid[2][5]);
    printf("   3 %c %c %c       3 %c %c %c       3 %c %c %c \n",grid[0][6],grid[0][7],grid[0][8],grid[1][6],grid[1][7],grid[1][8],grid[2][6],grid[2][7],grid[2][8]);
    printf("\n\n");
    printf("     a b c         a b c         a b c \n");
    printf("   1 %c %c %c       1 %c %c %c       1 %c %c %c \n",grid[3][0],grid[3][1],grid[3][2],grid[4][0],grid[4][1],grid[4][2],grid[5][0],grid[5][1],grid[5][2]);
    printf("2  2 %c %c %c       2 %c %c %c       2 %c %c %c \n",grid[3][3],grid[3][4],grid[3][5],grid[4][3],grid[4][4],grid[4][5],grid[5][3],grid[5][4],grid[5][5]);
    printf("   3 %c %c %c       3 %c %c %c       3 %c %c %c \n",grid[3][6],grid[3][7],grid[3][8],grid[4][6],grid[4][7],grid[4][8],grid[5][6],grid[5][7],grid[5][8]);
    printf("\n\n");
    printf("     a b c         a b c         a b c \n");
    printf("   1 %c %c %c       1 %c %c %c       1 %c %c %c \n",grid[3][0],grid[3][1],grid[3][2],grid[4][0],grid[4][1],grid[4][2],grid[5][0],grid[5][1],grid[5][2]);
    printf("2  2 %c %c %c       2 %c %c %c       2 %c %c %c \n",grid[3][3],grid[3][4],grid[3][5],grid[4][3],grid[4][4],grid[4][5],grid[5][3],grid[5][4],grid[5][5]);
    printf("   3 %c %c %c       3 %c %c %c       3 %c %c %c \n",grid[3][6],grid[3][7],grid[3][8],grid[4][6],grid[4][7],grid[4][8],grid[5][6],grid[5][7],grid[5][8]);

}


void cleargrid()
{
    int iteratee = 0;
    while (iteratee < 80)
    {
        grid[iteratee % 9][iteratee / 9] = '.';
        iteratee++;
    }
}

int returnlocation()
{
    locationstart:
    int location = 0;
    printf("\nChoose which grid you wish to play in (enter in the format ' x,y ')? ");
    int row;
    char column;
    fflush(stdin);
    scanf("%c,%d", column, row);

    switch(column)
    {
    case 'a':
    case 'A': location += 1; break;
    case 'b':
    case 'B': location += 2; break;
    case 'c':
    case 'C': location += 3; break;
    default: location += 100; break;
    }
    location += row*3
    if location > 9
    {
        printf("Input Invalid")
        goto locationstart;
    }
    return location
}
