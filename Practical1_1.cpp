/*A bank wants to create a simple system to manage customer bank accounts. The system should
allow customers to perform basic banking operations such as depositing money, withdrawing
money, and checking their account balance.
Each bank account will need to have an account holder's name, a unique account number, and
a balance. Deposits should increase the account balance, while withdrawals should only be
allowed if there are sufficient funds in the account. If an attempt is made to withdraw more
money than is available, an error message should be displayed. Customers should also have the
ability to view their account balance whenever required.
The system must be designed using Object-Oriented Programming principles, focusing on
creating a simple and efficient solution to manage the accounts effectively. The system should
ensure that all account details are secure and accessible only through authorized methods. */

#include <iostream>

using namespace std;

//create bankaccount class
class bankaccount
{
private:
    string name;
    double number;
    float balance;

public:
    void details();
    void deposit();
    void withdraw();
    void display_balance();
};
void bankaccount ::details() //function that take input from user for details
{
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your account number:";
    cin >> number;
    cout << "Enter your bank balance:";
    cin >> balance;
}
void bankaccount ::deposit() // Function to deposit money into the account
{
    long int add;
    cout << endl;
    cout << "How much money you want to store?? :" << endl;
    cin >> add;
    balance += add;
    cout << "Thank you!!" << endl;
}
void bankaccount ::withdraw() // Function to withdraw money from the account
{
    long int balance_gone;
    cout << endl;
    cout << "How much money you want to withdraw??:";
    cin >> balance_gone;

    if (balance_gone > balance)  // Check if sufficient balance is available of not
    {
        cout << "Error!" << endl;
    }
    else
    {
        balance -= balance_gone;
        cout << "Withdraw succesfully!!" << endl;
    }
}
void bankaccount ::display_balance() //Function to display details and balance 
{
    cout << endl;
    cout << "Account Holder Name: " << name << endl;
    cout << "Account Number: " << number << endl;
    cout << "Your current balance is :" << balance;
}

int main()
{
    bankaccount a1; //create an object of bankacciunt class 
    a1.details();
    a1.deposit();
    a1.withdraw();
    a1.display_balance();

    cout << "\n\n24CE098_Shivam Prajapati\n\n";

    return 0;
}
