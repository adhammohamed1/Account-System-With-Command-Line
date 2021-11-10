#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "cmd.h"
#include "data.h"

void breachalert()
{
    printf("\n\t\x1b[31m!! Potential Security Breach !!\n\nProcess Terminated.");
    exit(0);
}

char *getpass()
{

    char *pswd=malloc(25),ch;
    int i=0;
    while(PROCESS)
    {
        if(ovrdcmd) return user[indx].password;
        ch=getch();

        if(ch == ENTER || ch == TAB)
        {
            pswd[i]=0;
            break;
        }
        else if(ch == BKSP)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if(!cmdlnkey && ch=='/')
        {
            cmdln();
        }
        else
        {
            pswd[i++] = ch;
            printf("* \b");
        }
    }
    return pswd;
}


