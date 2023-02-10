
#include "BankAccount.h"

std::string BankAccount::getCardName() const {
    return cardName;
}

std::string BankAccount::getCardNumber() const {
    return cardNumber;
}

double BankAccount::getCardBalance() const {
    return cardBalance;
}

std::vector<Operation> BankAccount::getCardHistory() const {
    return cardHistory;
}

void BankAccount::setCardNumber(std::string val) {
    cardNumber = val;
}

void BankAccount::setCardBalance(double val) {
    if(val >= 0)
        cardBalance = val;
}

void BankAccount::deposit(std::string operationInfo, double operationCost, std::tm operationDate) {
    if(operationCost > 0) {
        cardHistory.push_back({1, operationInfo, operationCost, operationDate});
        cardBalance += operationCost;
    }
}

void BankAccount::spend(std::string operationInfo, double operationCost, std::tm operationDate) {

    if((cardBalance - operationCost) >= 0)
    {
        cardHistory.push_back({0, operationInfo, operationCost,operationDate});
        cardBalance -= operationCost;
    }
}

void BankAccount::printHistory() const {
    std::cout << "Name : " << cardName << std::endl;
    for(auto item : cardHistory)
    {
        item.printData();
    }
}

void BankAccount::printCategoryHistory(std::string category) const {
    for(auto item : cardHistory)
    {
        if(item.getOperationInfo() == category)
            item.printData();
    }
}

void BankAccount::printDayHistory(std::tm date, std::string category) const {
    for(auto item : cardHistory)
    {
        std::tm opDate = item.getOperationDate();
        if((opDate.tm_mday == date.tm_mday) && (opDate.tm_mon == date.tm_mon) && (opDate.tm_year == date.tm_year)
        && category == item.getOperationInfo() && (item.getOperationType() == 0))
            item.printData();
    }
}

void BankAccount::printMonthHistory(std::tm date, std::string category) const {

    for(auto item : cardHistory) {
        std::tm opDate = item.getOperationDate();
        if ((opDate.tm_mon == date.tm_mon) && (opDate.tm_year == date.tm_year)
        && category == item.getOperationInfo() && (item.getOperationType() == 0))
            item.printData();
    }
}

void BankAccount::printTopMaxMonthSpend(std::tm date) const {
    std::vector<int> max = findMax(cardHistory, date);
    for(int i = 0; i < 3; i++)
    {
        cardHistory.at(max[i]).printData();
    }
}

std::vector<int> BankAccount::findMax(std::vector<Operation> operations, std::tm date) const {
    std::vector<int> indexes;
    Operation max(operations[0]);
    int i, j = 0;
    while(j < 3)
    {
        i = 0;
        for(auto item : operations)
        {
            if((max.getOperationCost() < item.getOperationCost()) && (item.getOperationDate().tm_mon == date.tm_mon)
            && (item.getOperationDate().tm_year == date.tm_year)) {
                max = item;
            }
            i++;
        }
        indexes[j] = i;
        operations.erase(operations.begin()+i);
        j++;
    }
    return indexes;
}



/*void BankAccount::printTopMaxCategory(std::tm date) const {

    int i = 0;
    for(auto item : cardHistory) {
        if ((item.getOperationDate().tm_mon == date.tm_mon) && (item.getOperationDate().tm_year == date.tm_year)) {

        }
    }


}*/


