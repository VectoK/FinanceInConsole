#pragma once
#include "includes.h"
#include "BankAccount.h"
class DebitCard : public BankAccount {
public:
    DebitCard();
    DebitCard(std::string cardName);
    DebitCard(double cardBalance);
    DebitCard(std::string cardName,std::string cardNumber,double cardBalance);
    DebitCard(std::string cardName,std::string cardNumber);
    DebitCard(const DebitCard& obj);
    void printData()const;

};
