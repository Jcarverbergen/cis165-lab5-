#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double loan_amount;
    double annual_rate;
    double monthly_rate;
    double monthly_rate_percent;
    double growth_factor;
    double monthly_payment;
    double amount_paid_back;
    double interest_paid;
    int number_of_payments;

    cout << "Enter the loan amount: $";
    cin >> loan_amount;

    cout << "Enter the annual interest rate (%): ";
    cin >> annual_rate;

    cout << "Enter the number of monthly payments: ";
    cin >> number_of_payments;

    if (!cin || loan_amount <= 0.0 || annual_rate < 0.0
        || number_of_payments <= 0) {
        cout << "Invalid input. Enter a positive loan amount, a "
             << "nonnegative rate, and a positive number of payments.\n";
        return 1;
    }

    monthly_rate = annual_rate / 100.0 / 12.0;
    monthly_rate_percent = monthly_rate * 100.0;

    growth_factor = pow(1.0 + monthly_rate, number_of_payments);

    if (monthly_rate == 0.0) {
        monthly_payment = loan_amount / number_of_payments;
    } else {
        monthly_payment = loan_amount * monthly_rate * growth_factor
                          / (growth_factor - 1.0);
    }

    amount_paid_back = monthly_payment * number_of_payments;
    interest_paid = amount_paid_back - loan_amount;

    cout << fixed << setprecision(2);

    cout << "\n          LOAN PAYMENT REPORT\n";
    cout << "--------------------------------------\n";
    cout << left << setw(25) << "Loan amount:"
         << right << "$" << setw(11) << loan_amount << '\n';
    cout << left << setw(25) << "Monthly interest rate:"
         << right << setw(11) << monthly_rate_percent << "%\n";
    cout << left << setw(25) << "Number of payments:"
         << right << setw(12) << number_of_payments << '\n';
    cout << left << setw(25) << "Monthly payment:"
         << right << "$" << setw(11) << monthly_payment << '\n';
    cout << left << setw(25) << "Amount paid back:"
         << right << "$" << setw(11) << amount_paid_back << '\n';
    cout << left << setw(25) << "Interest paid:"
         << right << "$" << setw(11) << interest_paid << '\n';

    return 0;
}
