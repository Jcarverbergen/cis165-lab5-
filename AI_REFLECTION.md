## Tools Used

I used ChatGPT to help organize the assignment requirements, develop
the two C++ program drafts, review the compound-interest and loan
payment formulas, and plan the README documentation. I used the
assignment instructions to identify the required inputs, outputs,
test cases, and coding standards.

## One Programming Decision

One decision was to keep the calculation variables separate from the
output statements. This makes it easier to read and check each step
instead of placing complicated formulas directly inside `cout`.
I also included a separate calculation for a zero-interest loan
because the regular payment formula would otherwise divide by zero.
I need to compile and test these decisions before treating them as
verified.

## Verification

The assignment's loan test uses a $10,000 loan, a 12% annual interest
rate, and 36 monthly payments. The monthly decimal rate should be
0.01, and the monthly payment should display as approximately $332.14.
I will compile both programs using `g++ -std=c++17 -Wall -Wextra`,
run the assigned and changed-value tests, and record the actual
outputs in README.md. The compiler results and numerical comparisons
will provide evidence of verification.

## Learning and Next Steps

I learned how percentage conversion, `pow()`, and named result
variables fit into financial calculations. I also learned why
formatting output to two decimal places should not mean rounding
intermediate calculations. I still need to practice independently
checking numerical results and debugging compiler warnings. Before
submission, I will verify every test, update the test table, and
confirm that all four files are included in the public repository.
