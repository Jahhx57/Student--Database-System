#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void addStudent(struct Student students[], int *count) {
    printf("Enter student name: ");
    scanf("%s", students[*count].name);

    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);

    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
    printf("Student record added successfully!\n");
}

void displayAllStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("Student Records:\n");
    printf("------------------------------------------------\n");
    printf("| %-20s | %-10s | %-5s |\n", "Name", "Roll Number", "Marks");
    printf("------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("| %-20s | %-10d | %-5.2f |\n", students[i].name, students[i].rollNumber, students[i].marks);
    }

    printf("------------------------------------------------\n");
}

int main() {
    struct Student students[100];
    int count = 0;

    int choice;

    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Consume the newline character from the input buffer
        getchar();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayAllStudents(students, count);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
