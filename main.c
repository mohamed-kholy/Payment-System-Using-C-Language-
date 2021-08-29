#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "STD_TYPES.h"
#include "Card.h"
#include "Terminal.h"
#include "Server.h"


int main()
{
    /* Local Variable used to Check The Validation of the While Loop */
    u8 u8_localTestLoop = 'y';
    while ((u8_localTestLoop == 'Y')||(u8_localTestLoop == 'y'))
        {
            /* Take From the user Card Data */
            cardEntryInfo();
            /* Take From the Terminal Card Data */
            terminalEntryInfo();
            /* Check The Validation of the Process */
            checkValidate();
            /* If the User Want to Continue Press y , Other Wise press any Button */
            printf("Do You Want To Continue (y/n)?:\n");
            scanf("%s",&u8_localTestLoop);
   }
    return 0;
}
