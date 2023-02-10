#include "CreditCard.h"

CreditCard::CreditCard() = default;

CreditCard::CreditCard(std::string cardName) {
    this->cardName = cardName;
}

CreditCard::CreditCard(double cardBalance) {
    if(cardBalance >= 0)
        this->cardBalance = cardBalance;
}

CreditCard::CreditCard(std::string cardName, std::string cardNumber, double cardBalance, double cardLimit) {
    this->cardName = cardName;
    this->cardNumber = cardNumber;
    if(cardBalance >= 0)
        this->cardBalance = cardBalance;
    if(cardLimit > 0)
        this->cardLimit = cardLimit;

}

CreditCard::CreditCard(std::string cardName, std::string cardNumber) {
    this->cardName = cardName;
    this->cardNumber = cardNumber;
}

CreditCard::CreditCard(const CreditCard &obj) {
    cardName = obj.cardName;
    cardNumber = obj.cardNumber;
    cardBalance = obj.cardBalance;
    cardLimit = obj.cardLimit;
    cardHistory = obj.cardHistory;
}


double CreditCard::getCardLimit() const {
    return cardLimit;
}


void CreditCard::setCardLimit(double val) {
    if(val > 0)
        cardLimit = val;
}

void CreditCard::printData() const {
    std::cout << "Name : " << cardName <<
    "\nType : Credit\n" <<
    "Number : " << cardNumber <<
    "\nLimit : " << cardLimit <<
    "\nBalance : " << cardBalance << std::endl;
}

