#include <iostream>
#include <stack>
using namespace std;

class Bankaccount
{
    string account_number;
    double balance;

public:
    Bankaccount(string acc, double bal) : account_number(acc), balance(bal) {}

    void deposit(double amt)
    {
        balance += amt;
        cout << "Deposited: " << amt << ",Balance: " << balance << endl;
    }
    int withdraw(double amt)
    {
        if (balance >= amt)
        {
            balance -= amt;
            cout << "Withrawn: " << amt << ",Balance: " << balance << endl;
            return 1;
        }
        else
        {
            cout << "Insufficient balance!!!" << endl;
        }
    }
    string get_account_number() const
    {
        return account_number;
    }

    double get_balance() const
    {
        return balance;
    }
};
class savingaccount : public Bankaccount
{
public:
    savingaccount(string acc, double bal) : Bankaccount(acc, bal) {}
};
class currentaccount : public Bankaccount
{
    double overdraft_limit;

public:
    currentaccount(string acc, double bal, double limit) : Bankaccount(acc, bal), overdraft_limit(limit) {}

    int withdraw(double amt)
    {
        if (get_balance() + overdraft_limit >= amt)
        {
            double new_balance = get_balance() - amt;
            cout << "Withdrawn: " << amt << ", Balance: " << new_balance << endl;
            return 1;
        }
        else
        {
            cout << "Overdraft limit exceeded!!!" << endl;
            return 0;
        }
    }
    double get_oveerdraft_limit() const
    {
        return overdraft_limit;
    }
};
struct Transaction
{
    string type;
    double amt;
};
void show()
{
    cout << "\n1.Deposit\n2.Withdraw\n3.Undo\n4.Show Balance\n0.Exit\n\n";
}

int main()
{
    string type, accno;
    double bal;

    cout << "Account type(Saving or Current): ";
    cin >> type;
    cout << "Account Number: ";
    cin >> accno;
    cout << "Intial Balance: ";
    cin >> bal;
    cout << "\nHello " << accno << endl
         << "Please Press:" << endl;

    stack<Transaction> history;
    int choose;
    double amt;

    if (type == "Saving")
    {
        savingaccount acc(accno, bal);

        do
        {
            show();
            cin >> choose;

            switch (choose)
            {
            case 1:
                cout << "Amount: ";
                cin >> amt;
                acc.deposit(amt);
                history.push({"Deposit", amt});
                break;
            case 2:
                cout << "Amount: ";
                cin >> amt;
                if (acc.withdraw(amt) == 1)
                {
                    history.push({"Withraw", amt});
                }
                break;
            case 3:
                if (!history.empty())
                {
                    Transaction last = history.top();
                    history.pop();
                    cout << "Undoing: " << last.type << " of " << last.amt << endl;
                    if (last.type == "Deposit")
                    {
                        acc.withdraw(last.amt);
                    }
                    else
                    {
                        acc.deposit(last.amt);
                    }
                }
                else
                {
                    cout << "No,Transaction to undo!!" << endl;
                }
                break;
            case 4:
                cout << "Balance: " << acc.get_balance() << endl;
                break;
            }
        } while (choose != 0);
    }
    else if (type == "Current")
    {
        double limit;
        cout << "Overdraft limit: ";
        cin >> limit;
        currentaccount acc(accno, bal, limit);

        do
        {
            show();
            cin >> choose;

            switch (choose)
            {
            case 1:
                cout << "Amount: ";
                cin >> amt;
                acc.deposit(amt);
                history.push({"Deposit", amt});
                break;
            case 2:
                cout << "Amount: ";
                cin >> amt;
                if (acc.withdraw(amt) == 1)
                {
                    history.push({"Withdraw", amt});
                }
                break;
            case 3:
                if (!history.empty())
                {
                    Transaction last = history.top();
                    acc.withdraw(last.amt);
                    history.pop();
                    cout << "Undoing: " << last.type << " of " << last.amt << endl;

                    if (last.type == "Deposit")
                    {
                        if (acc.get_balance() - last.amt >= -acc.get_oveerdraft_limit())
                        {
                            acc.withdraw(last.amt);
                            history.pop();
                            cout << "Undoing deposit of " << last.amt << endl;
                        }
                        else
                        {
                            cout << "Can't undo deposit - overdraft will be exceeded!!" << endl;
                        }
                    }
                    else
                    {
                        acc.deposit(last.amt);
                        history.pop();
                        cout << "Undoing withdrawal of " << last.amt << endl;
                    }
                }
                else
                {
                    cout << "No transaction to undo\n";
                }
                break;

            case 4:
                cout << "Balance: " << acc.get_balance() << endl;
                break;
            }
        } while (choose != 0);
    }
    else
    {
        cout << "Invalid amount type!!!" << endl;
    }

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
