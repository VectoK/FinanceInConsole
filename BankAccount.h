#pragma once
#include "includes.h"
class BankAccount {
protected:
    std::string cardName = "Bank Account";
    std::string cardNumber;
    double cardBalance = 0;
    std::vector<Operation> cardHistory;
public:
    std::string getCardName() const;
    std::string getCardNumber() const;
    double getCardBalance() const;
    std::vector<Operation> getCardHistory() const;
    void setCardNumber(std::string val);
    void setCardBalance(double val);
    void deposit(std::string operationInfo, double operationCost, std::tm operationDate);
    void spend(std::string operationInfo, double operationCost, std::tm operationDate);
    void printHistory()const;
    void printCategoryHistory(std::string category) const;
    void printDayHistory(std::tm date, std::string category) const;
    void printMonthHistory(std::tm date, std::string category) const;
    void printTopMaxMonthSpend(std::tm date) const;
/*    void printTopMaxCategory(std::tm date) const;*/
    std::vector<int> findMax(std::vector<Operation> operations, std::tm date)const;
};
