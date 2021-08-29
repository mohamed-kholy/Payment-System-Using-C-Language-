#ifndef _SERVER_H_
#define _SERVER_H_

/* Structure that Holds Server Data */
typedef struct ST_accountBalance_t
{
    float balance ;
    u8 primaryAccountNumber[20];
}ST_accountBalance_t ;

/* Prototype of the Function that used in Server.c File */
void checkValidate (void);
u8 transAmountCheck(void);
u8 serverBalanceCheck (void);
u8 serverPanCheck(void);


#endif // _TERMINAL_H_


