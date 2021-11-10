#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "myfunc.h"
#include <conio.h>
#include <ctype.h>
#include "cmd.h"

void print_logo()
{
    if(devMode==69)
    {
        printf("\x1b[33m\tKING Mode\n\n");
        printf("\t/\\_/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\__/\\_/\\\n");
        printf("\t========================================================================================");
        printf("\n\t||                                                                                    ||");
        printf("\n\t||          >   >                   THE APP DRAWER                      <   <         ||");
        printf("\n\t||                                                                                    ||");
        printf("\n\t========================================================================================");
        if(!signedin)
        {
            printf("\n\t||\x1b[35m  V %s \x1b[33m ||\r\x1b[76C||\x1b[35m AM Productions\x1b[33m ||",VERSION);
        }
        else
        {
            printf("\n\t||\x1b[35m  V %s \x1b[33m ||\t\t\t\x1b[31m  %s %s #%04d\x1b[33m\r\x1b[76C||\x1b[35m AM Productions\x1b[33m ||",VERSION,active_firstName,active_lastName,active_id);
        }
        printf("\n\t========================================================================================\x1b[0m\n");
    }
    else if(devMode!=1)
    {
        if(devMode==2) printf("\x1b[36m\tAdmin Mode\n\n\x1b[0m");
        printf("\t========================================================================================");
        if(devMode==2)printf("  count=%d",count);
        printf("\n\t||                                                                                    ||");
        if(devMode==2)printf("  signedin=%d",signedin);
        printf("\n\t||          >   >                   THE APP DRAWER                      <   <         ||");
        printf("\n\t||                                                                                    ||");
        printf("\n\t========================================================================================");
        if(!signedin)
        {
            printf("\x1b[0m\n\t||\x1b[35m  V %s \x1b[0m ||\r\x1b[76C||\x1b[35m AM Productions\x1b[0m ||",VERSION);
        }
        else
        {
            printf("\n\t||\x1b[35m  V %s \x1b[0m ||\t\t\t\x1b[31m  %s %s #%04d\x1b[0m\r\x1b[76C||\x1b[35m AM Productions\x1b[0m ||",VERSION,active_firstName,active_lastName,active_id);
        }
        printf("\n\t========================================================================================\n");
    }
    else
    {
        if(devMode==1)printf("\tDeveloper Mode\n\n");
        printf("\t========================================================================================");
        printf("  count=%d",count);
        printf("\n\t||                                                                                    ||");
        printf("  signedin=%d",signedin);
        printf("\n\t||          >   >                   THE APP DRAWER                      <   <         ||");
        printf("\n\t||                                                                                    ||");
        printf("\n\t========================================================================================");
        if(!signedin)
        {
            printf("\n\t||  V %s  ||\r\x1b[76C|| AM Productions ||",VERSION);
        }
        else
        {
            printf("\n\t||  V %s  ||\t\t\t  %s %s #%04d\r\x1b[76C|| AM Productions ||",VERSION,active_firstName,active_lastName,active_id);
        }
        printf("\n\t========================================================================================\n");

    }
}

void update_path(char s[])
{
    if(KING)printf("\x1b[33m");
    char path[200]="\t| THE APP DRAWER > ";
    strcat(path,s);
    printf("%s\n",path);
    printf("\t========================================================================================\n");
    if(devMode!=1)printf("\x1b[0m");
}

void register_menu()
{
    char elm, s[2];
    while(PROCESS)
    {
        system("cls");
        print_logo();
        update_path("Register");

        printf("\n\t <|> Register:\t\t\t\t\t\t\t\t   You can enter\n\t--------------\t\t\t\t\t\t\t\t 0 in the firstname\n\t\t\t\t\t\t\t\t\t\t     to cancel");
        if(count==9999)
        {
            printf("\n\t Maximum account capacity reached.");
            return;
        }
        if(devMode!=1) printf("\n\t First Name : \x1b[47m                            \x1b[0m\n\n\t Last Name  : \x1b[47m                            \x1b[0m\n\n\t Username   : \x1b[47m                            \x1b[0m\n\n\t Password   : \x1b[47m                            \x1b[6A\x1b[27D\x1b[30m");
        else printf("\n\t First Name : \n\n\t Last Name  : \n\n\t Username   : \n\n\t Password   : \x1b[6A\x1b[1C");
        elm=getche();
        if(elm=='/')
        {
            printf("\x1b[1D\x1b[0K\n\n\n");
            cmdln();
            continue;
        }
        else if(elm=='0')
        {
            if(devMode!=1)printf("\x1b[0m");
            printf("\x1b[6B\r\t Process Canceled.\n\t ");
            system("pause");
            return;
        }
        else if(elm==ENTER || elm==TAB || elm==' ')
        {
            printf("\x1b[0m");
            continue;
        }
        else
        {
            s[0]=elm;
            s[1]=0;
        }
        gets(user[count].firstName);
        strcpy(user[count].firstName,strcat(s,user[count].firstName));
        if(islower(*user[count].firstName))
        {
            *user[count].firstName=toupper(*user[count].firstName);
            printf("\x1b[1A\r\x1b[23C%s",user[count].firstName);
        }
        if(devMode!=1)printf("\x1b[30m\x1b[47m");
        printf("\n\n\r\x1b[23C");
take_lastname_register:
        printf("\r\x1b[22C\x1b[47m                            \r\x1b[23C");
        elm=getche();
        if(elm=='/')
        {
            printf("\x1b[1D\x1b[0K\n\n\n");
            cmdln();
            continue;
        }
        else if(elm=='0')
        {
            if(devMode!=1)printf("\x1b[0m");
            printf("\x1b[6B\r\t Process Canceled.\n\t ");
            system("pause");
            return;
        }
        else if(elm==ENTER || elm==TAB || elm==' ')
            goto take_lastname_register;
        else
        {
            s[0]=elm;
            s[1]=0;
        }
        gets(user[count].lastName);
        strcpy(user[count].lastName,strcat(s,user[count].lastName));
        if(islower(*user[count].lastName))
        {
            *user[count].lastName=toupper(*user[count].lastName);
            printf("\x1b[1A\r\x1b[23C%s",user[count].lastName);
        }
        printf("\n\n\r\x1b[23C");
take_username_register:
        printf("\r\x1b[22C\x1b[47m                            \r\x1b[23C");
        if(devMode!=1)printf("\x1b[30m\x1b[47m");
        elm=getche();
        if(elm=='/')
        {
            printf("\x1b[1D\x1b[0K\n\n\n");
            cmdln();
            continue;
        }
        else if(elm=='0')
        {
            if(devMode!=1)printf("\x1b[0m");
            printf("\x1b[6B\r\t Process Canceled.\n\t ");
            system("pause");
            return;
        }
        else if(elm==ENTER || elm==TAB || elm==' ')
        {
            goto take_username_register;
        }
        else
        {
            s[0]=elm;
            s[1]=0;
        }
        gets(user[count].username);
        strcpy(user[count].username,strcat(s,user[count].username));
        printf("\x1b[0m\x1b[1A\r\x1b[59C\x1b[0K\r\x1b[23C\n\r");
        int check=reg_check_credentials();
        if(!check)
        {
            if(devMode!=1)printf("\x1b[1A\r\x1b[22C\x1b[47m                            \x1b[0m \x1b[41m ! \x1b[33m\x1b[40m Username already in use!\r\x1b[23C\x1b[0m");
            else printf("\x1b[1A\r\x1b[19C\x1b[0K\x1b[32C <!>  Username already in use!\r\x1b[20C");
            goto take_username_register;
        }
        if(devMode!=1)printf("\x1b[0m\x1b[1A\x1b[51C\x1b[0K\x1b[37m\x1b[42m %c ",251);
        else printf("\x1b[1A\x1b[51C\x1b[0K %c ",251);
        gettingpass=1;
        printf("\n\n\r\x1b[23C");
take_password_register:
        if(devMode!=1)printf("\x1b[30m\x1b[47m");
        printf("\r\x1b[22C\x1b[47m                            \r\x1b[23C");
        strcpy(user[count].password,getpass());
        if(*user[count].password==0 || *user[count].password==ENTER || *user[count].password==TAB || *user[count].password==' ') goto take_password_register;
        gettingpass=0;
        if(devMode!=1)printf("\x1b[0m");
        break;
    }
    user[count].id=user[count-1].id+1;
    count++;
    save();
    load_accounts();
    printf("\n\n\n\t Account created successfully.\n\t ");
    system("pause");
}




void signIn_menu()
{
    char elm,s[2];
    while(PROCESS)
    {
        system("cls");
        print_logo();
        update_path("Sign in");
        strcpy(active_password," ");
        printf("\n\t <|> Sign in:\t\t\t\t\t\t\t\t You can enter\n\t-------------\t\t\t\t\t\t\t\t0 in the username\n\t\t\t\t\t\t\t\t\t\t   to cancel");
        if(devMode!=1)printf("\n\t Username : \x1b[47m                            \x1b[0m\n\n\t Password : \x1b[47m                            \x1b[2A\r\x1b[21C\x1b[0m");
        else printf("\n\t Username : \n\n\t Password : \x1b[2A\r\x1b[21C");
take_username_signIn:
        if(devMode!=1)printf("\x1b[30m\x1b[47m");
        elm=getche();
        if(elm=='/')
        {
            printf("\x1b[1D \n");
            if(devMode!=1)printf("\x1b[0m");
            cmdln();
            continue;
        }
        else if(elm==ENTER||elm==TAB||elm==' ')
        {
            continue;
        }
        else if(elm=='0')
        {
            if(devMode!=1)printf("\x1b[0m");
            printf("\x1b[4B\r\t Process Canceled.\n\t ");
            system("pause");
            return;
        }
        else
        {
            s[0]=elm;
            s[1]=0;
        }
        gets(active_username);
        strcpy(active_username,strcat(s,active_username));
        if(devMode!=1)printf("\x1b[0m");
        printf("\x1b[1A\r\x1b[59C\x1b[0K\n\r");
        int check=si_check_credentials();
        if(check==1)
        {
            if(devMode==1) printf("\r\x1b[1A\x1b[19C\x1b[0K\x1b[32C<!> Username doesn't exist!\r\x1b[20C");
            else
            {
                printf("\r\x1b[1A\x1b[51C\x1b[0K\x1b[41m ! \x1b[33m\x1b[40m Username doesn't exist!\r\x1b[21C\x1b[0m");
                printf("\x1b[47m                           \r\x1b[21C");
            }
            goto take_username_signIn;
        }
        if(devMode==1) printf("\x1b[1A\x1b[51C\x1b[0K<!> Valid!\n\r");
        else printf("\x1b[1A\x1b[51C\x1b[0K\x1b[42m %c \n\r\x1b[0m",251);
        printf("\n\x1b[21C");
take_password_signIn:
        if(devMode!=1) printf("\x1b[47m                           \r\x1b[21C\x1b[30m\x1b[47m");
        gettingpass=1;
        if(KING)strcpy(active_password,user[indx].password);
        else strcpy(active_password,getpass());
        ovrdcmd=0;
        if(devMode!=1)printf("\x1b[0m");
        printf("\r\x1b[59C\x1b[0K\n\r");
        check=si_check_credentials();
        if(check==-1)
        {
            if(devMode==1) printf("\x1b[1A\r\x1b[19C\x1b[0K\x1b[32C<!> Wrong password!\r\x1b[20C");
            else
            {
                printf("\x1b[1A\r\x1b[19C\x1b[0K\x1b[32C\x1b[41m ! \x1b[33m\x1b[40m Wrong password!\r\x1b[20C\x1b[0m");
                printf("\x1b[47m                            \r\x1b[21C");
            }
            goto take_password_signIn;
        }
        gettingpass=0;
        break;
    }
    signIn(user[indx].firstName,user[indx].lastName,user[indx].username,user[indx].password,user[indx].id);
    if(devMode==1) return;
    else if(devMode==2)
    {
        printf("\x1b[1A\r\x1b[50C\x1b[0K\r");
        printf("\n\n\n\t Successfully logged in as %s.\n\n\t ",active_firstName);
        printf("\r\x1b[30A\x1b[9B\x1b[36C\x1b[32m--> Success!\x1b[0m\x1b[12B\r\t ");
    }
    else if(devMode==69)
    {
        printf("\x1b[1A\r\x1b[50C\x1b[0K\r");
        printf("\n\n\n\t Successfully logged in as %s.\n\n\t ",active_firstName);
        printf("\r\x1b[30A\x1b[10B\x1b[36C\x1b[32m--> Success!\x1b[0m\x1b[12B\r\t ");
    }
    else
    {
        printf("\x1b[1A\r\x1b[50C\x1b[0K\r");
        printf("\n\n\n\t Welcome, %s!\n\n\t ",active_firstName);
        printf("\r\x1b[30A\x1b[7B\x1b[36C\x1b[32m--> Success!\x1b[0m\x1b[12B\r\t ");
    }
    system("pause");
}

void exit_menu()
{
    while(PROCESS)
    {
        system("cls");
        print_logo();
        printf("\n\t\t<!> Are you sure you want to exit?\n\t\t    1. Yes\n\t\t    2. No\n\t\t     >");
        switch(getche())
        {
        case '1':
            printf("\b \b\n");
            exit(0);
        case '2':
            return;
        default:
            continue;
        }
    }
}

void manage_account()
{

}

void logout_menu()
{
    while(PROCESS)
    {
        system("cls");
        print_logo();
        printf("\n\t<!> Log out of \"%s %s\" ?\n\n\t    1. Yes\n\t    2. No\n\t     >",active_firstName,active_lastName);
        switch(getche())
        {
        case '1':
            signedin=0;
        case '2':
            return;
        default:
            continue;
        }
    }
}

void profile_page()
{
    cmdlnkey=0;
    while(PROCESS)
    {
        system("cls");
        print_logo();
        if(devMode!=1)
        {
            printf("\x1b[36m\t\n\t\x1b[47m|    |\n\t| \x1b[30m()\x1b[36m |\x1b[0m %s %s\x1b[36m\x1b[47m\n\t| \x1b[30m/\\\x1b[36m |\x1b[34m\x1b[40m #%04d\x1b[36m\x1b[47m\n\t|____|\x1b[0m\n\n\t1. Manage account\n\t2. Logout\n\t3. Quit\n\t >",active_firstName,active_lastName,active_id);
            switch(getche())
            {
            case '1':
                manage_account();
                break;
            case '2':
                logout_menu();
                if(!signedin) return;
                break;
            case '3':
                exit_menu();
                break;
            case '/':
                printf("\33[2K\r\t >");
                cmdln();
                break;
            default:
                continue;
            }
        }
        else
        {
            printf("\n\tWelcome to my account system!\n\t------------------------------\n\t1. Register\n\t2. Sign in\n\t3. Developer Notes\n\t >");
            switch(getche())
            {
            case '1':
                register_menu();
                break;
            case '2':
                signIn_menu();
                break;
            case '3':
                notes();
                break;
            case '/':
                printf("\33[2K\r\t >");
                cmdln();
                break;
            default:
                continue;
            }
        }
    }
}


void homepage()
{
    load_accounts();
    cmdlnkey=0;
    while(!signedin && PROCESS)
    {
        system("cls");
        print_logo();
        if(devMode!=1)
        {
            printf("\n\tWelcome to the app drawer!\n\t--------------------------\n\t>");
            printf("\n");
            printf("\n\t\t\t\t       ________________________");
            printf("\n\t\t\t\t      [________________________]");
            printf("\n\t\t\t\t      (|                      |)");
            printf("\n\t\t\t\t      (|      1. Sign In      |)");
            printf("\n\t\t\t\t      (|______________________|)");
            printf("\n\t\t\t\t      (|                      |)");
            printf("\n\t\t\t\t      (|      2. Register     |)");
            printf("\n\t\t\t\t      (|______________________|)");
            printf("\n\t\t\t\t      (|                      |)");
            printf("\n\t\t\t\t      (|       3. Quit        |)");
            printf("\n\t\t\t\t      (|______________________|)");
            printf("\n\t\t\t\t      [________________________]");
            printf("\x1b[13A\r\x1b[10C");
            switch(getche())
            {
            case '1':
                signIn_menu();
                break;
            case '2':
                register_menu();
                break;
            case '3':
                exit_menu();
                break;
            case '/':
                printf("\33[2K\r\t >\n\n\n\n\n\n\n\n\n\n\n\n");
                cmdln();
                break;
            default:
                continue;
            }
        }
        else
        {
            printf("\n\tWelcome to my account system!\n\t------------------------------\n\t1. Sign in\n\t2. Register\n\t3. Developer Notes\n\t >");
            switch(getche())
            {
            case '1':
                signIn_menu();
                break;
            case '2':
                register_menu();
                break;
            case '3':
                notes();
                break;
            case '/':
                printf("\33[2K\r\t >");
                cmdln();
                break;
            default:
                continue;
            }
        }
    }
    while(signedin && PROCESS)
    {
        system("cls");
        profile_page();

    }
}
