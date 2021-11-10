short int PROCESS;

#define ENTER 13
#define BKSP 8
#define TAB 9
#define VERSION "0.6.6"


typedef struct
{
    int id;
    char firstName[20];
    char lastName[20];
    char username[30];
    char password[50];
} User;

User user[10000];
int count,indx,active_id;
char active_username[30],active_password[50],active_firstName[20],active_lastName[20];
short int signedin;
