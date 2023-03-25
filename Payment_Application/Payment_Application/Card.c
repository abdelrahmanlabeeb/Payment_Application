//
//  Card.c
//  Payment_application
//
//  Created by Abdelrahman Hisham on 10/09/2022.
//
#include "Card.h"
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
    puts("Please enter card holder name:");
    scanf("%s", cardData->cardHolderName);
    uint16_t i = strlen((char*)cardData->cardHolderName);
    if (i > 24 || i < 20)
        return WRONG_NAME;
    return OK;
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
    puts("enter card expiry date:");
    scanf("%s", cardData->cardExpirationDate);
    uint16_t i = strlen((char*)cardData->cardExpirationDate);
    if (i != 5)
        return WRONG_EXP_DATE;
    if (cardData->cardExpirationDate[2] != '\\')
        return WRONG_EXP_DATE;
    if (cardData->cardExpirationDate[0] == '1')
    {
        if (cardData->cardExpirationDate[1] > '2')
            return WRONG_EXP_DATE;
    }
    else if (cardData->cardExpirationDate[0] == '0')
    {
        if (cardData->cardExpirationDate[1] > '9' || cardData->cardExpirationDate[1] == '0')
            return WRONG_EXP_DATE;
    }
    else
        return WRONG_EXP_DATE;
    return OK;
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
    printf("please enter card primary account number:");
    scanf("%s", cardData->primaryAccountNumber);
    uint16_t i = strlen((char*)cardData->primaryAccountNumber);
    if (i > 19 || i < 16)
        return WRONG_PAN;
    return OK;
}