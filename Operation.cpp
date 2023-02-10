
#include "Operation.h"

Operation::Operation(bool operationType, std::string operationInfo, double operationCost, std::tm operationDate) {
    this->operationType = operationType;
    this->operationInfo = operationInfo;
    if(operationCost > 0)
        this->operationCost = operationCost;
    this->operationDate = operationDate;
}



void Operation::printData() const {
    std::cout << "Type : " << ((operationType) ? "Deposit\n" : "Spend\n") <<
    "Info : " << operationInfo <<
    "\nPrice : " << operationCost <<
    "\nDate : " << operationDate.tm_mday << "." << operationDate.tm_mon+1 << "." << operationDate.tm_year <<
    " " << operationDate.tm_hour << ":" << operationDate.tm_min << ":" << operationDate.tm_sec << std::endl;
}

bool Operation::getOperationType() const {
    return operationType;
}

std::string Operation::getOperationInfo() const {
    return operationInfo;
}

double Operation::getOperationCost() const {
    return operationCost;
}

std::tm Operation::getOperationDate() const {
    return operationDate;
}

void Operation::dataToFile(std::string fileName) const {
    std::ofstream file(fileName, std::ios_base::app);
    file << ((operationType) ? "Deposit;" : "Spend;") <<
            operationInfo.c_str() << ";" <<
            operationCost << ";" <<
            operationDate.tm_mday << "." << operationDate.tm_mon+1 << "." << operationDate.tm_year <<
            " " << operationDate.tm_hour << ":" << operationDate.tm_min << ":" << operationDate.tm_sec << ";\n";
    file.close();
}
