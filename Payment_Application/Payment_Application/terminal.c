//
//  terminal.c
//  Payment_application
//
//  Created by Abdelrahman Hisham on 10/09/2022.
//

#include "terminal.h"
void getTransactionDate(ST_terminalData_t* termData)
{
    time_t rawtime;
    struct tm* info;
    char buffer[11];

    time(&rawtime);

    info = localtime(&rawtime);

    strftime(buffer, 10, "%d\\%m\\%Y", info);

    strcpy((char*)termData->transactionDate, buffer);
}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
    if (termData.transactionDate[8] > cardData.cardExpirationDate[3])
        return EXPIRED_CARD;
    else if (termData.transactionDate[8] < cardData.cardExpirationDate[3])
        return OKy;
    else
    {
        if (termData.transactionDate[9] > cardData.cardExpirationDate[4])
            return EXPIRED_CARD;
        else if (termData.transactionDate[9] < cardData.cardExpirationDate[4])
            return OKy;
        else
        {
            if (termData.transactionDate[3] > cardData.cardExpirationDate[0])
                return EXPIRED_CARD;
            else if (termData.transactionDate[3] < cardData.cardExpirationDate[0])
                return OKy;
            else
            {
                if (termData.transactionDate[4] > cardData.cardExpirationDate[1])
                    return EXPIRED_CARD;
            }
            return OKy;
        }
    }
    return OKy;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
    printf("enter the transactoin amount: ");
    scanf("%f", &termData->transAmount);
    if (termData->transAmount > 0)
        return OKy;
    return INVALID_AMOUNT;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
    printf("enter the max amount: ");
    scanf("%f", &termData->maxTransAmount);
    if (termData->maxTransAmount > 0)
        return OKy;
    return INVALID_MAX_AMOUNT;
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
    if (termData->maxTransAmount < termData->transAmount)
        return EXCEED_MAX_AMOUNT;
    return OKy;
}

