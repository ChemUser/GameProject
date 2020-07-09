#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*
Turn-based strategy project
---------------------------
Started 9 June 2020
By Anonymous
---------------------------
*/

int main()
{
    //setting variables
    char a;
    char territory[79][49];
    char resources[79][49];
    char people[79][49];

    int b;

    //making game field markup
    for(b=0;b<79;b++)
    {
        territory[b][0]=b;
        resources[b][0]=b;
        people[b][0]=b;

        if(b<49)
        {
            territory[0][b]=b;
            resources[0][b]=b;
            people[0][b]=b;
        }
        if(b>0&&b<79)
        {
            territory[b][1]='-';
            resources[b][1]='-';
            people[b][1]='-';

            if(b<49)
            {
                territory[1][b]='|';
                resources[1][b]='|';
                people[1][b]='|';
            }
        }
    }
    //end making game field markup



    //displaying start menu
    printf("Menu:\n\n");
    printf("1.New game\n");
    printf("2.Load game\n");
    printf("3.Settings\n");
    printf("4.Help\n");
    printf("5.Quit\n\n");

    scanf("%c",&a);
    printf("\n");
    switch(a)
    {
        case '1':
            {

            }
        break;

        case '2':
            {

            }
        break;

        case '3':
            {

            }
        break;

        case '4':
            {

            }
        break;

        case '5':
            {
                goto q;
            }
        break;
    }

    q:
        return 0;
}

char show(char a[][49])
{
    int b,c;
    for(b=0;b<49;b++)
    {
        for(c=0;c<79;c++)
        {
            printf("%c",a[c][b]);
        }
        printf("\n");
    }
}
