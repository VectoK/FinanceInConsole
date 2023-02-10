#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

class Operation {
private:
    bool operationType;
    std::string operationInfo;
    double operationCost;
    std::tm operationDate;
public:
    Operation(bool operationType, std::string operationInfo, double operationCost, std::tm operationDate);
    void printData()const;
    bool getOperationType() const;
    std::string getOperationInfo() const;
    double getOperationCost() const;
    std::tm getOperationDate() const;
    void dataToFile(std::string fileName) const;

};



