#include <stdio.h>

struct Student {
    int id;
    char name[30];
    float grade;
    int passed; //1 = passed, 0 = failed
};

float computeAverage (struct Student students[], int n);
float findTopStudent (struct Student students[], int n);
void countPassFail (struct Student students[], int n, int *passCount, int *failCount);
void printBelowAverage (struct Student students[], int n, float avg);

int main () {
    int n;
    printf("Enter number of students (1-50): ");
    scanf("%d", &n);

    struct Student students[50];

    for (int i = 0; i < n; i++){
        printf("\nEnter info for student %d\n", i+1);
        printf("ID: ");
        scanf ("%d", &students[i].id);
        printf("Name: ");
        scanf ("%s", &students[i].name);
        printf("Grade: ");
        scanf ("%f", &students[i].grade);
        printf("Passed (1=yes, 0=no): ");
        scanf (" %d", &students[i].passed);
    }

    //calculate avverage
    float avg = computeAverage(students, n);
    printf("\nAverage grade: %.2f\n", avg);

    //top student
    int topIndex = findTopStudent (students, n);
    printf("Top student: %s (ID: %d) with grade %.2f\n",
           students[topIndex].name,
           students[topIndex].id,
           students[topIndex].grade);

    //pass fail
    int passed = 0, failed = 0;
    countPassFail(students, n, &passed, &failed);
    printf("Passed: %d, Failed: %d\n", passed, failed);

    //below average student
    printf("\nStudents below average:\n");
    printBelowAverage(students, n, avg);

    return 0;
}

float computeAverage(struct Student students[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].grade;
    }
    return sum / n;
}


float findTopStudent(struct Student students[], int n) {
    int topIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].grade > students[topIndex].grade) {
            topIndex = i;
        }
    }
    return topIndex;
}

void countPassFail(struct Student students[], int n, int *passCount, int *failCount) {
    for (int i = 0; i < n; i++) {
        if (students[i].passed == 1)
            (*passCount)++;
        else
            (*failCount)++;
    }
}

void printBelowAverage(struct Student students[], int n, float avg) {
    for (int i = 0; i < n; i++) {
        if (students[i].grade < avg) {
            printf("%s (ID: %d) - Grade: %.2f\n", students[i].name, students[i].id, students[i].grade);
        }
    }
}
