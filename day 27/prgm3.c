#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    int id;
    char name[50];
    char dept[30];
    float basic, hra, da, pf, tax, net;
} Emp;

Emp e[MAX];
int n = 0, nextId = 1;

void calc(Emp *p) {
    p->hra = p->basic * 0.40;
    p->da  = p->basic * 0.20;
    p->pf  = p->basic * 0.12;
    float gross = p->basic + p->hra + p->da;
    p->tax = (gross > 50000) ? gross * 0.10 : (gross > 20000) ? gross * 0.05 : 0;
    p->net = gross - p->pf - p->tax;
}

void add() {
    Emp p; p.id = nextId++;
    printf("Name  : "); scanf(" %[^\n]", p.name);
    printf("Dept  : "); scanf(" %[^\n]", p.dept);
    printf("Basic : "); scanf("%f", &p.basic);
    calc(&p);
    e[n++] = p;
    printf("Added! Net Salary: Rs. %.2f\n", p.net);
}

void list() {
    printf("%-4s %-18s %-12s %-10s %-10s\n", "ID", "Name", "Dept", "Basic", "Net");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-4d %-18s %-12s %-10.2f %-10.2f\n",
               e[i].id, e[i].name, e[i].dept, e[i].basic, e[i].net);
}

void slip() {
    int id; printf("ID: "); scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (e[i].id == id) {
            printf("\n--- SALARY SLIP ---\n");
            printf("Name  : %s\nDept  : %s\n", e[i].name, e[i].dept);
            printf("Basic : %.2f\nHRA   : %.2f\nDA    : %.2f\n", e[i].basic, e[i].hra, e[i].da);
            printf("PF    : %.2f\nTax   : %.2f\n", e[i].pf, e[i].tax);
            printf("Net   : Rs. %.2f\n", e[i].net);
            return;
        }
    }
    printf("Not found.\n");
}

void del() {
    int id; printf("ID: "); scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (e[i].id == id) {
            for (int j = i; j < n - 1; j++) e[j] = e[j+1];
            n--; printf("Deleted!\n"); return;
        }
    }
    printf("Not found.\n");
}

int main() {
    int ch;
    do {
        printf("\n1.Add  2.List  3.Slip  4.Delete  0.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) add();
        else if (ch == 2) list();
        else if (ch == 3) slip();
        else if (ch == 4) del();
    } while (ch != 0);
    return 0;
}