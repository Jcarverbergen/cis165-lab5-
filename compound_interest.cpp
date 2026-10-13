#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double principal;
    double annual_rate;
    double rate;
    double amount;
    double interest_earned;
    int times_compounded;

    cout << "Enter the principal balance: $";
    cin >> principal;

    cout << "Enter the annual interest rate (%): ";
    cin >> annual_rate;

    cout << "Enter the number of times interest is compounded per year: ";
    cin >> times_compounded;

    if (!cin || principal <= 0.0 || annual_rate < 0.0
        || times_compounded <= 0) {
        cout << "Invalid input. Enter a positive principal, a nonnegative "
             << "rate, and a positive compounding frequency.\n";
        return 1;
    }

    rate = annual_rate / 100.0;

    amount = principal
             * pow(1.0 + rate / times_compounded, times_compounded);

    interest_earned = amount - principal;

    cout << fixed << setprecision(2);

    cout << "\n       COMPOUND INTEREST REPORT\n";
    cout << "--------------------------------------\n";
    cout << left << setw(25) << "Annual interest rate:"
         << right << setw(12) << annual_rate << "%\n";
    cout << left << setw(25) << "Times compounded:"
         << right << setw(12) << times_compounded << '\n';
    cout << left << setw(25) << "Principal:"
         << right << "$" << setw(11) << principal << '\n';
    cout << left << setw(25) << "Interest earned:"
         << right << "$" << setw(11) << interest_earned << '\n';
    cout << left << setw(25) << "Amount in savings:"
         << right << "$" << setw(11) << amount << '\n';

    return 0;
}
