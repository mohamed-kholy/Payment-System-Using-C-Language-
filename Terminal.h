#ifndef _TERMINAL_H_
#define _TERMINAL_H_

/* Structure that Holds Terminal Data */
 typedef struct ST_terminalData_t
{
    float transAmount ;
    float maxTransAmount ;
    u8 transactionDate[11];
}ST_terminalData_t;

/* Prototype of the Function that used in Terminal.c File */
void terminalEntryInfo(void);

#endif // _TERMINAL_H_


