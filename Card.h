#ifndef _CARD_H_
#define _CARD_H_

/* Structure that Holds Card Data */
   typedef struct ST_cardData_t
    {
        u8 cardHolderName[20] ;
        u8 primaryAccountNumber[20];
        u8 cardExpirationData[6];
    }ST_CardData_t ;

    /* Prototype of the Function that used in Card.c file */
    void cardEntryInfo (void);
    u8 ExpiryDateCheck(void);
    void substring(char str[], char sub[], int position, int len) ;

#endif
