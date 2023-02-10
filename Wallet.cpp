
#include "Wallet.h"

Wallet::Wallet() = default;

CreditCard Wallet::getCreditCard(std::string cardName) const {
    for(auto item : creditCards)
        if(item.getCardName() == cardName)
            return item;
}

DebitCard Wallet::getDebitCard(std::string cardName) const {
    for(auto item : debitCards)
        if(item.getCardName() == cardName)
            return item;
}

void Wallet::addCreditCard(std::string cardName, std::string cardNumber, double cardLimit, double cardBalance) {
    creditCards.push_back({cardName, cardNumber, cardLimit, cardBalance});
}

void Wallet::addDebitCard(std::string cardName, std::string cardNumber, double cardBalance) {
    debitCards.push_back({cardName, cardNumber, cardBalance});
}

void Wallet::addCreditCard(const CreditCard &obj) {
    creditCards.push_back(obj);
}

void Wallet::addDebitCard(const DebitCard &obj) {
    debitCards.push_back(obj);
}

void Wallet::deleteCreditCard(std::string cardName) {
    int i = 0;
    auto iterator = creditCards.begin();
    for(auto item : creditCards)
    {
        if(cardName == item.getCardName()) {
            creditCards.erase(iterator + i);
            break;
        }
        i++;
    }
}

void Wallet::deleteDebitCard(std::string cardName) {
    int i = 0;
    auto iterator = debitCards.begin();
    for(auto item : creditCards)
    {
        if(cardName == item.getCardName()) {
            debitCards.erase(iterator + i);
            break;
        }
        i++;
    }
}

void Wallet::printCards() const {
    for(auto item : creditCards) item.printData();

    for(auto item : debitCards) item.printData();
}

void Wallet::saveToFileCardHistory(std::string fileName) {
    std::ofstream file(fileName, std::ios_base::out);
    for(auto item : creditCards)
    {
       file << item.getCardName() << ";" << item.getCardNumber() << ";\n";
        for(auto item1 : item.getCardHistory())
            item1.dataToFile(fileName);
    }
    for(auto item : debitCards)
    {
        file << item.getCardName() << ";" << item.getCardNumber() << ";\n";
        for(auto item1 : item.getCardHistory())
            item1.dataToFile(fileName);
    }
    file.close();

}



