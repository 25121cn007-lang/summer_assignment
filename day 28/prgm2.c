#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct { int acc; char name[50]; char type[10]; float balance; } Account;
Account a[MAX];
int n = 0, nextAcc = 1001;
int find(int acc) {
    for (int i = 0; i < n; i++)
        if (a[i].acc == acc) return i;
    return -1;
}
void create() {
    a[n].acc = nextAcc++;
    printf("Name   : "); scanf(" %[^\n]", a[n].name);
    printf("Type (Savings/Current): "); scanf("%s", a[n].type);
    printf("Deposit: "); scanf("%f", &a[n].balance);
    printf("Account created! No: %d\n", a[n].acc);
    n++;
}
void list() {
    for (int i = 0; i < n; i++)
        printf("%d. %s | %s | Rs. %.2f\n", a[i].acc, a[i].name, a[i].type, a[i].balance);
}
void deposit() {
    int acc; float amt;
    printf("Acc No: "); scanf("%d", &acc);
    int i = find(acc);
    if (i == -1) { printf("Not found.\n"); return; }
    printf("Amount: "); scanf("%f", &amt);
    a[i].balance += amt;
    printf("New Balance: Rs. %.2f\n", a[i].balance);
}
void withdraw() {
    int acc; float amt;
    printf("Acc No: "); scanf("%d", &acc);
    int i = find(acc);
    if (i == -1) { printf("Not found.\n"); return; }
    printf("Amount: "); scanf("%f", &amt);
    if (amt > a[i].balance) { printf("Insufficient balance!\n"); return; }
    a[i].balance -= amt;
    printf("New Balance: Rs. %.2f\n", a[i].balance);
}
void check() {
    int acc; printf("Acc No: "); scanf("%d", &acc);
    int i = find(acc);
    if (i == -1) { printf("Not found.\n"); return; }
    printf("\n--- Account Details ---\n");
    printf("Acc No  : %d\n", a[i].acc);
    printf("Name    : %s\n", a[i].name);
    printf("Type    : %s\n", a[i].type);
    printf("Balance : Rs. %.2f\n", a[i].balance);
}
void transfer() {
    int from, to; float amt;
    printf("From Acc: "); scanf("%d", &from);
    printf("To Acc  : "); scanf("%d", &to);
    int i = find(from), j = find(to);
    if (i == -1 || j == -1) { printf("Account not found.\n"); return; }
    printf("Amount  : "); scanf("%f", &amt);
    if (amt > a[i].balance) { printf("Insufficient balance!\n"); return; }
    a[i].balance -= amt;
    a[j].balance += amt;
    printf("Transferred! Rs. %.2f from %d to %d\n", amt, from, to);
}
void del() {
    int acc; printf("Acc No: "); scanf("%d", &acc);
    int i = find(acc);
    if (i == -1) { printf("Not found.\n"); return; }
    for (int j = i; j < n - 1; j++) a[j] = a[j+1];
    n--; printf("Account deleted!\n");
}
int main() {
    int ch;
    do {
        printf("\n1.Create  2.List  3.Deposit  4.Withdraw  5.Balance  6.Transfer  7.Delete  0.Exit\nChoice: ");
        scanf("%d", &ch);
        if      (ch == 1) create();
        else if (ch == 2) list();
        else if (ch == 3) deposit();
        else if (ch == 4) withdraw();
        else if (ch == 5) check();
        else if (ch == 6) transfer();
        else if (ch == 7) del();
    } while (ch != 0);
    return 0;
}