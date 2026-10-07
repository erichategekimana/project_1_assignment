#include <stdio.h>

int main(void) {
    // Variable declarations with appropriate data types
    double balance = 0.0;
    double amount = 0.0;
    int choice = 0;
    int deposit_count = 0;
    int withdrawal_count = 0;

    while (1) {
        // Display Menu
        printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        // Validate menu choice input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a numeric choice.\n");
            // Clear input buffer to avoid an infinite loop on invalid character input
            while (getchar() != '\n');
            continue; // Return to the top of the loop
        }

        // Process choices using switch
        switch (choice) {
            case 1: // Deposit
                printf("Enter deposit amount: ");
                if (scanf("%lf", &amount) != 1 || amount <= 0.0) {
                    printf("Transaction rejected: Deposit amount must be positive.\n");
                    while (getchar() != '\n');
                    continue; // Skip the rest and return to menu
                }

                balance += amount;
                deposit_count++;
                printf("Deposit successful.\n");
                printf("Current balance: %.0f RWF\n", balance);
                break;

            case 2: // Withdraw
                printf("Enter withdrawal amount: ");
                if (scanf("%lf", &amount) != 1 || amount <= 0.0) {
                    printf("Transaction rejected: Withdrawal amount must be positive.\n");
                    while (getchar() != '\n');
                    continue; // Skip the rest and return to menu
                }

                if (amount > balance) {
                    printf("Transaction rejected: Insufficient balance.\n");
                    printf("Current balance: %.0f RWF\n", balance);
                } else {
                    balance -= amount;
                    withdrawal_count++;
                    printf("Withdrawal successful.\n");
                    printf("Current balance: %.0f RWF\n", balance);
                }
                break;

            case 3: // Balance Inquiry
                printf("Current balance: %.0f RWF\n", balance);
                break;

            case 4: // Transaction Summary
                printf("===== TRANSACTION SUMMARY =====\n");
                printf("Successful Deposits   : %d\n", deposit_count);
                printf("Successful Withdrawals: %d\n", withdrawal_count);
                printf("Current Balance       : %.0f RWF\n", balance);
                break;

            case 5: // Exit
                printf("System terminated.\n");
                break; // Break out of switch; loop termination handled below

            default:
                printf("Invalid selection! Please choose an option from 1 to 5.\n");
                continue; // Return directly to the menu
        }

        // Check for termination to break the while loop
        if (choice == 5) {
            break;
        }
    }

    return 0;
}