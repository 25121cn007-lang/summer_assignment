#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define EMAIL_LEN 50
#define DEPT_LEN 50
#define FILE_NAME "students.dat"

typedef struct {
    int id;
    char name[NAME_LEN];
    char rollNo[20];
    char dept[DEPT_LEN];
    int year;
    char email[EMAIL_LEN];
    float gpa;
    char grade[5];
    char phone[15];
} Student;

Student students[MAX_STUDENTS];
int count = 0;
int nextId = 1;

/* ───── File I/O ───── */

void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) { printf("Error saving file!\n"); return; }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(&nextId, sizeof(int), 1, fp);
    fwrite(students, sizeof(Student), count, fp);
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return;
    fread(&count, sizeof(int), 1, fp);
    fread(&nextId, sizeof(int), 1, fp);
    fread(students, sizeof(Student), count, fp);
    fclose(fp);
}

/* ───── Helpers ───── */

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printLine() {
    printf("─────────────────────────────────────────────────────────\n");
}

void printHeader() {
    system("clear || cls");
    printLine();
    printf("         🎓  STUDENT RECORD MANAGEMENT SYSTEM\n");
    printLine();
}

int findById(int id) {
    for (int i = 0; i < count; i++)
        if (students[i].id == id) return i;
    return -1;
}

int rollExists(const char *roll, int excludeId) {
    for (int i = 0; i < count; i++)
        if (strcmp(students[i].rollNo, roll) == 0 && students[i].id != excludeId)
            return 1;
    return 0;
}

void printTableHeader() {
    printf("%-5s %-20s %-10s %-18s %-6s %-5s %-5s\n",
           "ID", "Name", "Roll No", "Department", "Year", "GPA", "Grade");
    printLine();
}

void printStudent(Student *s) {
    printf("%-5d %-20s %-10s %-18s %-6d %-5.2f %-5s\n",
           s->id, s->name, s->rollNo, s->dept, s->year, s->gpa, s->grade);
}

/* ───── Core Operations ───── */

void addStudent() {
    printHeader();
    printf("  ADD NEW STUDENT\n");
    printLine();

    if (count >= MAX_STUDENTS) {
        printf("Storage full! Cannot add more students.\n");
        return;
    }

    Student s;
    s.id = nextId++;

    printf("Name        : ");
    fgets(s.name, NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    do {
        printf("Roll Number : ");
        fgets(s.rollNo, 20, stdin);
        s.rollNo[strcspn(s.rollNo, "\n")] = 0;
        if (rollExists(s.rollNo, -1))
            printf("  ⚠ Roll number already exists. Try again.\n");
    } while (rollExists(s.rollNo, -1));

    printf("Department  : ");
    fgets(s.dept, DEPT_LEN, stdin);
    s.dept[strcspn(s.dept, "\n")] = 0;

    printf("Year (1-5)  : ");
    scanf("%d", &s.year);
    clearBuffer();

    printf("Email       : ");
    fgets(s.email, EMAIL_LEN, stdin);
    s.email[strcspn(s.email, "\n")] = 0;

    printf("Phone       : ");
    fgets(s.phone, 15, stdin);
    s.phone[strcspn(s.phone, "\n")] = 0;

    printf("GPA (0-4)   : ");
    scanf("%f", &s.gpa);
    clearBuffer();

    printf("Grade       : ");
    fgets(s.grade, 5, stdin);
    s.grade[strcspn(s.grade, "\n")] = 0;

    students[count++] = s;
    saveToFile();
    printf("\n  ✓ Student '%s' added successfully! (ID: %d)\n", s.name, s.id);
}

void listAllStudents() {
    printHeader();
    printf("  ALL STUDENTS  (%d record%s)\n", count, count != 1 ? "s" : "");
    printLine();

    if (count == 0) {
        printf("  No students found.\n");
        return;
    }

    printTableHeader();
    for (int i = 0; i < count; i++)
        printStudent(&students[i]);
}

void searchStudent() {
    printHeader();
    printf("  SEARCH STUDENT\n");
    printLine();
    printf("  1. Search by ID\n");
    printf("  2. Search by Name\n");
    printf("  3. Search by Roll Number\n");
    printLine();
    printf("Choice: ");

    int choice;
    scanf("%d", &choice);
    clearBuffer();

    int found = 0;

    if (choice == 1) {
        printf("Enter ID: ");
        int id; scanf("%d", &id); clearBuffer();
        int idx = findById(id);
        if (idx != -1) {
            Student *s = &students[idx];
            printLine();
            printf("  ID         : %d\n", s->id);
            printf("  Name       : %s\n", s->name);
            printf("  Roll No    : %s\n", s->rollNo);
            printf("  Department : %s\n", s->dept);
            printf("  Year       : %d\n", s->year);
            printf("  Email      : %s\n", s->email);
            printf("  Phone      : %s\n", s->phone);
            printf("  GPA        : %.2f\n", s->gpa);
            printf("  Grade      : %s\n", s->grade);
            found = 1;
        }
    } else if (choice == 2) {
        printf("Enter Name (partial): ");
        char query[NAME_LEN];
        fgets(query, NAME_LEN, stdin);
        query[strcspn(query, "\n")] = 0;
        printLine();
        printTableHeader();
        for (int i = 0; i < count; i++) {
            if (strstr(students[i].name, query) != NULL) {
                printStudent(&students[i]);
                found = 1;
            }
        }
    } else if (choice == 3) {
        printf("Enter Roll No: ");
        char roll[20];
        fgets(roll, 20, stdin);
        roll[strcspn(roll, "\n")] = 0;
        printLine();
        printTableHeader();
        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].rollNo, roll) == 0) {
                printStudent(&students[i]);
                found = 1;
            }
        }
    }

    if (!found) printf("\n  No matching student found.\n");
}

void updateStudent() {
    printHeader();
    printf("  EDIT STUDENT\n");
    printLine();
    printf("Enter Student ID to edit: ");
    int id; scanf("%d", &id); clearBuffer();

    int idx = findById(id);
    if (idx == -1) { printf("  Student not found.\n"); return; }

    Student *s = &students[idx];
    printf("Editing: %s (%s)\n", s->name, s->rollNo);
    printLine();
    printf("(Press Enter to keep current value)\n\n");

    char buf[100];

    printf("Name [%s]: ", s->name);
    fgets(buf, NAME_LEN, stdin);
    buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf) > 0) strcpy(s->name, buf);

    char newRoll[20];
    do {
        printf("Roll No [%s]: ", s->rollNo);
        fgets(newRoll, 20, stdin);
        newRoll[strcspn(newRoll, "\n")] = 0;
        if (strlen(newRoll) == 0) break;
        if (rollExists(newRoll, s->id))
            printf("  ⚠ Roll number already in use.\n");
        else { strcpy(s->rollNo, newRoll); break; }
    } while (1);

    printf("Department [%s]: ", s->dept);
    fgets(buf, DEPT_LEN, stdin);
    buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf) > 0) strcpy(s->dept, buf);

    printf("Year [%d]: ", s->year);
    fgets(buf, 10, stdin);
    buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf) > 0) s->year = atoi(buf);

    printf("Email [%s]: ", s->email);
    fgets(buf, EMAIL_LEN, stdin);
    buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf) > 0) strcpy(s->email, buf);

    printf("Phone [%s]: ", s->phone);
    fgets(buf, 15, stdin);
    buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf) > 0) strcpy(s->phone, buf);

    printf("GPA [%.2f]: ", s->gpa);
    fgets(buf, 10, stdin);
    buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf) > 0) s->gpa = atof(buf);

    printf("Grade [%s]: ", s->grade);
    fgets(buf, 5, stdin);
    buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf) > 0) strcpy(s->grade, buf);

    saveToFile();
    printf("\n  ✓ Student record updated successfully!\n");
}

void deleteStudent() {
    printHeader();
    printf("  DELETE STUDENT\n");
    printLine();
    printf("Enter Student ID to delete: ");
    int id; scanf("%d", &id); clearBuffer();

    int idx = findById(id);
    if (idx == -1) { printf("  Student not found.\n"); return; }

    printf("Are you sure you want to delete '%s' (%s)? (y/n): ",
           students[idx].name, students[idx].rollNo);
    char c = getchar(); clearBuffer();

    if (c == 'y' || c == 'Y') {
        for (int i = idx; i < count - 1; i++)
            students[i] = students[i + 1];
        count--;
        saveToFile();
        printf("  ✓ Student deleted successfully.\n");
    } else {
        printf("  Deletion cancelled.\n");
    }
}

void showStats() {
    printHeader();
    printf("  STATISTICS\n");
    printLine();

    if (count == 0) { printf("  No data available.\n"); return; }

    float totalGpa = 0, maxGpa = 0, minGpa = 4.0;
    int honors = 0;
    char depts[MAX_STUDENTS][DEPT_LEN];
    int deptCount = 0;

    for (int i = 0; i < count; i++) {
        float g = students[i].gpa;
        totalGpa += g;
        if (g > maxGpa) maxGpa = g;
        if (g < minGpa) minGpa = g;
        if (g >= 3.7) honors++;

        int found = 0;
        for (int j = 0; j < deptCount; j++)
            if (strcmp(depts[j], students[i].dept) == 0) { found = 1; break; }
        if (!found) strcpy(depts[deptCount++], students[i].dept);
    }

    printf("  Total Students   : %d\n", count);
    printf("  Average GPA      : %.2f\n", totalGpa / count);
    printf("  Highest GPA      : %.2f\n", maxGpa);
    printf("  Lowest GPA       : %.2f\n", minGpa);
    printf("  Honors (GPA≥3.7) : %d\n", honors);
    printf("  Departments      : %d\n", deptCount);
    printLine();
    printf("  Departments list :\n");
    for (int i = 0; i < deptCount; i++)
        printf("    • %s\n", depts[i]);
}

/* ───── Main Menu ───── */

int main() {
    loadFromFile();

    int choice;
    do {
        printHeader();
        printf("  MAIN MENU\n");
        printLine();
        printf("  1. Add Student\n");
        printf("  2. List All Students\n");
        printf("  3. Search Student\n");
        printf("  4. Edit Student\n");
        printf("  5. Delete Student\n");
        printf("  6. View Statistics\n");
        printf("  0. Exit\n");
        printLine();
        printf("  Choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1: addStudent();      break;
            case 2: listAllStudents(); break;
            case 3: searchStudent();   break;
            case 4: updateStudent();   break;
            case 5: deleteStudent();   break;
            case 6: showStats();       break;
            case 0: printf("\n  Goodbye!\n"); break;
            default: printf("  Invalid choice.\n");
        }

        if (choice != 0) {
            printf("\n  Press Enter to continue...");
            getchar();
        }

    } while (choice != 0);

    return 0;
}