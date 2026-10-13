# cis165-lab5-
 compound_interest.cpp   loan_payment.cpp   README.md   AI_REFLECTION.md
## Overview

This lab contains two C++ programs that perform financial calculations using `double`, `pow()` from `<cmath>`, and formatted output using `<iomanip>`.

- `compound_interest.cpp` calculates compound interest and the final savings balance.
- `loan_payment.cpp` calculates monthly loan payments, the total amount paid back, and total interest paid.

Both programs use meaningful variable names, store calculations in variables before displaying them, and format monetary results to two decimal places.

## Program 1: Compound Interest

### Plan

**Inputs:**
- Principal balance
- Annual interest rate as a percentage
- Number of times interest is compounded per year

**Intermediate variables:**
- `principal`: the original savings balance
- `annual_rate`: the annual interest rate entered as a percentage
- `rate`: the annual interest rate converted to decimal form
- `times_compounded`: the number of compounding periods per year
- `amount`: the final savings balance
- `interest_earned`: the interest earned

**Steps:**
1. Ask the user to enter the principal, annual interest rate, and compounding frequency.
2. Check that the principal is positive, the rate is nonnegative, and the compounding frequency is positive.
3. Convert the annual percentage to decimal form by dividing by 100.
4. Calculate the final balance using the compound-interest formula and `pow()`.
5. Calculate the interest earned by subtracting the original principal from the final balance.
6. Display the results using `fixed`, `setprecision(2)`, and `setw()`.

**Formulas:**

`rate = annual_rate / 100.0`

`amount = principal * pow(1.0 + rate / times_compounded, times_compounded)`

`interest_earned = amount - principal`

## Program 2: Monthly Loan Payment

### Plan

**Inputs:**
- Loan amount
- Annual interest rate as a percentage
- Number of monthly payments

**Intermediate variables:**
- `loan_amount`: the original loan amount
- `annual_rate`: the annual interest rate entered as a percentage
- `monthly_rate`: the monthly interest rate in decimal form
- `monthly_rate_percent`: the monthly rate expressed as a percentage for display
- `growth_factor`: the exponentiation result
- `monthly_payment`: the required monthly payment
- `amount_paid_back`: the total amount paid over all payments
- `interest_paid`: the total interest paid
- `number_of_payments`: the number of monthly payments

**Steps:**
1. Ask the user to enter the loan amount, annual interest rate, and number of payments.
2. Check that the loan amount is positive, the rate is nonnegative, and the number of payments is positive.
3. Convert the annual percentage into a monthly decimal rate.
4. Use `pow()` to calculate the growth factor.
5. Calculate the monthly payment using the loan payment formula. If the interest rate is zero, divide the loan amount by the number of payments instead.
6. Calculate the amount paid back and the total interest paid.
7. Display the required results using `fixed`, `setprecision(2)`, and `setw()`.

**Formulas:**

`monthly_rate = annual_rate / 100.0 / 12.0`

`growth_factor = pow(1.0 + monthly_rate, number_of_payments)`

For a positive monthly rate:

`monthly_payment = loan_amount * monthly_rate * growth_factor / (growth_factor - 1.0)`

For a zero monthly rate:

`monthly_payment = loan_amount / number_of_payments`

`amount_paid_back = monthly_payment * number_of_payments`

`interest_paid = amount_paid_back - loan_amount`

## Testing

Expected monetary values are rounded to two decimal places. Actual results must be recorded after compiling and running each program.

| Program and test | Inputs | Expected results | Actual results | Match or correction |
|---|---|---|---|---|
| Compound interest — assigned | Principal: $1,000; annual rate: 4.25%; periods: 12 | Interest earned: $43.34; amount in savings: $1,043.34 |  Interest earned: $43.34; amount in savings: $1,043.34 | match |
| Compound interest — changed | Principal: $2,500; annual rate: 5.5%; periods: 4 | Interest earned: approximately $140.36; amount in savings: approximately $2,640.36 | Interest earned: approximately $140.36; amount in savings: approximately $2,640.36 | match |
| Loan payment — assigned | Loan: $10,000; annual rate: 12%; payments: 36 | Monthly rate: 1.00%; monthly payment: approximately $332.14; amount paid back: approximately $11,957.15; interest paid: approximately $1,957.15 || Monthly rate: 1.00%; monthly payment: approximately $332.14; amount paid back: approximately $11,957.15; interest paid: approximately $1,957.15 | match |
| Loan payment — changed | Loan: $5,000; annual rate: 6%; payments: 24 | Monthly rate: 0.50%; monthly payment: approximately $221.60; amount paid back: approximately $5,318.40; interest paid: approximately $318.40 |  Monthly rate: 0.50%; monthly payment: approximately $221.60; amount paid back: approximately $5,318.40; interest paid: approximately $318.40 | match |

### Testing procedure

1. Compile both C++ programs using the commands in the next section.
2. Run the compound-interest program with the assigned inputs.
3. Run it again with the changed inputs.
4. Run the loan-payment program with the assigned inputs.
5. Run it again with the changed inputs.
6. Compare the actual output with the expected results.
7. Update the Actual results and Match or correction columns with the results of your tests.

If any result differs, check the formula, percentage conversion, input values, and calculations before recording a correction.

## Compiling and Running the Programs

A C++ compiler such as `g++` is required. Open a terminal in the directory containing the source files.

### Compile the compound-interest program

```bash
g++ -std=c++17 -Wall -Wextra compound_interest.cpp -o compound_interest
```

### Run the compound-interest program

```bash
./compound_interest
```

### Compile the loan-payment program

```bash
g++ -std=c++17 -Wall -Wextra loan_payment.cpp -o loan_payment
```

### Run the loan-payment program

```bash
./loan_payment
```

On Windows, the executable names may end in `.exe`. For example, use `compound_interest.exe` and `loan_payment.exe`.

## Code Understanding Questions

### 1. Why must a percentage be divided by 100 before using it in a formula?

A percentage means an amount out of 100. Dividing by 100 converts the percentage into decimal form so it can be used in calculations. For example, 4.25% becomes 0.0425.

### 2. How does `pow()` represent exponentiation?

The `pow()` function from `<cmath>` raises a base number to a specified power. For example, `pow(1.01, 12)` calculates 1.01 raised to the twelfth power. This is useful when interest compounds over multiple periods.

### 3. What does the number of compounding periods change in the savings formula?

The number of compounding periods determines how many times interest is added to the balance during the year. With a positive annual rate, more frequent compounding generally produces a higher final balance because interest is added more often.

### 4. How is an annual interest rate converted to a monthly rate?

First, divide the annual percentage rate by 100 to convert it to decimal form. Then divide by 12 to obtain the monthly decimal rate. For example, an annual rate of 12% becomes 0.01 per month.

### 5. Why should `double` be used for these calculations?

The `double` data type supports decimal values and provides more precision than an integer. Interest rates, account balances, and loan payments can contain fractional amounts, so using integers would cause problems with these calculations.

### 6. Why should calculations use full precision when money is displayed to two decimal places?

Rounding intermediate calculations can introduce errors that affect later results. Keeping full precision during calculations helps make the results more accurate. `fixed` and `setprecision(2)` control how monetary values are displayed without requiring intermediate results to be rounded.

### 7. How are the amount paid back and total interest calculated?

The amount paid back is calculated by multiplying the monthly payment by the number of monthly payments. The total interest is calculated by subtracting the original loan amount from the amount paid back.

### 8. Why are calculations stored in variables before being displayed?

Storing calculations in variables makes the program easier to read, test, debug, and maintain. It also separates the calculation logic from the output statements and makes it easier to check intermediate results.

## Repository Contents

The public GitHub repository named `cis165-lab5` must contain these four files at the top level:

- `compound_interest.cpp`
- `loan_payment.cpp`
- `README.md`
- `AI_REFLECTION.md`

Before submitting, compile and run both programs, complete all four test records, and commit all four files.

Finally, open the repository and final commit while signed out of GitHub to confirm that they are publicly accessible.

## Submission Information

Course section: CIS-165-W099

Repository URL: https://github.com/YOUR-USERNAME/cis165-lab5

Final commit URL: https://github.com/YOUR-USERNAME/cis165-lab5/commit/FULL-COMMIT-SHA

Replace the placeholders with your actual GitHub username and full commit SHA before submitting in Canvas.
