#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void show(char a[][62]);

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
    char territory[49][62];
    char resources[49][62];
    char people[49][62];

    int b,c;



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
            //making game field markup
            for(b=0;b<62;b++)
            {
                if(b>=0&&b<=9)
                {
                    territory[0][b]=b+48;
                    resources[0][b]=b+48;
                    people[0][b]=b+48;

                    if(b<49)
                    {
                        territory[b][0]=b+48;
                        resources[b][0]=b+48;
                        people[b][0]=b+48;
                    }
                }

                if(b>=10&&b<=35)
                {
                    territory[0][b]=b+87;
                    resources[0][b]=b+87;
                    people[0][b]=b+87;

                    if(b<49)
                    {
                        territory[b][0]=b+87;
                        resources[b][0]=b+87;
                        people[b][0]=b+87;
                    }
                }

                if(b>=36&&b<=61)
                {
                    territory[0][b]=b+29;
                    resources[0][b]=b+29;
                    people[0][b]=b+29;

                    if(b<49)
                    {
                        territory[b][0]=b+29;
                        resources[b][0]=b+29;
                        people[b][0]=b+29;
                    }
                }
            }

            for(b=1;b<62;b++)
            {
                territory[1][b]='-';
                resources[1][b]='-';
                people[1][b]='-';

                if(b>=2&&b<49)
                {
                    territory[b][1]='|';
                    resources[b][1]='|';
                    people[b][1]='|';
                }
            }
            //end making game field markup
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

void show(char a[][62])
{
    int b,c;
    for(b=0;b<49;b++)
    {
        for(c=0;c<62;c++)
        {
            printf("%c",a[b][c]);
        }
        printf("\n");
    }
}
