#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Account {
public:
    Account() : owner(""), accountNumber(0), balance(0) {}

    Account(std::string owner, int accountNumber) 
        : owner(owner), accountNumber(accountNumber), balance(0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions.push_back("Deposit: $" + std::to_string(amount));
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions.push_back("Withdraw: $" + std::to_string(amount));
        } else {
            std::cout << "Invalid withdraw amount or insufficient funds." << std::endl;
        }
    }

    void transfer(Account &toAccount, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            toAccount.deposit(amount);
            transactions.push_back("Transfer: $" + std::to_string(amount) + " to Account " + std::to_string(toAccount.getAccountNumber()));
        } else {
            std::cout << "Invalid transfer amount or insufficient funds." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void printTransactionHistory() const {
        std::cout << "Transaction history for account " << accountNumber << ":" << std::endl;
        for (const auto &transaction : transactions) {
            std::cout << transaction << std::endl;
        }
    }

private:
    std::string owner;
    int accountNumber;
    double balance;
    std::vector<std::string> transactions;
};

class BankingSystem {
public:
    void createAccount(const std::string &owner) {
        int accountNumber = nextAccountNumber++;
        accounts[accountNumber] = Account(owner, accountNumber);
        std::cout << "Account created for " << owner << " with account number " << accountNumber << std::endl;
    }

    Account* getAccount(int accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            return &accounts[accountNumber];
        } else {
            std::cout << "Account not found." << std::endl;
            return nullptr;
        }
    }

private:
    std::unordered_map<int, Account> accounts;
    int nextAccountNumber = 1000;
};

void showMenu() {
    std::cout << "Banking System Menu:" << std::endl;
    std::cout << "1. Create Account" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Transfer Money" << std::endl;
    std::cout << "5. View Balance" << std::endl;
    std::cout << "6. View Transaction History" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    BankingSystem bank;
    int choice;
    std::string owner;
    int accountNumber;
    double amount;
    int toAccountNumber;

    while (true) {

        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter owner name: ";
                std::cin >> owner;
                bank.createAccount(owner);
                break;
            case 2:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                if (Account* account = bank.getAccount(accountNumber)) {
                    account->deposit(amount);
                }
                break;
            case 3:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                if (Account* account = bank.getAccount(accountNumber)) {
                    account->withdraw(amount);
                }
                break;
            case 4:
                std::cout << "Enter your account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter recipient account number: ";
                std::cin >> toAccountNumber;
                std::cout << "Enter amount to transfer: ";
                std::cin >> amount;
                if (Account* fromAccount = bank.getAccount(accountNumber)) {
                    if (Account* toAccount = bank.getAccount(toAccountNumber)) {
                        fromAccount->transfer(*toAccount, amount);
                    }
                }
                break;
            case 5:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                if (Account* account = bank.getAccount(accountNumber)) {
                    std::cout << "Balance: $" << account->getBalance() << std::endl;
                }
                break;
            case 6:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                if (Account* account = bank.getAccount(accountNumber)) {
                    account->printTransactionHistory();
                }
                break;
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << "Press any key to continue...";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}1