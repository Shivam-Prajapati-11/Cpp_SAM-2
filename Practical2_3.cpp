/*In a growing city, a newly established bank sought to streamline its operations by implementing a
digital system to manage customer accounts. The management envisioned a system where each
account would store details about the account holder, their unique account number, and the current
balance. To ensure flexibility and accuracy, they required functionalities for creating accounts with
varying initial balances, depositing money, withdrawing funds (with checks for sufficient balance), and
generating detailed account summaries.
The bank's IT team faced the challenge of developing a robust solution. They began by sketching out
the essential features of the system. The team highlighted that new accounts could be created in two
ways: one with no initial balance, and another with specified account details and a starting amount.
Additionally, they recognized the need for reliable mechanisms to handle deposits and withdrawals,
ensuring proper validation to prevent overdrafts. Displaying account details in a clear format was also
prioritized for customer communication.
To ensure scalability, the team decided to simulate the system by creating multiple accounts using the
proposed methods. They tested various scenarios, such as depositing and withdrawing different
amounts, handling edge cases like insufficient funds, and verifying that the account summaries were
accurate. This iterative approach helped them refine the system and ensure its readiness for
deployment.*/

#include <iostream>

using namespace std;

class Bank //Create a class of bank
{
    string name;
    int account_number;
    int balance;

public:
    Bank() //Default constructor called
    {
        name = "N/A";
        account_number = 000000;
        balance = 0;
    }
    Bank(string n, int an, int b) //Parametrized constructor called
    {
        name = n;
        account_number = an;
        balance = b;
    }
    void deposit(int d)
    {
        balance += d;
        cout <<"Deposited " << d << endl;
    }
    void withdraw(int d)
    {
        if (balance < d)
        {
            cout << "Sorry!!, Your current balance less" << endl
                 << "Current Balance: " << balance << endl;
        }
        else
        {
            balance -= d;
            cout << "Withdraw: " << d << endl;
            cout << "Money Withdrawed!!" << endl;
            cout << "Current Balance: " << balance << endl;
        }
    }
    void display_account_details() //Displaying account details
    {
        cout << "Account Holder Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Bank Balance: " << balance << endl;
        deposit(4000);
        withdraw(1000);
    }
};

int main()
{
    Bank a[2]; //create 2 object of bank

    cout << "Enter your information About your Bank Account" << endl;
    for (int i = 0; i < 2; i++) //Using for loop to ask user for input
    {
        string n;
        int an, b;
        cout << "Account " << i + 1 << ": " << endl;
        cout << "Enter account Holder Name: ";
        cin >> n;
        cout << "Enter Account Number: ";
        cin >> an;
        cout << "Enter Bank Balance: ";
        cin >> b;
        a[i] = Bank(n, an, b);
    }

    cout << "Bank account Details: " << endl;
    for (int i = 0; i < 2; i++) //This for loop will display details
    {

        cout << "<------------Account " << i + 1 << ": ------------>" << endl;
        a[i].display_account_details();
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
