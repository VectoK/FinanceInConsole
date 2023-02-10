#include "DebitCard.h"

DebitCard::DebitCard() = default;

DebitCard::DebitCard(std::string cardName, std::string cardNumber, double cardBalance) {
    this->cardNumber = cardNumber;
    if(cardBalance >= 0)
        this->cardBalance = cardBalance;
}

DebitCard::DebitCard(std::string cardNumber) {
    this->cardNumber = cardNumber;
}

DebitCard::DebitCard(double cardBalance) {
    if(cardBalance >= 0)
        this->cardBalance = cardBalance;
}

DebitCard::DebitCard(const DebitCard &obj) {
    cardName = obj.cardName;
    cardNumber = obj.cardNumber;
    cardBalance = obj.cardBalance;
    cardHistory = obj.cardHistory;
}

void DebitCard::printData() const {
    std::cout << "Name : " << cardName <<
    "\nType : Debit\n" <<
    "Number : " << cardNumber <<
    "\nBalance : " << cardBalance << std::endl;
}




