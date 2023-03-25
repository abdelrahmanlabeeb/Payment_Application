//
//  app.c
//  Payment_application
//
//  Created by Abdelrahman Hisham on 10/09/2022.
//

#include "app.h"
void appStart(void)
{
    ST_transaction_t trans;
    ST_transaction_t* transptr = &trans;
    uint8_t again = 'y';
    while (again == 'y')
    {
        transptr = &trans;
        while (getCardHolderName(&transptr->cardHolderData) == WRONG_NAME);

        while (getCardExpiryDate(&transptr->cardHolderData) == WRONG_EXP_DATE);

        getTransactionDate(&transptr->terminalData);

        if (isCardExpired(trans.cardHolderData, trans.terminalData) == EXPIRED_CARD)
        {
            puts("Card has expired\n");
        }
        else
        {
            while (getCardPAN(&transptr->cardHolderData) == WRONG_PAN);

            while (setMaxAmount(&transptr->terminalData) == INVALID_MAX_AMOUNT);

            while (getTransactionAmount(&transptr->terminalData) == INVALID_AMOUNT);

            if (isBelowMaxAmount(&transptr->terminalData) == EXCEED_MAX_AMOUNT)
            {
                puts("transaction amount exceeds the max available");
            }
            else
            {


                switch (recieveTransactionData(transptr))
                {
                case OKyy:
                    transptr->transState = APPROVED;
                    printf("Transaction Approved \n");
                    break;
                case DECLINED_INSUFFECIENT_FUND:
                    transptr->transState = DECLINED_INSUFFECIENT_FUND;
                    printf("Amount is not available \n");
                    break;
                case DECLINED_STOLEN_CARD:
                    transptr->transState = DECLINED_STOLEN_CARD;
                    printf("Card info is incorrect, stolen card \n");
                    break;
                case INTERNAL_SERVER_ERROR:
                    transptr->transState = INTERNAL_SERVER_ERROR;
                    printf("Internal server error, Failed to save transaction\n ");
                    break;
                }
            }
        }
        printf("if you want to add another transaction click y: ");
        scanf("%s", &again);

    }
}
