/*Abstraction means displaying only essential information and hides the details of implementation

Types of abstraction 
    1. Data abstraction 
    2. control abstraction -> only show required information about implementation */


#include <iostream>
#include <string>
using namespace std;

// Abstract class
class BankAccount 
{
protected:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initialBalance) 
        : accountHolder(name), balance(initialBalance) 
        {

        }

    // Pure virtual function for depositing money
    virtual void deposit(double amount) = 0;

    // Pure virtual function for withdrawing money
    virtual void withdraw(double amount) = 0;

    // Function to display account details
    virtual void display() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Virtual destructor
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount 
{
public:
    SavingsAccount(string name, double initialBalance) 
        : BankAccount(name, initialBalance) 
        {

        }

    void deposit(double amount) override 
    {
        balance += amount; // Add amount to balance
        cout << "Deposited $" << amount << " to Savings Account." << endl;
    }

    void withdraw(double amount) override 
    {
        if (amount <= balance) 
        {
            balance -= amount; // Subtract amount from balance
            cout << "Withdrew $" << amount << " from Savings Account." << endl;
        } 
        else 
        {
            cout << "Insufficient funds in Savings Account." << endl;
        }
    }
};

class CheckingAccount : public BankAccount 
{
public:
    CheckingAccount(string name, double initialBalance) 
        : BankAccount(name, initialBalance) 
        {

        }

    void deposit(double amount) override 
    {
        balance += amount; // Add amount to balance
        cout << "Deposited $" << amount << " to Checking Account." << endl;
    }

    void withdraw(double amount) override 
    {
        if (amount <= balance) 
        {
            balance -= amount; // Subtract amount from balance
            cout << "Withdrew $" << amount << " from Checking Account." << endl;
        } 
        else 
        {
            cout << "Insufficient funds in Checking Account." << endl;
        }
    }
};


int main() 
{
    BankAccount* savings = new SavingsAccount("Alice", 1000.0);
    BankAccount* checking = new CheckingAccount("Bob", 500.0);

    savings->display();
    checking->display();

    savings->deposit(200);
    savings->withdraw(150);
    savings->display();

    checking->deposit(300);
    checking->withdraw(600); // Should show insufficient funds
    checking->display();

    // Clean up
    delete savings;
    delete checking;

    return 0;
}