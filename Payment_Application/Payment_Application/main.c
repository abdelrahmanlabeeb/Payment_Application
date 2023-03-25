//
//  main.c
//  Payment_application
//
//  Created by Abdelrahman Hisham on 10/09/2022.
//
#include "app.h"
#include <stdio.h>
int main() {
#if 0
    ST_cardData_t card;
    ST_cardData_t* cardptr = &card;

    // card holder name function test
#if 0
    while ((getCardHolderName(cardptr)) == WRONG_NAME);
#endif
    // card get pan function test
#if 0
    while (getCardPAN(cardptr) == WRONG_PAN);
#endif
    // card get Expiery function test
#if 1
    while (getCardExpiryDate(cardptr) == WRONG_EXP_DATE);
#endif

#endif

#if 0

    ST_cardData_t card;
    ST_cardData_t* cardptr = &card;
    ST_terminalData_t terminal;
    ST_terminalData_t* terminalptr = &terminal;
#if 0
    getTransactionDate(terminalptr);
    puts((char*)terminalptr->transactionDate);
#endif

#if 0
    while (getCardExpiryDate(cardptr) == WRONG_EXP_DATE);
    getTransactionDate(terminalptr);
    while (isCardExpired(card, terminal) == EXPIRED_CARD)
        while (getCardExpiryDate(cardptr) == WRONG_EXP_DATE);
#endif
#if 0
    while (getTransactionAmount(terminalptr) == INVALID_AMOUNT);
#endif
#if 0
    while (setMaxAmount(terminalptr) == INVALID_MAX_AMOUNT);
#endif

#if 0
    while (setMaxAmount(terminalptr) == INVALID_MAX_AMOUNT);
    while (getTransactionAmount(terminalptr) == INVALID_AMOUNT);
    while (isBelowMaxAmount(terminalptr) == EXCEED_MAX_AMOUNT)
        while (getTransactionAmount(terminalptr) == INVALID_AMOUNT);
#endif
#endif

    appStart();
    return 0;
}
