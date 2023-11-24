#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account {
    public:
        string accountNumber;
        string accountHolder;
        double balance;
        Account(string x, string y, double z){
            accountNumber = x;
            accountHolder = y;
            balance = z;
        }
        void displayDetails() const {
            cout << "Account Details for Account (ID: " << accountNumber << "):" << endl;
            cout << " Holder: " << accountHolder << endl;
            cout << fixed << setprecision(2);
            cout << " Balance: $" << balance << endl;
        }
        void deposit(double amount){
            if (amount > 0) balance = balance + amount;
            else cout << "Must deposit positive money." << endl;
        }
        void withdraw(double amount){
            if (balance >= amount && amount >= 0) balance = balance - amount;
            else cout << "Amount requested not in account, or requested invalid amount." << endl;
        }
        Account operator+(Account &other) const {
            Account result = *this;
            result.balance += other.balance;
            other.balance -= other.balance;
            return result;
        }
        friend ostream& operator<<(ostream& os, const Account& account) {
            account.displayDetails();
            return os;
    }
};

class SavingsAccount : public Account {
    public: 
        double interestRate;
        SavingsAccount(string x, string y, double z, double a) : Account(x,y,z), interestRate(a) {}
        void displayDetails() const {
            cout << "Account Details for Savings Account (ID: " << accountNumber << "):" << endl;
            cout << " Holder: " << accountHolder << endl;
            cout << fixed << setprecision(2);
            cout << " Balance: $" << balance << endl;
            cout << " Interest Rate: " << 100*interestRate << "%" << endl;
        }
        SavingsAccount operator+(Account &other) const {
            SavingsAccount result = *this;
            result.balance += other.balance;
            other.balance -= other.balance;
            return result;
        }
        friend ostream& operator<<(ostream& os, const SavingsAccount& account) {
            account.displayDetails();
            return os;
        }
};

class CurrentAccount : public Account {
    public:
        double overdraftLimit;
        CurrentAccount(string x, string y, double z, double a) : Account(x, y, z), overdraftLimit(a) {}
        void displayDetails() const {
            cout << "Account Details for Savings Account (ID: " << accountNumber << "):" << endl;
            cout << " Holder: " << accountHolder << endl;
            cout << fixed << setprecision(2);
            cout << " Balance: $" << balance << endl;
            cout << " Overdraft Limit: " << overdraftLimit << endl;
        }
        void withdraw(double amount){
            if (balance - amount >= -1*overdraftLimit) balance = balance - amount;
            else cout << "Withdrawl value too high, or invalid withdrawl amount." << endl;
        }
        CurrentAccount operator+(Account &other) const {
            CurrentAccount result = *this;
            result.balance += other.balance;
            other.balance -= other.balance;
            return result;
        }
        friend ostream& operator<<(ostream& os, const CurrentAccount& account) {
            account.displayDetails();
            return os;
        }
};




int main() {
    SavingsAccount saving("A123", "Benjamin Kozlowski", 500, 0.04);
    CurrentAccount current("C672", "Jameson Lameson", 100, 300);
    cout << saving;
    cout << current;
    saving.deposit(3000);
    current.withdraw(50);
    cout << "Details after withdrawl and deposit" << endl;
    cout << saving;
    cout << current;
    SavingsAccount saving2 = saving + current;
    cout << "Details after transferring all money from current to savings" << endl;
    cout << saving2;
    cout << current;
    return 0;
}
