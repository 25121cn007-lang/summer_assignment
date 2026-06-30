#include <stdio.h>
#include <string.h>
#define MAX 50

struct Book { int id; char title[50]; char author[30]; int issued; } books[MAX];
int count = 0;

void addBook() {
    printf("ID: "); scanf("%d", &books[count].id);
    printf("Title: "); scanf(" %[^\n]", books[count].title);
    printf("Author: "); scanf(" %[^\n]", books[count].author);
    books[count].issued = 0;
    count++;
    printf("Book added!\n");
}

void displayAll() {
    printf("\n%-5s %-20s %-15s %-10s\n", "ID", "Title", "Author", "Status");
    for (int i = 0; i < count; i++)
        printf("%-5d %-20s %-15s %-10s\n", books[i].id, books[i].title, books[i].author,
               books[i].issued ? "Issued" : "Available");
}

void issueBook() {
    int id;
    printf("Enter ID to issue: "); scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued) printf("Already issued!\n");
            else { books[i].issued = 1; printf("Book issued!\n"); }
            return;
        }
    }
    printf("Book not found!\n");
}

void returnBook() {
    int id;
    printf("Enter ID to return: "); scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            books[i].issued = 0;
            printf("Book returned!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void searchBook() {
    char t[50];
    printf("Enter title to search: "); scanf(" %[^\n]", t);
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, t) == 0) {
            printf("Found -> ID:%d Author:%s Status:%s\n", books[i].id, books[i].author,
                   books[i].issued ? "Issued" : "Available");
            return;
        }
    }
    printf("Book not found!\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add 2.Display 3.Issue 4.Return 5.Search 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addBook(); break;
            case 2: displayAll(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: searchBook(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}