//
//  Card.h
//  Payment_application
//
//  Created by Abdelrahman Hisham on 10/09/2022.
//

#ifndef Card_h
#define Card_h
#include <string.h>
#include <stdio.h>
#include "types.h"
typedef enum EN_cardError_t
{
	OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);

#endif /* Card_h */
