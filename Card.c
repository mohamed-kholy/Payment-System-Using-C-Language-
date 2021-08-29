#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "STD_TYPES.h"
#include "Card.h"

/* Create Object from Card Structure    */
ST_CardData_t cardData ;
/* Global Variable that holds the Current Month */
u8 u8_localCurrentMonth ;
/* Global Variable that holds the Current Year */
u8 u8_localCurrentYear  ;
/* Global Variable that holds the Expire Month */
u8 u8_localExpireMonth ;
/* Global Variable that holds the Expire Year */
u8 u8_localExpireYear ;


/************************************************************************************
* Parameters (in): None
* Parameters (out): None
* Return value: None
* Description: Take Card Data from the User and store it in card Structure
************************************************************************************/
void cardEntryInfo (void)
{
    printf("Please Enter Card Data : \n");
    printf("Please Enter The Card Holder Name:\n");
    gets(cardData.cardHolderName);
    printf("Please Enter The Primary Account Number:\n");
    scanf("%s",cardData.primaryAccountNumber);
    printf("Please Enter Card Expiry Date:\n");
    scanf("%s",cardData.cardExpirationData);
}

/************************************************************************************
* Parameters (in): None
* Parameters (out): None
* Return value: return 1 if the Card Expired and 0 otherwise
* Description: Check if the Card Date Expire or not
************************************************************************************/

u8 ExpiryDateCheck(void)
{
    u8 u8_localReturn = 0 ;
    /* time Variable that holds the current Time */
    time_t t = time(NULL);
    /* Create object from Time Structure */
    struct tm tm = *localtime(&t);
    /* local Array that holds the current month */
    u8 month[5] ;
    /* local Array that holds the current Year */
    u8 year[5];
    /* Convert the current month into integer and store the result in Month Array */
    itoa(tm.tm_mon+1 , month,10);
    /* Convert the current month into integer and store the result in Year Array */
    itoa((tm.tm_year-100),year,10);
    /* local Array used to holds Two Digits Only from year of the Card Expire date */
    u8 u8_localYear[2];
    /* local Array used to holds Two Digits Only from Month of the Card Expire date */
    u8 u8_localMonth[2] ;
    /* Temp Array */
    u8 u8_localtempYear[2] ;
    u8 u8_localtempMonth[2]  ;
    /* reverse of the Array That Holds the Expire Date and Store the First Digit from the card Date into The First Digit in Local Month Array */
    u8_localMonth[0]=(cardData.cardExpirationData)[0];
    /* Store the second Digit from the card Date into The second Digit in Local Month Array */
    u8_localMonth[1]=(cardData.cardExpirationData)[1] ;
    /* Return back reverse of the Array That Holds the Expire Date and Store the Second Digit from the card Date into The First Digit in Local Year Array */
    u8_localYear[0] = strrev(cardData.cardExpirationData)[1];
    /* Store the first Digit from the card Date into The second Digit in Local Year Array */
    u8_localYear[1] =cardData.cardExpirationData[0];
    /* Just Take The First Two Digits from Temporary Month Array */
    substring(u8_localMonth,u8_localtempMonth , 1,2);
    /* Convert Current Month , Current Year , Expire Month , Expire Year into Integer to use it in the comparison */
    u8_localExpireMonth  = atoi(u8_localtempMonth);
     /* Just Take The First Two Digits from Temporary Year Array */
    substring(u8_localYear,u8_localtempYear , 1,2);
    u8_localExpireYear   = atoi(u8_localtempYear);
    u8_localCurrentMonth = atoi(month);
    u8_localCurrentYear  = atoi(year);
    /* Check if The Card is Expired */
   if( ((u8_localExpireYear < u8_localCurrentYear)&&(u8_localExpireMonth < u8_localCurrentMonth)) ||
      (((u8_localExpireYear < u8_localCurrentYear)&&(u8_localExpireMonth >= u8_localCurrentMonth))) )
   {
       u8_localReturn = 1 ;
       return u8_localReturn ;
   }
    return u8_localReturn ;
}

/************************************************************************************
* Parameters (in): String Array that needs to Substring , The Array the Holds the result , Start Position , length that returned after Start Position
* Parameters (out): Result of the Substring Array
* Return value: None
* Description: SubString incoming Array
************************************************************************************/

void substring(char str[], char sub[], int position, int len)
{
   int c = 0;

   while (c < len) {
      sub[c] = str[position+c-1];
      c++;
   }
   sub[c] = '\0';
}
