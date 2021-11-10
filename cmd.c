#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "myfunc.h"
#include <conio.h>
#include <ctype.h>
#include "cmd.h"
#include "menus.h"

void printcreds()
{
    if(devMode!=1)printf("\x1b[33m");
    if(!count) printf("\tNo credentials stored.\n");
    else
    {
        if(devMode!=69)
        {
            printf("\tDisplaying all credentials stored in \"theappdrawer_accounts.txt\"...\n\t*encrypted*\n\n");
            for(int i=0; i<count; i++)
            {
                encdecpass('e',i);
                printf("\t%04d.\t%s  <---  %s\n",i+1,user[i].username,user[i].password);
                encdecpass('d',i);
            }
        }
        else if(devMode==69)
        {
            printf("\tDisplaying all credentials stored in \"theappdrawer_accounts.txt\"...\n\t*decrypted*\n\n");
            for(int i=0; i<count; i++)
            {
                printf("\t%04d.\t%s  <---  %s\n",i+1,user[i].username,user[i].password);
            }
        }
    }
    printf("\n\t");
    system("pause");
    if(devMode!=1)printf("\x1b[0m");
}

void dummy_menu()
{
    system("cls");
    print_logo();
}

void gvsetzero()
{
    signedin=0;
    count=0;
    ovrdcmd=0;

}

void notes()
{
    FILE *f=fopen("developer notes.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^#]#",devnotes);
    }
    printf("\n\n\t");
    if(devMode!=1)printf("\x1b[33m");
    printf(devnotes);
    printf("\n\n\t");
    system("pause");
    if(devMode!=1)printf("\x1b[0m");
}


void adminlogin()
{
    short int tries=0;
    while(PROCESS)
    {
        short int a=0,ku=0,kp=0;
        char username[25],password[25];
        system("cls");
        printf("\x1b[33m\x1b[40m\n\n");
        printf("\n\t\t\tAdmin Login");
        printf("\n\t\t\t=========================================================");
        printf("\n\t\t\t|                                                       |");
        printf("\n\t\t\t|\tUsername: \x1b[43m                           \x1b[40m\t\t|");
        printf("\n\t\t\t|                                                       |");
        printf("\n\t\t\t|\tPassword: \x1b[43m                           \x1b[40m\t\t|");
        printf("\n\t\t\t|                                                       |");
        printf("\n\t\t\t=========================================================");
        if(tries>0&&tries<3)printf("\x1b[31m\t\t\t\t\t\t\t\t\t\t\t\t\t\t  *%d tries left*\r\x1b[1A",4-tries);
        if(tries==3)printf("\x1b[31m\t\t\t\t\t\t\t\t\t\t\t\t\t\t    *1 try left*\r\x1b[1A");
        printf("\r\x1b[4A\x1b[43C\x1b[30m\x1b[43m");
        gets(username);
        if(!strcmp(username,"admin")) a++;
        else if(!strcmp(username,"drogoogord")) ku=1;
        printf("\n\x1b[43C");
        strcpy(password,getpass());
        if(!strcmp(password,"admin")) a++;
        if(!strcmp(password,"69420")) kp=1;
        printf("\x1b[0m\n\n\n\n");
        if(a==2)
        {
            devMode=2;
            gettingpass=0;
            break;
        }
        else if((ku+kp)==2)
        {
            devMode=69;
            KING=1;
            gettingpass=0;
            system("cls");
            printf("\x1b[33m\n\n\n\n\n\n\t\t\t\tWELCOME ABOARD CAPTAIN\n\t\t\t  > <     ALL SYSTEMS ONLINE     > <\n\t\t\t     > < \t\t     > <\n\t\t\t\t\t > <\x1b[2D");
            getche();
            printf("\x1b[0m");
            break;
        }
        else tries++;
        if(ku) breachalert();
        if(tries==4) breachalert();
    }
}

void cmdln()
{
    cmdlnkey=1;
    if(devMode!=1)printf("\x1b[30m\x1b[43m");
    printf("\n\n\n\t Command Line: ");
    gets(command);
    if(devMode!=1) printf("\x1b[0m");
    if(!strcmp(command,"sys.devmode"))
    {
        char attempt[25];
        short int tries=0;
        if(devMode!=1)
        {
            printf("\t\x1b[33m You are attempting to access developer mode. Some\n\t functionalities may operate differently and you will\n\t have access to all commands.\n\t Enter 'cancel' without the quotations to cancel.\n\t");
            while(PROCESS)
            {
                if(tries==4)
                {
                    breachalert();
                }
                if(devMode<2)
                {
                    printf("\t\x1b[30m\x1b[43mpass: ");
                    strcpy(attempt,getpass());
                }
                else
                    strcpy(attempt,"1392018");
                if(strcmp(attempt,"1392018"))
                {
                    if(!strcmp(attempt,"cancel"))
                    {
                        printf("\x1b[0m\r\x1b[4A\x1b[0J");
                        if(gettingpass)printf("\x1b[%dA\r\x1b[20C\x1b[0J",4+tries);
                        break;
                    }
                    if(tries<2)printf("\x1b[31m\x1b[40m\t <!> Access Denied! (%d tries left)\n\t",3-tries);
                    else if(tries==2)printf("\x1b[31m\x1b[40m\t <!> Access Denied! (1 try left)\n\t");
                    else printf("\x1b[0m");
                    tries++;
                }
                else
                {
                    devMode=1;
                    KING=0;
                    printf("\x1b[32m\x1b[40m\t <!> Access Granted!\x1b[33m\n\n\t ");
                    system("pause");
                    printf("\x1b[0m");
                    system("COLOR 16");
                    if(gettingpass)printf("\x1b[%dA\r\x1b[20C\x1b[0J",11+tries);
                    break;
                }
            }
        }
    }
    else if(!strcmp(command,"devmode.trm") && devMode==1)
    {
        devMode =0;
        system("COLOR  ");
        dummy_menu();
    }
    else if(!strcmp(command,"admin.trm") && devMode>1)
    {
        KING = 0;
        devMode =0;
        dummy_menu();
    }
    else if(!strcmp(command,"sys.admin") && !devMode)
    {
        printf("\t\x1b[33m Proceeding will transfer you to another menu.\n\t Are you sure you wish to proceed?\n\t Press ENTER for yes or any other button for no.\n\t\t>\x1b[0m");
        if(getche()!=ENTER)
        {
            if(!gettingpass) printf("\x1b[0m");
            else printf("\r\x1b[7A\x1b[22C\x1b[0J\x1b[47m                          \r\x1b[21C\x1b[30m\x1b[47m");
        }
        else
        {
            adminlogin();
            homepage();
        }
    }
    else if(!strcmp(command,"goto signin_menu"))
    {
        printf("\x1b[0m");
        gettingpass=0;
        signIn_menu();
    }
    else if(!strcmp(command,"goto accReg"))
    {
        printf("\x1b[0m");
        gettingpass=0;
        register_menu();
    }
    else if(!strcmp(command,"goto home"))
    {
        printf("\x1b[0m");
        gettingpass=0;
        homepage();
    }
    else if(!strcmp(command,"dev.gvsetzero"))
    {
        if(devMode)
        {
            gvsetzero();
            if(devMode!=1)printf("\x1b[33m");
            printf("\n\tGlobal Variables have been reset.\n\t");
            system("pause");
            if(devMode!=1)printf("\x1b[0m");
            if(gettingpass)printf("\r\x1b[7A\x1b[20C\x1b[0J");
        }
        else printf("\r\x1b[4A\x1b[20C\x1b[0J");
    }
    else if(!strcmp(command,"dev.printcreds"))
    {
        if(devMode && !gettingpass)printcreds();
        else printf("\r\x1b[1A\33[2K\x1b[3A\x1b[20C");
    }
    else if(!strcmp(command,"dev.override"))
    {
        if(devMode)ovrdcmd=1;
        else printf("\r\x1b[4A\x1b[20C\x1b[0J");
    }
    else if(!strcmp(command,"process.trm"))
    {
        printf("\n\n\x1b[31mProcess terminated.");
        PROCESS=0;
    }
    else if(!strcmp(command,"dev.notes") && devMode &&!gettingpass)
    {
        notes();
    }

    else if(gettingpass)
    {
        printf("\r\x1b[4A\x1b[20C\x1b[0J");
        if(devMode!=1) printf("\x1b[47m                            \r\x1b[21C\x1b[30m\x1b[47m");
    }
    cmdlnkey=0;
}
