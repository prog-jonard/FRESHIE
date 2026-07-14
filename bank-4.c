#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define FILE_NAME "bank3.txt"

struct Account {
    int accountNo;
    char name[50];
    int pin;
    float credit;
    float debit;
    float balance;
};

Account accounts[MAX];
int total = 0;

void loadFile() {
    FILE *f = fopen(FILE_NAME, "r");
    if (!f) return;
    total = 0;
    while (fscanf(f, "%d %s %d %f %f %f",
        &accounts[total].accountNo, accounts[total].name,
        &accounts[total].pin, &accounts[total].credit,
        &accounts[total].debit, &accounts[total].balance) == 6) {
        total++;
    }
    fclose(f);
}

void saveFile() {
    FILE *f = fopen(FILE_NAME, "w");
    for (int i = 0; i < total; i++) {
        fprintf(f, "%d %s %d %.2f %.2f %.2f\n",
            accounts[i].accountNo, accounts[i].name,
            accounts[i].pin, accounts[i].credit,
            accounts[i].debit, accounts[i].balance);
    }
    fclose(f);
}

int findAccount(int accNo, int pin) {
    for (int i = 0; i < total; i++)
        if (accounts[i].accountNo == accNo && accounts[i].pin == pin)
            return i;
    return -1;
}

void showAccount(int i) {
    printf("\nAccount No : %d\n", accounts[i].accountNo);
    printf("Name       : %s\n",   accounts[i].name);
    printf("Credit     : %.2f\n", accounts[i].credit);
    printf("Debit      : %.2f\n", accounts[i].debit);
    printf("Balance    : %.2f\n", accounts[i].balance);
}

void addAccount() {
    int accNo, pin;
    char name[50];
    float credit;
	
   printf("\n========================================\n");
   printf("     BANK ACCOUNT MANAGEMENT SYSTEM\n");
   printf("========================================\n");

    printf("Account Number [Numbers Only]: "); scanf("%d", &accNo);
    if (accNo < 10000 || accNo > 99999) { printf("Invalid! Account number must be exactly 5 digits. [Numbers Only]\n"); return; }
    for (int i = 0; i < total; i++)
        if (accounts[i].accountNo == accNo) { printf("Invalid! Account number already exists.\n"); return; }

    printf("Account Name [Letters Only]  : "); fflush(stdin); scanf(" %s", name);
    for (int i = 0; name[i] != '\0'; i++) {
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z'))) {
            printf("Invalid! Name must contain letters only.\n"); return;
        }
    }

    printf("PIN Number [Four Digits Only]: "); scanf("%d", &pin);
    if (pin < 1000 || pin > 9999) { printf("Invalid! PIN must be exactly 4 digits.\n"); return; }

    printf("Credit         : "); scanf("%f", &credit);

    accounts[total].accountNo = accNo;
    strcpy(accounts[total].name, name);
    accounts[total].pin     = pin;
    accounts[total].credit  = credit;
    accounts[total].debit   = 0;
    accounts[total].balance = credit;
    total++;
    saveFile();
    printf("\nAccount added!\n");
}

void editAccount() {
    int accNo, pin;
    printf("\n--- Edit Account ---\n");
    printf("Verify your Account to continue\n\n");
    printf("Account Number : "); scanf("%d", &accNo);    
    printf("PIN Number     : "); scanf("%d", &pin);

    int i = findAccount(accNo, pin);
    if (i == -1) { printf("Record not found!\n"); return; }

    showAccount(i);

    char c[5];
    float amount;
    printf("\nDeposit or Withdraw? [D/W] : "); fflush(stdin); scanf(" %s", c);

    switch (toupper(c[0])) {
        case 'D':
            printf("Amount : "); scanf("%f", &amount);
            accounts[i].credit  += amount;
            accounts[i].balance += amount;
            break;
        case 'W':
            printf("Amount : "); scanf("%f", &amount);
            if (amount > accounts[i].balance)
                printf("Insufficient balance.\n");
            else {
                accounts[i].debit   += amount;
                accounts[i].balance -= amount;
            }
            break;
        default:
            printf("Invalid option. No changes made. [Choose only from the Letters Above]\n");
            return;
    }

    saveFile();
    printf("\nAccount updated!\n");
}

void deleteAccount() {
    int accNo, pin;
    printf("\n--- Delete Account ---\n");
    printf("Verify your Account to continue\n\n");
    printf("Account Number : "); scanf("%d", &accNo);
    printf("PIN Number     : "); scanf("%d", &pin);

    int i = findAccount(accNo, pin);
    if (i == -1) { printf("Record not found!\n"); return; }

    showAccount(i);

    char ans[10];
    printf("\nDelete this account? [Y/N]: "); scanf("%s", ans);
    if (strcmp(ans, "Y") == 0) {
        for (int j = i; j < total - 1; j++)
            accounts[j] = accounts[j + 1];
        total--;
        saveFile();
        printf("\nAccount deleted!\n");
    } else {
        printf("\nCancelled.\n");
        
    }
}

void viewAll() {
    printf("\n<--- All Accounts --->\n");
    printf("%-15s %-15s %-10s %-10s %-10s %-10s\n", "Account No", "Name", "PIN", "Credit", "Debit", "Balance");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%-15d %-15s %-10d %-10.2f %-10.2f %-10.2f\n",
               accounts[i].accountNo,
               accounts[i].name,
               accounts[i].pin,
               accounts[i].credit,
               accounts[i].debit,
               accounts[i].balance);
    }
}

int main() {
    loadFile();

    char has[5];
    do {
        printf("\n========================================\n");
        printf("     BANK ACCOUNT MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("\nDo you have an account? (Y/N) or E[X]it: ");
        fflush(stdin);
        scanf(" %s", has);
        has[0] = toupper(has[0]);

        if (has[0] == 'X') {
            printf("Thank you for using this program\n");
            break;
        }

        if (has[0] == 'N') {
            char want[5];
            printf("Would you like to create one? (Y/N): ");
            fflush(stdin);
            scanf(" %s", want);
            want[0] = toupper(want[0]);

            if (want[0] != 'Y') {
                printf("\nReturning...\n");
                continue;
            }

            addAccount();

            char after[5];
            do {
                printf("\n1. [C]reate another account  \n2. [L]og in\n");
                printf("Please select [Letter Only]: ");
                fflush(stdin);
                scanf(" %s", after);
                after[0] = toupper(after[0]);

                if (after[0] == 'C') {
                    addAccount();
                } else if (after[0] == 'L') {
                    break;
                } else {
                    printf("Invalid option. [Choose only from the Letters Above]\n");
                }
            } while (after[0] != 'L');

            continue;
            
        }

        if (has[0] != 'Y') {
            printf("Invalid option [Choose only from the Letters Above].\n");
            continue;
        }

        int accNo, pin;
        printf("\nEnter account number : "); scanf("%d", &accNo);
        if (accNo < 10000 || accNo > 99999) { printf("Invalid! Account number must be exactly 5 digits. [Numbers Only]\n"); continue; }

        printf("Enter PIN            : "); scanf("%d", &pin);
        if (pin < 1000 || pin > 9999) { printf("Invalid! PIN must be exactly 4 digits. \n"); continue; }

        if (findAccount(accNo, pin) == -1) {
            printf("Record not found!\n\nReturning...\n");
            continue;
        }

        printf("\nLogin successful!\n");

        char option[5];
        do {
            printf("\n1. [A]dd  \n2. [E]dit  \n3. [D]elete  \n4. [V]iew  \n5. E[X]it\n");
            printf("Please select [Letter Only]: ");
            fflush(stdin);
            scanf(" %s", option);
            option[0] = toupper(option[0]);

            switch (option[0]) {
                case 'A': addAccount();             break;
                case 'E': editAccount();            break;
                case 'D': deleteAccount();          break;
                case 'V': viewAll();                break;
                case 'X': printf("Thank you for using this program!\n"); return 0;
                default:  printf("Invalid option. [Choose only from the Letters Above]\n"); break;
            }

        } while (option[0] != 'X');

    } while (has[0] != 'X');

    return 0;
}








