#include <stdlib.h>
#include "Types.h"
#include "PaymentSystem_int.h"
#include <string.h>

extern ST_accountBalance_t ServerData[10];

void main(void)
{
    EN_transStat_t x,y,z;
    ST_transaction Data;
    ReadCardData(&Data);
    ReadTerminalData(&Data);
    x=CheckAccountNumFromServer(&Data);
    if(x==APPROVED)
    {
        y= CheckBlanceFromServer(&Data);  
        if(y==APPROVED)
        {
            z= CheckExpiration(&Data);
            if(z==APPROVED)
            {
                printf("Transaction done successfully");
            }
            else
            {
               printf("Transaction Declined");
            }
        }
        else
        {
            printf("Declined");
        }      
    }
    else
        printf("DECLINED");

}