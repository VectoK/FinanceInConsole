#include "Wallet.h"
int main() {
    Wallet wallet;
    bool flag = 1;
    while(flag)
    {
        std::cout << "Choose the option\n"
                     "0 - Exit\n"
                     "1 - Add Credit Card\n"
                     "2 - Add Debit Card\n"
                     "3 - Deposit Money\n"
                     "4 - Spend Money\n"
                     "5 - Get Card History\n"
                     "6 - Print Finance Report\n"
                     "7 - TOP3 Month Spends\n"
                     "8 - Save To File" << std::endl;
        int choice;
        std::cin >> choice;
        switch(choice)
        {
            default:
            {
                std::cout << "No such option" << std::endl;
                break;
            }
            case 0:
            {
                flag = 0;
                break;
            }
            case 1:
            {
                std::cout << "Enter Card Name : " << std::endl; std::string cardName; getline(std::cin, cardName);
                std::cout << "Enter Card Number : " << std::endl; std::string cardNumber; getline(std::cin, cardNumber);
                std::cout << "Enter Card Balance : " << std::endl; double cardBalance; std::cin >> cardBalance;
                std::cout << "Enter Card Limit : " << std::endl; double cardLimit; std::cin >> cardLimit;
                wallet.addCreditCard({cardName, cardNumber, cardBalance, cardLimit});
                break;
            }
            case 2:
            {
                std::cout << "Enter Card Name : " << std::endl; std::string cardName; getline(std::cin, cardName);
                std::cout << "Enter Card Number : " << std::endl; std::string cardNumber; getline(std::cin, cardNumber);
                std::cout << "Enter Card Balance : " << std::endl; double cardBalance; std::cin >> cardBalance;
                wallet.addDebitCard({cardName, cardNumber, cardBalance});
                break;
            }
            case 3:
            {
                std::cout << "Enter Card Name : " << std::endl; std::string cardName; getline(std::cin, cardName);
                std::cout << "Credit/Debit - 1/0" << std::endl; bool type; std::cin >> type;

                std::cout << "Enter Deposit Info : " << std::endl; std::string info; getline(std::cin, info);
                std::cout << "Enter Deposit Amount : " << std::endl; double cost; std::cin >> cost;
                std::cout << "Enter date dd mm yyyy hh mm ss : " << std::endl; std::tm opData; std::cin >> opData.tm_mday >> opData.tm_mon >>
                                                                                                        opData.tm_year >> opData.tm_hour >> opData.tm_min >> opData.tm_sec;
                (type) ? wallet.getCreditCard(cardName).deposit(info, cost, opData) :
                wallet.getDebitCard(cardName).deposit(info, cost, opData);
                break;
            }
            case 4:
            {
                std::cout << "Enter Card Name : " << std::endl; std::string cardName; getline(std::cin, cardName);
                std::cout << "Credit/Debit - 1/0" << std::endl; bool type; std::cin >> type;

                std::cout << "Enter Spend Info : " << std::endl; std::string info; getline(std::cin, info);
                std::cout << "Enter Spend Amount : " << std::endl; double cost; std::cin >> cost;
                std::cout << "Enter date dd mm yyyy hh mm ss : " << std::endl; std::tm opData; std::cin >> opData.tm_mday >> opData.tm_mon >>
                                                                                                        opData.tm_year >> opData.tm_hour >> opData.tm_min >> opData.tm_sec;
                (type) ? wallet.getCreditCard(cardName).spend(info, cost, opData) :
                wallet.getDebitCard(cardName).spend(info, cost, opData);
                break;
            }
            case 5:
            {
                std::cout << "Enter Card Name : " << std::endl; std::string cardName; getline(std::cin, cardName);
                std::cout << "Credit/Debit - 1/0" << std::endl; bool type; std::cin >> type;
                (type) ? wallet.getCreditCard(cardName).printHistory() :
                wallet.getDebitCard(cardName).printHistory();
                break;
            }
            case 6:
            {
                std::cout << "Enter Card Name : " << std::endl; std::string cardName; getline(std::cin, cardName);
                std::cout << "Credit/Debit - 1/0" << std::endl; bool type; std::cin >> type;
                std::cout << "Month/Day - 1/0" << std::endl; bool md; std::cin >> md;
                std::cout << "Which category?" << std::endl; std::string category; getline(std::cin, category);

                if(type && md)
                {
                    std::cout << "Enter date mm yyyy: " << std::endl; std::tm opData; std::cin >> opData.tm_mon >> opData.tm_year;
                    wallet.getCreditCard(cardName).printMonthHistory(opData, category);
                }
                else if(!type && md)
                {
                    std::cout << "Enter date mm yyyy: " << std::endl; std::tm opData; std::cin >> opData.tm_mon >> opData.tm_year;
                    wallet.getDebitCard(cardName).printMonthHistory(opData, category);
                }
                else if(type && !md)
                {
                    std::cout << "Enter date dd mm yyyy: " << std::endl; std::tm opData; std::cin >> opData.tm_mday >> opData.tm_mon >> opData.tm_year;
                    wallet.getCreditCard(cardName).printDayHistory(opData, category);
                }
                else if(!type && !md)
                {
                    std::cout << "Enter date dd mm yyyy: " << std::endl; std::tm opData; std::cin >> opData.tm_mday >> opData.tm_mon >> opData.tm_year;
                    wallet.getDebitCard(cardName).printDayHistory(opData, category);
                }
                break;
            }
            case 7:
            {
                std::cout << "Enter Card Name : " << std::endl; std::string cardName; getline(std::cin, cardName);
                std::cout << "Credit/Debit - 1/0" << std::endl; bool type; std::cin >> type;
                std::cout << "Which category?" << std::endl; std::string category; getline(std::cin, category);


                std::cout << "Enter date mm yyyy: " << std::endl; std::tm opData; std::cin >> opData.tm_mon >> opData.tm_year;
                (type) ? wallet.getCreditCard(cardName).printTopMaxMonthSpend(opData)
                : wallet.getDebitCard(cardName).printTopMaxMonthSpend(opData);

                break;
            }
            case 8:
            {
                std::cout << "Enter File Name : " << std::endl; std::string fileName; getline(std::cin, fileName);
                wallet.saveToFileCardHistory(fileName);
                break;
            }
        }

    }
    return 0;
}
