#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct { int id; char name[50]; char phone[15]; char email[50]; char group[15]; } Contact;
Contact c[MAX];
int n = 0, nextId = 1;
int find(int id) {
    for (int i = 0; i < n; i++)
        if (c[i].id == id) return i;
    return -1;
}
void add() {
    c[n].id = nextId++;
    printf("Name  : "); scanf(" %[^\n]", c[n].name);
    printf("Phone : "); scanf("%s", c[n].phone);
    printf("Email : "); scanf("%s", c[n].email);
    printf("Group (Friend/Work/Family): "); scanf("%s", c[n].group);
    printf("Saved! ID: %d\n", c[n].id);
    n++;
}
void list() {
    if (n == 0) { printf("No contacts.\n"); return; }
    printf("%-4s %-20s %-15s %-25s %s\n", "ID", "Name", "Phone", "Email", "Group");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-4d %-20s %-15s %-25s %s\n",
               c[i].id, c[i].name, c[i].phone, c[i].email, c[i].group);
}
void search() {
    char q[50]; printf("Search name/phone: "); scanf(" %[^\n]", q);
    int found = 0;
    for (int i = 0; i < n; i++)
        if (strstr(c[i].name, q) || strstr(c[i].phone, q)) {
            printf("%d. %s | %s | %s | %s\n", c[i].id, c[i].name, c[i].phone, c[i].email, c[i].group);
            found = 1;
        }
    if (!found) printf("Not found.\n");
}
void update() {
    int id; printf("ID: "); scanf("%d", &id);
    int i = find(id);
    if (i == -1) { printf("Not found.\n"); return; }
    printf("Name  [%s]: ", c[i].name);  scanf(" %[^\n]", c[i].name);
    printf("Phone [%s]: ", c[i].phone); scanf("%s", c[i].phone);
    printf("Email [%s]: ", c[i].email); scanf("%s", c[i].email);
    printf("Group [%s]: ", c[i].group); scanf("%s", c[i].group);
    printf("Updated!\n");
}
void del() {
    int id; printf("ID: "); scanf("%d", &id);
    int i = find(id);
    if (i == -1) { printf("Not found.\n"); return; }
    for (int j = i; j < n - 1; j++) c[j] = c[j+1];
    n--; printf("Deleted!\n");
}
void byGroup() {
    char g[15]; printf("Group: "); scanf("%s", g);
    int found = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(c[i].group, g) == 0) {
            printf("%d. %s | %s\n", c[i].id, c[i].name, c[i].phone);
            found = 1;
        }
    if (!found) printf("No contacts in this group.\n");
}
int main() {
    int ch;
    do {
        printf("\n1.Add  2.List  3.Search  4.Update  5.Delete  6.Group  0.Exit\nChoice: ");
        scanf("%d", &ch);
        if      (ch == 1) add();
        else if (ch == 2) list();
        else if (ch == 3) search();
        else if (ch == 4) update();
        else if (ch == 5) del();
        else if (ch == 6) byGroup();
    } while (ch != 0);
    return 0;
}