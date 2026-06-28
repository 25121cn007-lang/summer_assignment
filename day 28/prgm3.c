#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct { int id; char from[20]; char to[20]; char date[12]; int seats; float price; } Train;
typedef struct { int bid; int trainId; char name[50]; int seats; float total; } Booking;
Train t[MAX]; Booking bk[MAX];
int tn = 0, bn = 0, tid = 1, bid = 1;
int findTrain(int id) {
    for (int i = 0; i < tn; i++)
        if (t[i].id == id) return i;
    return -1;
}
void addTrain() {
    t[tn].id = tid++;
    printf("From  : "); scanf(" %[^\n]", t[tn].from);
    printf("To    : "); scanf(" %[^\n]", t[tn].to);
    printf("Date  : "); scanf("%s", t[tn].date);
    printf("Seats : "); scanf("%d", &t[tn].seats);
    printf("Price : "); scanf("%f", &t[tn].price);
    printf("Train added! ID: %d\n", t[tn].id);
    tn++;
}
void listTrains() {
    if (tn == 0) { printf("No trains.\n"); return; }
    printf("%-4s %-12s %-12s %-12s %-6s %s\n", "ID", "From", "To", "Date", "Seats", "Price");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < tn; i++)
        printf("%-4d %-12s %-12s %-12s %-6d Rs.%.2f\n",
               t[i].id, t[i].from, t[i].to, t[i].date, t[i].seats, t[i].price);
}
void book() {
    listTrains();
    int id; printf("Train ID: "); scanf("%d", &id);
    int i = findTrain(id);
    if (i == -1) { printf("Not found.\n"); return; }
    int seats; printf("Seats   : "); scanf("%d", &seats);
    if (seats > t[i].seats) { printf("Only %d seats available!\n", t[i].seats); return; }
    bk[bn].bid = bid++;
    bk[bn].trainId = id;
    printf("Name    : "); scanf(" %[^\n]", bk[bn].name);
    bk[bn].seats = seats;
    bk[bn].total = seats * t[i].price;
    t[i].seats -= seats;
    printf("Booked! ID: %d | Total: Rs.%.2f\n", bk[bn].bid, bk[bn].total);
    bn++;
}
void viewBooking() {
    int id; printf("Booking ID: "); scanf("%d", &id);
    for (int i = 0; i < bn; i++) {
        if (bk[i].bid == id) {
            int j = findTrain(bk[i].trainId);
            printf("\n--- TICKET ---\n");
            printf("Booking ID : %d\n", bk[i].bid);
            printf("Name       : %s\n", bk[i].name);
            if (j != -1) {
                printf("From       : %s\n", t[j].from);
                printf("To         : %s\n", t[j].to);
                printf("Date       : %s\n", t[j].date);
            }
            printf("Seats      : %d\n", bk[i].seats);
            printf("Total      : Rs.%.2f\n", bk[i].total);
            return;
        }
    }
    printf("Not found.\n");
}
void cancel() {
    int id; printf("Booking ID: "); scanf("%d", &id);
    for (int i = 0; i < bn; i++) {
        if (bk[i].bid == id) {
            int j = findTrain(bk[i].trainId);
            if (j != -1) t[j].seats += bk[i].seats;
            for (int k = i; k < bn - 1; k++) bk[k] = bk[k+1];
            bn--; printf("Cancelled!\n"); return;
        }
    }
    printf("Not found.\n");
}
void listBookings() {
    if (bn == 0) { printf("No bookings.\n"); return; }
    printf("%-6s %-20s %-10s %-6s %s\n", "BID", "Name", "Train ID", "Seats", "Total");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < bn; i++)
        printf("%-6d %-20s %-10d %-6d Rs.%.2f\n",
               bk[i].bid, bk[i].name, bk[i].trainId, bk[i].seats, bk[i].total);
}
int main() {
    int ch;
    do {
        printf("\n1.Add Train  2.Trains  3.Book  4.Ticket  5.Cancel  6.Bookings  0.Exit\nChoice: ");
        scanf("%d", &ch);
        if      (ch == 1) addTrain();
        else if (ch == 2) listTrains();
        else if (ch == 3) book();
        else if (ch == 4) viewBooking();
        else if (ch == 5) cancel();
        else if (ch == 6) listBookings();
    } while (ch != 0);
    return 0;
}