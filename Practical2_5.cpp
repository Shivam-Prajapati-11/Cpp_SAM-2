/*A regional banking institution sought to improve its loan management process by developing a system
that could efficiently handle loan details for applicants. The system was expected to streamline the
calculation of monthly EMIs (Equated Monthly Instalments) and provide detailed loan summaries for
customers. This initiative aimed to enhance customer experience by offering accurate and transparent
information about their loans.

To meet these requirements, the bank's technology team was tasked with designing a solution. They
envisioned a system where each loan would be uniquely identified by a loan ID, and additional details
such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months
would be stored. The team also emphasized the importance of accurately calculating the EMI using a
standard formula based on the loan amount, interest rate, and tenure. The formula incorporated
compound interest principles to determine the fixed monthly payment for the loan term.

EMI=
P ∗ R ∗ (1 + R)^T
((1+R)^T) −1

As part of the implementation, the developers planned to initialize loans either with default values for
testing purposes or with actual customer data provided at the time of application. The system needed

to include a feature to display comprehensive loan details, including the calculated EMI, in a customer-
friendly format. This functionality was intended to aid both customers and bank staff in managing

loan-related queries effectively.*/

#include <iostream>
#include <cmath>

using namespace std;

class bank_loan //Create class of bank loan
{
    int loanID;
    string applicantName;
    float loanAmount;
    float interestRate;
    int loanTerm;

public:
    // Default Counstructor
    bank_loan()
    {
        loanID = 0,
        applicantName = "N/A",
        loanAmount = 0.0,
        interestRate = 0.0,
        loanTerm = 0;
    }
    // Parameter Counstructor
    bank_loan(int ID, string n, float a, float R, int t)
    {
        loanID = ID;
        applicantName = n;
        loanAmount = a;
        interestRate = R;
        loanTerm = t;
    }
    void display_details() // Funtion that display details
    {
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Loan Term: " << loanTerm << endl;
    }
    void calculateEMI() //Function that calculate EMI
    {
        float monthlyrate = (interestRate / 12) / 100;
        float EMI = (loanAmount * monthlyrate * pow(1 + monthlyrate, loanTerm)) / (pow(1 + monthlyrate, loanTerm) - 1);

        cout << "Monthly EMI: " << EMI << endl;
    }
};

int main()
{
    int id;
    string name;
    float amount, rate;
    int term;

    //Ask User for details about bank loan
    cout << "Enter Loan id: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter loan amount: ";
    cin >> amount;

    cout << "Enter annual interest rate: ";
    cin >> rate;

    cout << "Enter loan term(in month): ";
    cin >> term;

    // Loan object using parameterized constructor
    bank_loan loan(id, name, amount, rate, term);

    // Displaying loan details
    cout << "----------Loan Details------------" << endl;
    loan.display_details();
    loan.calculateEMI();

    cout << "\n\n24CE098_Shivam Prajapati\n\n";
    return 0;
}
