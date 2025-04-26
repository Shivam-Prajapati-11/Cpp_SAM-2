/*A community bank sought to enhance its account management system with a digital solution to
improve efficiency and provide better customer service. The system was required to manage the
essential details of each account, including the account number, account holder’s name, and balance.
Additionally, the bank wanted to provide a secure mechanism for transferring money between
accounts, allowing customers to easily manage their funds.
The bank also needed a way to track the total number of accounts created, which would be important
for generating reports and understanding the growth of their customer base. This feature was aimed
at helping the bank maintain an overview of their account portfolio and analyze trends over time.
To ensure smooth and reliable operations, the system was designed to store account information in a
way that would allow easy access and updates. When new accounts were created, they would be
added to the system dynamically. The management team planned for future scalability and
performance improvements by considering more efficient storage and retrieval methods after the
initial system was built, ensuring that the bank could easily accommodate more accounts and
transactions as the customer base grew.*/

#include <iostream>
#include <vector>

using namespace std;

class bank //Create class of bank
{
private:
    int account_number;
    string account_name;
    double balance;
    static int count;

public:
    bank(int num, string name, double bal) //Parameterized Constructor
    {
        account_number = num;
        account_name = name;
        balance = bal;
        count++;
    }
    void details() //Before deposit display details
    {
        cout <<endl << "Account Number: " << account_number << endl;
        cout << "Account Holder Name: " << account_name << endl;
        cout << "Initial Balance: " << balance << endl;
    }
    void deposite(double d)
    {
        balance += d;
        cout <<endl << "Deposite in account 1: " << balance << endl;
    }
    void withdraw(double w)
    {
        if (balance > w)
        {
            balance -= w;
            cout << "Withdraw in account 2: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!!" << endl;
        }
    }
    void display() //After deposit display details
    { 
        cout<<"Account Name : "<<account_name<<endl; 
        cout<<"Account Number : "<<account_number<<endl; 
        cout<<"Account Total Balance : "<<balance<<endl<<endl; 
    } 
    static int get_count()
    {
        return count;
    }

    friend void transfer_money(bank &from, bank &to, double amount); 
};

int bank ::count = 0;

void transfer_money(bank &account1, bank &account2, double amount) //Function that transfer money to one account to anonther account
{
    account1.balance -= amount;
    account2.balance += amount;
    cout << endl << "Transferred " << amount << " from account 1 to account 2" << endl;
    cout << "Deposited in account 1 to account 2: " << account2.balance << endl;
}

int main()
{
    // Create two bank account objects
    bank account_1(1234, "Shivam Prajapati", 1000);
    bank account_2(7777, "Yash Gajera", 4000);

    cout << "<--------------Account 1 Details------------>" << endl;
    account_1.details();

    cout << "<--------------Account 2 Details------------>" << endl;
    account_2.details();

    //Perform transections
    account_1.deposite(100);
    account_2.withdraw(50);

    transfer_money(account_1, account_2, 100); // Transfer money from account 1 to account 2

    cout << "<---------------Account 1-------------->" << endl;
    account_1.display();

    cout << "<---------------Account 2-------------->" << endl;
    account_2.display();

    cout << "Total Account: " << bank::get_count() << endl; // Show total number of accounts created

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
