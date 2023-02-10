#pragma once
#include "includes.h"
#include "BankAccount.h"
class CreditCard : public BankAccount{
private:
    double cardLimit = 0;
public:
    CreditCard();
    CreditCard(std::string cardName);
    CreditCard(double cardBalance);
    CreditCard(std::string cardName, std::string cardNumber, double cardBalance, double cardLimit);
    CreditCard(std::string cardName,std::string cardNumber);
    CreditCard(const CreditCard& obj);
    std::string getCardType() const;
    double getCardLimit() const;
    void setCardLimit(double val);
    void printData() const;

};

