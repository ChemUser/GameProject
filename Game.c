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
    char messgbuffer[100];
    char territory[49][62];
    char resources[49][62];
    char people[49][62];

    int b,c,d,e;
    int island_num;
    int line_num;
    int dot_num;
    int dot_x,dot_y;


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
            goto Newgame;
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

    Newgame:

    newmap:

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

    for(b=2;b<49;b++)
    {
        for(c=2;c<62;c++)
        {
            resources[b][c]='~';
            people[b][c]='~';
        }
    }
    //end making game field markup

    //generating random islands
    srand(time(NULL));
    island_num=rand()%6+5;//number of islands can be from 2 to 10
    for(b=0;b<island_num;b++)
    {
        label:
            dot_x=rand()%60+2;
            dot_y=rand()%47+2;
        if(territory[dot_y][dot_x]=='#')
        {
            goto label;
        }

        line_num=rand()%(49-dot_y);
        for(c=0;c<line_num;c++)
        {
            dot_num=rand()%(62-dot_x);
            for(d=0;d<dot_num;d++)
            {
                resources[dot_y][d+dot_x]='#';
                people[dot_y][d+dot_x]='#';
                territory[dot_y][d+dot_x]='#';
            }
            dot_y++;
            if(dot_x==2)
            {
                if(d+dot_x==61)
                {
                    dot_x=rand()%60+2;
                }
                else
                {
                    dot_x=rand()%(d+dot_x-1)+2;
                }
            }
            else
            {
                if(d+dot_x==61)
                {
                    dot_x=rand()%(63-dot_x)+dot_x-1;
                }
                else
                {
                    dot_x=rand()%(d+dot_x-1)+2;
                }
            }
        }
    }
    dot_x=0;
    dot_y=0;

    do //in this do{} while(); loop we send first colonists squad at the random position on the continent or island
    {
        dot_x=rand()%61+2;
        dot_y=rand()%47+2;
    }
    while(people[dot_y][dot_x]!='#');

    people[dot_y][dot_x]='!';
    show(people);
    printf("\n");
    scanf("%s",&messgbuffer);
    if(strspn(messgbuffer,"New")==3)
    {
        printf("\n");
        goto newmap;
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
