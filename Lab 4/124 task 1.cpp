#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    int acc_number;
    string name;
    string type;
    double curr_balance;
    double min_balance;

public:
    BankAccount(int num, string Name, string Type, double curr, double min):
        acc_number(num), name(Name), type(Type), curr_balance(curr), min_balance(min)
        {}

    void set_account_number(int number)
    {
        acc_number = number;
    }        

    void set_account_name(string Name)
    {
        name = Name;
    }

    void set_type(string Type)
    {
        type = Type;
    }

    void set_current_balance(double curr)
    {
        curr_balance = curr;
    }

    void set_minimum_balance(double min)
    {
        min_balance = min;
    }

    void show()
    {
        cout << "Account Number: " << acc_number << endl
            << "Account Holder Name: " << name << endl 
            << "Account Type: " << type << endl
            << "Account Balance: " << curr_balance << endl
            << "Minimum Balance: " << min_balance << endl;
    }

    void showBalance()
    {
        cout << "Current Balance: " << curr_balance << endl;
    }

    void deposit(int amount)
    {
        curr_balance += amount;
    }

    void withdrawal(int amount)
    {
        if (curr_balance - amount < min_balance)
            cout << "Cannnot withdraw. Exceeds minimum required balance.\n";
        else curr_balance -= amount;
    }

    void giveInterest(double rate = .03)
    {
        curr_balance += (curr_balance * rate) - (curr_balance * rate * 0.1);
    }

    ~BankAccount()
    {
        cout << "Account of " << name << " with account no " << acc_number
            << " is destroyed with a balance BDT " << curr_balance << endl;
    }
};

int main()
{
    BankAccount demo(1234, "Yes", "Savings", 50000, 5000);
    
}