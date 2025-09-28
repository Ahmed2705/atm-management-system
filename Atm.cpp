#include <iostream>
#include  "Atm.h"
using namespace std;


Account::Account() : accountNumber(0), nameHolder(""), balance(0.0), pin(0) {}

Account::Account(int accn, string nh, double initialBalance, int p) {
    accountNumber = accn;
    nameHolder = nh;
    balance = initialBalance;
    pin = p;
}

int Account::getAccountNumber() const { return accountNumber; }
string Account::getNameHolder() const { return nameHolder; }
double Account::getBalance() const { return balance; }
int Account::getPin() const { return pin; }
void Account::setBalance(double newBalance) { balance = newBalance; }

void Account::withdraw(double amount) { balance -= amount; }
void Account::deposit(double amount) { balance += amount; }

Account* Account::findAccount(int accn, vector<Account>& accounts) {
    for (auto& acc : accounts) {
        if (acc.accountNumber == accn) return &acc;
    }
    return nullptr;
}

void Account::create(vector<Account>& accounts) {
    int accn, pin1, pin2;
    double bal;
    string name;

    cout << "Enter account number: ";
    cin >> accn;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter initial balance: ";
    cin >> bal;

    do {
        cout << "Enter PIN: ";
        cin >> pin1;
        cout << "Re-enter PIN: ";
        cin >> pin2;
        if (pin1 != pin2) {
            cout << "PINs do not match, try again.\n";
        }
    } while (pin1 != pin2);

    accounts.emplace_back(accn, name, bal, pin1);
    cout << "Account created successfully.\n";
}

void Account::withdrawFrom(vector<Account>& accounts) {
    int accn, pin;
    double amt;

    cout << "Enter account number: ";
    cin >> accn;
    Account* acc = findAccount(accn, accounts);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter PIN: ";
    cin >> pin;
    if (pin != acc->pin) {
        cout << "Incorrect PIN.\n";
        return;
    }

    cout << "Enter amount to withdraw: ";
    cin >> amt;

    if (amt > acc->balance) {
        cout << "Insufficient balance.\n";
    }
    else {
        acc->withdraw(amt);
        cout << "Withdrawn. New balance: " << acc->balance << endl;
    }
}

void Account::depositTo(vector<Account>& accounts) {
    int accn, pin;
    double amt;

    cout << "Enter account number: ";
    cin >> accn;
    Account* acc = findAccount(accn, accounts);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter PIN: ";
    cin >> pin;
    if (pin != acc->pin) {
        cout << "Incorrect PIN.\n";
        return;
    }

    cout << "Enter amount to deposit: ";
    cin >> amt;
    acc->deposit(amt);
    cout << "Deposited. New balance: " << acc->balance << endl;
}

void Account::transferTo(vector<Account>& accounts) {
    int senderAcc, receiverAcc;
    double amt;

    cout << "Enter sender account number: ";
    cin >> senderAcc;
    Account* sender = findAccount(senderAcc, accounts);
    if (!sender) {
        cout << "Sender account not found.\n";
        return;
    }

    cout << "Enter PIN: ";
    int pin;
    cin >> pin;
    if (pin != sender->pin) {
        cout << "Incorrect PIN.\n";
        return;
    }

    cout << "Enter receiver account number: ";
    cin >> receiverAcc;
    Account* receiver = findAccount(receiverAcc, accounts);
    if (!receiver) {
        cout << "Receiver account not found.\n";
        return;
    }

    cout << "Enter amount to transfer: ";
    cin >> amt;

    if (amt > sender->balance) {
        cout << "Insufficient funds.\n";
        return;
    }

    sender->withdraw(amt);
    receiver->deposit(amt);
    cout << "Transfer successful.\n";
}

void Account::checkBalance(vector<Account>& accounts) {
    int accn, pin;
    cout << "Enter account number: ";
    cin >> accn;
    Account* acc = findAccount(accn, accounts);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter PIN: ";
    cin >> pin;
    if (pin != acc->pin) {
        cout << "Incorrect PIN.\n";
        return;
    }

    cout << "Your balance is: " << acc->balance << endl;
}