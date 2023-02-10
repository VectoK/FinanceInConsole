#pragma once
#include "CreditCard.h"
#include "DebitCard.h"
class Wallet {
private:
    std::vector<DebitCard> debitCards;
    std::vector<CreditCard> creditCards;
public:
    Wallet();
    void addCreditCard(std::string cardName, std::string cardNumber, double cardLimit, double cardBalance);
    void addDebitCard(std::string cardName, std::string cardNumber, double cardBalance);
    void addCreditCard(const CreditCard& obj);
    void addDebitCard(const DebitCard& obj);

    void deleteCreditCard(std::string cardName);
    void deleteDebitCard(std::string cardName);

    CreditCard getCreditCard(std::string cardName) const;
    DebitCard getDebitCard(std::string cardName) const;

    void printCards()const;

    void saveToFileCardHistory(std::string fileName);
    void saveToFileRating();
};
