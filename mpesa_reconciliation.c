#include <stdio.h>
#include <math.h>

int main()
{
    /* A. Initialise the balances */

    float cashBalance = 90000.0;
    float electronicFloat = 110000.0;

    float customerDeposits = 75500.0;
    float customerWithdrawals = 62300.0;

    float cashOperatingExpenses = 2000.0;

    float floatPurchase = 20000.0;
    float floatPurchaseFee = 200.0;

    float commission = 1850.0;

    float actualClosingCash = 80800.0;
    float actualClosingFloat = 118700.0;

    float permittedDifference = 100.0;

    /* B. Process daily transactions */

    /* 1. Customer deposits */
    cashBalance += customerDeposits;
    electronicFloat -= customerDeposits;

    printf("After Customer Deposits\n");
    printf("Cash Balance: %.2f\n", cashBalance);
    printf("Electronic Float: %.2f\n\n", electronicFloat);

    /* 2. Customer withdrawals */
    cashBalance -= customerWithdrawals;
    electronicFloat += customerWithdrawals;

    printf("After Customer Withdrawals\n");
    printf("Cash Balance: %.2f\n", cashBalance);
    printf("Electronic Float: %.2f\n\n", electronicFloat);

    /* 3. Deduct cash operating expenses */
    cashBalance -= cashOperatingExpenses;

    printf("After Operating Expenses\n");
    printf("Cash Balance: %.2f\n", cashBalance);
    printf("Electronic Float: %.2f\n\n", electronicFloat);

    /* 4. Purchase additional electronic float */
    cashBalance -= floatPurchase;
    electronicFloat += floatPurchase;

    printf("After Purchasing Float\n");
    printf("Cash Balance: %.2f\n", cashBalance);
    printf("Electronic Float: %.2f\n\n", electronicFloat);

    /* 5. Deduct float purchase fee */
    cashBalance -= floatPurchaseFee;

    printf("After Float Purchase Fee\n");
    printf("Cash Balance: %.2f\n", cashBalance);
    printf("Electronic Float: %.2f\n\n", electronicFloat);

    /* 6. Add commission to electronic float */
    electronicFloat += commission;

    printf("After Commission\n");
    printf("Cash Balance: %.2f\n", cashBalance);
    printf("Electronic Float: %.2f\n\n", electronicFloat);

    /* C. Reconciliation calculations */

    float totalCustomerTransactions;
    totalCustomerTransactions = customerDeposits + customerWithdrawals;

    float expectedClosingCash;
    expectedClosingCash = cashBalance;

    float expectedClosingFloat;
    expectedClosingFloat = electronicFloat;

    float cashDiscrepancy;
    cashDiscrepancy = actualClosingCash - expectedClosingCash;

    float floatDiscrepancy;
    floatDiscrepancy = actualClosingFloat - expectedClosingFloat;

    float expectedWorkingCapital;
    expectedWorkingCapital = expectedClosingCash + expectedClosingFloat;

    float actualWorkingCapital;
    actualWorkingCapital = actualClosingCash + actualClosingFloat;

    float workingCapitalDiscrepancy;
    workingCapitalDiscrepancy = actualWorkingCapital - expectedWorkingCapital;

    printf("========== RECONCILIATION ==========\n");
    printf("Total Customer Transactions: %.2f\n", totalCustomerTransactions);
    printf("Expected Closing Cash: %.2f\n", expectedClosingCash);
    printf("Expected Closing Electronic Float: %.2f\n", expectedClosingFloat);
    printf("Cash Discrepancy: %.2f\n", cashDiscrepancy);
    printf("Electronic Float Discrepancy: %.2f\n", floatDiscrepancy);
    printf("Expected Working Capital: %.2f\n", expectedWorkingCapital);
    printf("Actual Working Capital: %.2f\n", actualWorkingCapital);
    printf("Overall Working Capital Discrepancy: %.2f\n\n", workingCapitalDiscrepancy);

    /* D. Reconciliation tests */

    int cashExactlyZero;
    cashExactlyZero = (cashDiscrepancy == 0);

    int floatExactlyZero;
    floatExactlyZero = (floatDiscrepancy == 0);

    int cashWithinLimit;
    cashWithinLimit = (fabs(cashDiscrepancy) <= permittedDifference);

    int floatWithinLimit;
    floatWithinLimit = (fabs(floatDiscrepancy) <= permittedDifference);

    int bothWithinLimit;
    bothWithinLimit = cashWithinLimit && floatWithinLimit;

    int eitherShortage;
    eitherShortage = (cashDiscrepancy < 0) || (floatDiscrepancy < 0);

    int bothBalancesPositive;
    bothBalancesPositive = (actualClosingCash > 0) && (actualClosingFloat > 0);

    printf("========== RECONCILIATION TESTS ==========\n");
    printf("Cash Discrepancy Exactly Zero: %d\n", cashExactlyZero);
    printf("Float Discrepancy Exactly Zero: %d\n", floatExactlyZero);
    printf("Cash Within KES 100: %d\n", cashWithinLimit);
    printf("Float Within KES 100: %d\n", floatWithinLimit);
    printf("Both Within Permitted Difference: %d\n", bothWithinLimit);
    printf("Either Account Has Shortage: %d\n", eitherShortage);
    printf("Both Closing Balances Positive: %d\n", bothBalancesPositive);

    return 0;
}