#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Card.h"
#include "Terminal.h"
#include "Server.h"

/* Server Data */
ST_accountBalance_t accountBalance [10]={   {100.00,"123456789"},
                                            {6000.00,"234567891"},
                                            {3250.25,"567891234"},
                                            {1500.12,"456789123"},
                                            {500.00,"258649173"},
                                            {2100.00,"654823719"},
                                            {0.00,"971362485"},
                                            {1.00,"793148625"},
                                            {10.12,"123123456"},
                                            {0.55,"456789321"}        };

/* Call The Global Variable That Holds The Current Month from Card.c File */
extern u8 u8_localCurrentMonth ;
/* Call The Global Variable That Holds The Current Year from Card.c File */
extern u8 u8_localCurrentYear  ;
/* Call The Global Variable That Holds The The Expire Month from Card.c File */
extern u8 u8_localExpireMonth ;
/* Call The Global Variable That Holds The Expire Year from Card.c File */
extern u8 u8_localExpireYear ;
/* Call The Structure that holds Card Data */
extern ST_CardData_t cardData ;
/* Call The Structure that Terminal Card Data */
extern ST_terminalData_t terminalData ;
/* Call The Structure that holds The Data Stored in the Server */
extern ST_accountBalance_t accountBalance[10];
/* global Variable Hold the Index of the Required Data for the server Array */
u8 u8_gIndx ;

/************************************************************************************
* Parameters (in): None
* Parameters (out): None
* Return value: Approve the Transaction if the Transaction process is good and Declined Otherwise
* Description: Check The Validation if the Transaction
************************************************************************************/

void checkValidate (void)
{
    /* local variable holds Check Status of the Expired Card */
    u8 u8_localExpiryCheck = 0 ;
    /* Local Variable holds check Status of the Transaction Process */
    u8 u8_localTransCheck = 0 ;
    /* Local Variable holds check Status of the Balance Check */
    u8 u8_localBalanceCheck = 0 ;
    /* Local Variable holds check status of the Primary Account Number */
    u8 u8_localPanCheck = 0 ;
    /* get the Return Status of the Function the Check */
    u8_localExpiryCheck  = ExpiryDateCheck() ;
    u8_localTransCheck   = transAmountCheck() ;
    u8_localBalanceCheck = serverBalanceCheck();
    u8_localPanCheck     = serverPanCheck() ;

    if ((u8_localExpiryCheck == 1)||
        (u8_localPanCheck == 1 ) ||
        (transAmountCheck == 1) ||
        (u8_localBalanceCheck == 1 ))
    {
            printf("Transaction is Declined \n");
    }
    else
        printf("The Transaction is Approved \n");
}

/************************************************************************************
* Parameters (in): None
* Parameters (out): Return The Result of the Transaction Amount Check
* Return value: unsigned Char that holds the Status of the Check , 1 if the Amount is Greater than the max , 0 Other wise
* Description: Check if the Transaction Amount is less than the Maximum Allowed Transaction
************************************************************************************/

u8 transAmountCheck(void)
{
    /* local Variable holds Check Status */
    u8 u8_localCheck = 0 ;
    if(terminalData.transAmount>terminalData.maxTransAmount)
    {
        return 1 ;
    }
    return 0 ;
}
/************************************************************************************
* Parameters (in): None
* Parameters (out): Return The Result of the Balance Check
* Return value: unsigned Char that holds the Status of the Check , 1 if the Amount is Greater than The Amount in the Account, 0 Other wise
* Description: Check if the Balance Amount is less than the Balance Amount of The Account
************************************************************************************/

u8 serverBalanceCheck (void)
{

    if (terminalData.transAmount >= accountBalance[u8_gIndx].balance)
    {
        return 1 ;
    }
    return 0 ;
}

/************************************************************************************
* Parameters (in): None
* Parameters (out): Return The Result of the Check of the Primary Account Number
* Return value: unsigned Char that holds the Status of the Check , 0 if the PAN is Founded in The Server , 1 Otherwise
* Description: Loop on the Server Data and Check if the Number is Exist or not , if Exists Return the Index and the Status
************************************************************************************/

u8 serverPanCheck(void)
{
    /* local Variable that holds the Status of the check */
    u8 u8_localPanCheck= 0 ;
    /* Loop On The Server Data */
    for (u8 counter = 0 ; counter < 10 ; counter++)
    {
        /* if Exists */
        if(atol(accountBalance[counter].primaryAccountNumber) == atol(cardData.primaryAccountNumber) )
            {
                u8_localPanCheck = 0 ;
                u8 u8_gIndx = counter ;
                return u8_localPanCheck ;
            }
    }
    /* Otherwise */
    return 1;

}
