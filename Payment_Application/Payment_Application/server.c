//
//  server.c
//  Payment_application
//
//  Created by Abdelrahman Hisham on 10/09/2022.
//

#include "server.h"
uint32_t customer_i = 0;

ST_accountsDB_t accountsDB[255] = { {10000,"239485743219432181"}, {20000,"239485743219432182"}, {30000,"239485743219432183"}, {40000,"239485743219432184"}, {50000,"239485743219432185"}, {60000,"239485743219432186"}, {70000,"2394857432194321857"} };

ST_transaction_t transDB[255] = { {0,0,0},{0,0,0},{0},{0} };

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{

    if (isValidAccount(&transData->cardHolderData) == ACCOUNT_NOT_FOUND)
        return DECLINED_STOLEN_CARD;

    if (isAmountAvailable(&transData->terminalData) == LOW_BALANCE)
        return DECLINED_INSUFFECIENT_FUND;

    if (saveTransaction(transData) == SAVING_FAILED)
        return INTERNAL_SERVER_ERROR;

    accountsDB[customer_i].balance -= transData->terminalData.transAmount;
    printf("Your new balance is: %f \n", accountsDB[customer_i].balance);
    return APPROVED;
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
    uint32_t i = 0;
    while (accountsDB[i].balance)
    {
        if ((strcmp((char*)cardData->primaryAccountNumber, (char*)accountsDB[i].primaryAccountNumber)) == 0)
        {
            customer_i = i;
            return OKyy;

        }
        i++;
    }
    return ACCOUNT_NOT_FOUND;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
    if (termData->transAmount > accountsDB[customer_i].balance)
        return LOW_BALANCE;
    else
        return OKyy;
}
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
    static uint32_t TSN = 1;
    if (TSN == 256)
        return SAVING_FAILED;

    transData->transactionSequenceNumber = TSN;
    strcpy((char*)transDB[TSN - 1].cardHolderData.cardHolderName, (char*)transData->cardHolderData.cardHolderName);
    strcpy((char*)transDB[TSN - 1].cardHolderData.primaryAccountNumber, (char*)transData->cardHolderData.primaryAccountNumber);
    strcpy((char*)transDB[TSN - 1].cardHolderData.cardExpirationDate, (char*)transData->cardHolderData.cardExpirationDate);
    transDB[TSN - 1].terminalData.maxTransAmount = transData->terminalData.maxTransAmount;
    transDB[TSN - 1].terminalData.transAmount = transData->terminalData.transAmount;
    strcpy((char*)transDB[TSN - 1].terminalData.transactionDate, (char*)transData->terminalData.transactionDate);
    transDB[TSN - 1].transactionSequenceNumber = TSN;
    transDB[TSN - 1].transState = APPROVED;
    TSN++;
    return OKyy;
}
