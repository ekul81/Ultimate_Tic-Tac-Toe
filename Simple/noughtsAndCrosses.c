#include <stdio.h>
char chars[9]; // yes I know it could be chars[8] but that would involve lots of changes and who cares about technical debt here...
// yes I calling it chars is confusing but I couldn't get it working with chars and who cares...
void printgrid()
{
    printf("   1 2 3 \n");
    printf(" _______ \n");
    printf("1| %i %i %i \n", chars[1] , chars[2], chars[3]);
    printf("2| %i %i %i \n", chars[4], chars[5], chars[6]);
    printf("3| %i %i %i \n\n\n", chars[7], chars[8], chars[9]);
}

int anyonewon()
{
    if ((chars[1] == chars[2] && chars[2] == chars[3] && chars[2]) != 0)
    {
        return chars[2];
    }
    else if (chars[4] == chars[5] && chars[5] == chars[6] && chars[5] != 0)
    {
        return chars[5];
    }
    else if (chars[7] == chars[8] && chars[8] == chars[9] && chars[8] != 0)
    {
        return chars[8];
    }

    else if (chars[1] == chars[4] && chars[4] == chars[7] && chars[4] != 0)
    {
        return chars[4];
    }
    else if (chars[2] == chars[5] && chars[5] == chars[8] && chars[5] != 0)
    {
        return chars[8];
    }
    else if (chars[3] == chars[6] && chars[6] == chars[9] && chars[9] != 0)
    {
        return chars[6];
    }

    else if (chars[1] == chars[5] && chars[5] == chars[9] && chars[5] != 0)
    {
        return chars[5];
    }
    else if (chars[3] == chars[5] && chars[5] == chars[7] && chars[7] != 0)
    {
        return chars[7];
    }
    else if (chars[1] != 0 && chars[2] != 0 && chars[3] != 0 && chars[4] != 0 && chars[5] != 0 && chars[6] != 0 && chars[7] != 0 && chars[8] != 0 && chars[9])
    {
        return 3;
    }
    else return 0;
}

int main()
{

    char aWinnerExists = 0; // 0 is false, 1 or 2 represent winning player, 3 indicates only solution is a draw.
    char whosTurn = 1;
    printf("##    ##  #######  ##     ##  ######   ##     ## ########  ###### \n");
    printf("###   ## ##     ## ##     ## ##    ##  ##     ##    ##    ##    ##      ##   \n");
    printf("####  ## ##     ## ##     ## ##        ##     ##    ##    ##            ##   \n");
    printf("## ## ## ##     ## ##     ## ##   #### #########    ##     ######     ###### \n");
    printf("##  #### ##     ## ##     ## ##    ##  ##     ##    ##          ##      ##   \n");
    printf("##   ### ##     ## ##     ## ##    ##  ##     ##    ##    ##    ##      ##   \n");
    printf("##    ##  #######   #######   ######   ##     ##    ##     ######            \n\n");
    printf(" ######  ########   #######   ######   ######  ########  ######  \n");
    printf("##    ## ##     ## ##     ## ##    ## ##    ## ##       ##    ## \n");
    printf("##       ##     ## ##     ## ##       ##       ##       ##       \n");
    printf("##       ########  ##     ##  ######   ######  ######    ######  \n");
    printf("##       ##   ##   ##     ##       ##       ## ##             ## \n");
    printf("##    ## ##    ##  ##     ## ##    ## ##    ## ##       ##    ## \n");
    printf(" ######  ##     ##  #######   ######   ######  ########  ######  \n"); // thanks http://www.network-science.de/ascii/
    printf("Built by Luke Dickety \n\n");
start: //yes I know labels mean evil gotos but I'm new to C...
    aWinnerExists = 0
    whosTurn = 1
    chars[1] = 0;
    chars[2] = 0;
    chars[3] = 0;
    chars[4] = 0;
    chars[5] = 0;
    chars[6] = 0;
    chars[7] = 0;
    chars[8] = 0;
    chars[9] = 0;
    printgrid();
    do
    {
go:
        printf("Player %i, decide where you wish to go...\nPlease enter the coordinates with a space in between. i.e 'x y'\n", whosTurn);
        int column;
        int row;
        scanf("%i", &column);
        scanf("%i",  &row);
        int position = 1;
        switch (row)
        {
        case 1:
            break;
        case 2:
            position += 3;
            break;
        case 3:
            position += 6;
            break;
        default:
            position += 100;
        }

        switch (column)
        {
        case 1:
            break;
        case 2:
            position += 1;
            break;
        case 3:
            position += 2;
            break;
        default:
            position += 100;
            break;
        }


        if (position > 99)
        {
            printf("\n something went wrong... Try again \n");
            goto go;
        }

        if (chars[position] != 0)
        {
            printf("Someones already gone in this square... Try a different one \n");
            goto go;
        }
        chars[position] = whosTurn;
        printgrid();
        if (whosTurn == 1)
        {
            whosTurn = 2;
        }
        else
        {
            whosTurn = 1;
        }
        aWinnerExists = anyonewon();
    }
    while (aWinnerExists == 0);
    if (aWinnerExists ==3)
    {
        printf("It's a draw... )-:");
    }
    else
    {
        printf("Player %i won, well done!!!! (-: ", aWinnerExists);
    }
    printf("\n\n\n Do you wish to play another game (y/n) \n");
    char input;
    fflush(stdin);
    input = getchar();
    if (input == 'y')
    {
        goto start;
    }
    return 0;
}


