#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

void encdecpass(char c,int j)
{
    int swtch=0;
    if(c=='e')
    {
        for(int i=0; i<strlen(user[j].password); i++)
        {
            if(!(i%3))
            {
                *(user[j].password+i)+=14;
                swtch=1;
            }
            else if(swtch)
            {
                *(user[j].password+i)+=13;
                swtch=0;
            }
            else *(user[j].password+i)+=16;
        }
    }
    else if(c=='d')
    {
        for(int i=0; i<strlen(user[j].password); i++)
        {
            if(!(i%3))
            {
                *(user[j].password+i)-=14;
                swtch=1;
            }
            else if(swtch)
            {
                *(user[j].password+i)-=13;
                swtch=0;
            }
            else *(user[j].password+i)-=16;
        }
    }
}

void load_accounts()
{
    count=0;
    FILE *f;
    if(!(f=fopen("theappdrawer_accounts.txt","r")))
    {
        f=fopen("theappdrawer_accounts.txt","w");
        fclose(f);
        return;
    }
    while(!feof(f))
    {
        fscanf(f," %d, ",&user[count].id);
        fscanf(f," %[^,], ",user[count].lastName);
        fscanf(f," %[^,], ",user[count].firstName);
        fscanf(f," %[^,], ",user[count].username);
        fscanf(f," %[^\n]\n ",user[count].password);
        encdecpass('d',count);
        if(strcmp(user[count].firstName,"")) count++;
    }
    fclose(f);
}

int reg_check_credentials()
{
    short int used_uname=0;
    for(int i=0; i<count; i++)
        if(!strcmp(user[count].username,user[i].username)) used_uname=1;
    if(used_uname) return 0;
    return 1;
}

int si_check_credentials()
{
    int i;
    short int uex=0;
    for(i=0; i<count; i++)
    {
        if(!strcasecmp(active_username,user[i].username))
        {
            uex=1;
            indx=i;
        }
    }
    if(!uex) return 1;
    else
    {
        if(strcmp(active_password,user[indx].password)) return -1;
    }
    return 0;
}

void save()
{
    FILE *f=fopen("theappdrawer_accounts.txt","w");
    for(int i=0; i<count; i++)
    {
        encdecpass('e',i);
        fprintf(f,"%04d, %s, %s, %s, %s\n",user[i].id,user[i].lastName,user[i].firstName,user[i].username,user[i].password);
    }
    fclose(f);
}

void signIn(char *afn,char *aln,char*un,char*up,int id)
{
    strcpy(active_firstName,afn);
    strcpy(active_lastName,aln);
    strcpy(active_username,un);
    strcpy(active_password,up);
    active_id=id;
    signedin=1;
}
