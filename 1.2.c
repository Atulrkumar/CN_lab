/*1. Write a C program to swap the content of 2 variables entered through the
command line using function and pointer.
2. Write a C program to assign values to each member of the following structure.
Pass the populated structure to a function Using call-by-value and another
function using call-by-address and print the value of each member of the
structure.

struct student_info{
int roll_no;
char name [50];
float CGPA;
struct dob age;
};*/
#include <stdio.h>
#include <string.h>
struct dob {
    int day;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void printStudentInfoByValue(struct student_info student) {
    printf("Using call-by-value:\n");
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %02d/%02d/%04d\n", student.age.day, student.age.month, student.age.year);
}

void printStudentInfoByAddress(struct student_info *student) {
    printf("Using call-by-address:\n");
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of Birth: %02d/%02d/%04d\n", student->age.day, student->age.month, student->age.year);
}

int main() {
    struct student_info student;

    printf("Enter roll number: ");
    scanf("%d", &student.roll_no);
    getchar();
    printf("Enter name: ");
    fgets(student.name, sizeof(student.name), stdin);
    size_t len = strlen(student.name);
    if (len > 0 && student.name[len - 1] == '\n') {
        student.name[len - 1] = '\0';
    }
    printf("Enter CGPA: ");
    scanf("%f", &student.CGPA);
    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &student.age.day, &student.age.month, &student.age.year);

    printStudentInfoByValue(student);

    printStudentInfoByAddress(&student);

    return 0;
}