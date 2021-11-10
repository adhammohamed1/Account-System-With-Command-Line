#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "myfunc.h"
#include "cmd.h"



int main()
{
    PROCESS = 1;
    while(PROCESS)
    {
    gvsetzero();
    signedin=0;
    load_accounts();
    homepage();
    }
    return 0;
}
