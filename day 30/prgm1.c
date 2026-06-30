#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("Record limit full!\n");
        return;
    }
    struct Student s;
    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[count] = s;
    count++;
    printf("Student added successfully!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].roll, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int roll, found = 0;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Found -> Roll: %d, Name: %s, Marks: %.2f\n",
                   students[i].roll, students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student not found!\n");
}

void deleteStudent() {
    int roll, found = 0;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            found = 1;
            printf("Student deleted successfully!\n");
            break;
        }
    }
    if (!found)
        printf("Student not found!\n");
}

void updateStudent() {
    int roll, found = 0;
    printf("Enter Roll No to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);
            found = 1;
            printf("Student updated successfully!\n");
            break;
        }
    }
    if (!found)
        printf("Student not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n----- Student Record System -----\n");
        printf("1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}