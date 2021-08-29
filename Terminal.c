#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Terminal.h"

/* Take an Object from the Structure */
ST_terminalData_t terminalData ;

/************************************************************************************
* Parameters (in): None
* Parameters (out): None
* Return value: None
* Description: Take Terminal Data from the User and store it in Terminal Structure
************************************************************************************/

void terminalEntryInfo(void)
{
    /* Set The Maximum Amount that Allowed To The User */
    terminalData.maxTransAmount = 5000.0 ;
    printf("Please Enter Terminal Data : \n");
    printf("Please Enter The Transaction Amount:\n");
    scanf("%f",&terminalData.transAmount);
    printf("Please Enter The Transaction Date:\n");
    scanf("%s",terminalData.transactionDate);
}
