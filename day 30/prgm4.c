#include <stdio.h>
#include <string.h>
#define MAX 50

struct Student {
    int roll;
    char name[50];
    char grade[5];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) { printf("Limit full!\n"); return; }
    printf("Roll: "); scanf("%d", &students[count].roll);
    printf("Name: "); scanf(" %[^\n]", students[count].name);
    printf("Marks: "); scanf("%f", &students[count].marks);

    if (students[count].marks >= 90) strcpy(students[count].grade, "A+");
    else if (students[count].marks >= 75) strcpy(students[count].grade, "A");
    else if (students[count].marks >= 60) strcpy(students[count].grade, "B");
    else if (students[count].marks >= 40) strcpy(students[count].grade, "C");
    else strcpy(students[count].grade, "F");

    count++;
    printf("Student added!\n");
}

void displayAll() {
    if (count == 0) { printf("No records!\n"); return; }
    printf("\n%-6s %-20s %-8s %-6s\n", "Roll", "Name", "Marks", "Grade");
    for (int i = 0; i < count; i++)
        printf("%-6d %-20s %-8.2f %-6s\n", students[i].roll, students[i].name,
               students[i].marks, students[i].grade);
}

void searchStudent() {
    int roll;
    printf("Enter Roll: "); scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Found -> %s, Marks:%.2f, Grade:%s\n",
                   students[i].name, students[i].marks, students[i].grade);
            return;
        }
    }
    printf("Not found!\n");
}

void deleteStudent() {
    int roll;
    printf("Enter Roll to delete: "); scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) students[j] = students[j + 1];
            count--;
            printf("Deleted!\n");
            return;
        }
    }
    printf("Not found!\n");
}

float averageMarks() {
    if (count == 0) return 0;
    float sum = 0;
    for (int i = 0; i < count; i++) sum += students[i].marks;
    return sum / count;
}

void topper() {
    if (count == 0) { printf("No records!\n"); return; }
    int idx = 0;
    for (int i = 1; i < count; i++)
        if (students[i].marks > students[idx].marks) idx = i;
    printf("Topper -> %s with %.2f marks\n", students[idx].name, students[idx].marks);
}

int main() {
    int ch;
    while (1) {
        printf("\n--- Student Management ---\n");
        printf("1.Add 2.Display 3.Search 4.Delete 5.Average 6.Topper 7.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Average Marks: %.2f\n", averageMarks()); break;
            case 6: topper(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}