#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct { int id; char title[50]; char author[40]; int available; } Book;
typedef struct { int bookId; char roll[15]; char due[12]; int returned; } Issue;
Book b[MAX]; Issue rec[MAX];
int bn = 0, rn = 0, bid = 1;
void add() {
    b[bn].id = bid++;
    printf("Title : "); scanf(" %[^\n]", b[bn].title);
    printf("Author: "); scanf(" %[^\n]", b[bn].author);
    b[bn].available = 1; bn++;
    printf("Added!\n");
}
void list() {
    for (int i = 0; i < bn; i++)
        printf("%d. %s - %s [%s]\n", b[i].id, b[i].title, b[i].author,
               b[i].available ? "Available" : "Issued");
}
void issue() {
    int id; printf("Book ID: "); scanf("%d", &id);
    for (int i = 0; i < bn; i++) {
        if (b[i].id == id) {
            if (!b[i].available) { printf("Already issued!\n"); return; }
            printf("Roll: "); scanf("%s", rec[rn].roll);
            printf("Due : "); scanf("%s", rec[rn].due);
            rec[rn].bookId = id; rec[rn].returned = 0;
            b[i].available = 0; rn++;
            printf("Issued!\n"); return;
        }
    }
    printf("Not found.\n");
}
void ret() {
    char roll[15]; printf("Roll: "); scanf("%s", roll);
    for (int i = 0; i < rn; i++) {
        if (strcmp(rec[i].roll, roll) == 0 && !rec[i].returned) {
            rec[i].returned = 1;
            for (int j = 0; j < bn; j++)
                if (b[j].id == rec[i].bookId) { b[j].available = 1; break; }
            printf("Returned!\n"); return;
        }
    }
    printf("Not found.\n");
}
int main() {
    int ch;
    do {
        printf("\n1.Add  2.List  3.Issue  4.Return  0.Exit\nChoice: ");
        scanf("%d", &ch);
        if      (ch == 1) add();
        else if (ch == 2) list();
        else if (ch == 3) issue();
        else if (ch == 4) ret();
    } while (ch != 0);
    return 0;
}