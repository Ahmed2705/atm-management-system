#define ACCOUNT_H

#include <string>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    string nameHolder;
    double balance;
    int pin;

public:
    Account();
    Account(int accn, string nh, double initialBalance, int p);

    int getAccountNumber() const;
    std::string getNameHolder() const;
    double getBalance() const;
    int getPin() const;

    void setBalance(double newBalance);
    void withdraw(double amount);
    void deposit(double amount);

    void create(vector<Account>& accounts);
    void withdrawFrom(vector<Account>& accounts);
    void depositTo(vector<Account>& accounts);
    void transferTo(vector<Account>& accounts);
    void checkBalance(vector<Account>& accounts);

    Account* findAccount(int accn, vector<Account>& accounts);
};

