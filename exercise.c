#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_GRADES 3

// Function to determine the letter grade based on the average
char getLetterGrade(float average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    char names[NUM_STUDENTS][50]; // Array to store names of students
    float subj1[NUM_STUDENTS], subj2[NUM_STUDENTS], subj3[NUM_STUDENTS]; // Arrays to store grades for 3 subjects
    float averages[NUM_STUDENTS]; // Array to store average grades of students
    char grades[NUM_STUDENTS]; // Array to store letter grades (A, B, C, etc.)

    // Input student names and their grades
    for (int i = 0; i < NUM_STUDENTS; i++) {
        // Prompt for student name
        printf("Enter the name of student %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin); // Read student name (handles spaces)

        // Ask for grades for 3 subjects
        printf("Enter grades for %s", names[i]);
        printf("Subject 1: ");
        scanf("%f", &subj1[i]);
        printf("Subject 2: ");
        scanf("%f", &subj2[i]);
        printf("Subject 3: ");
        scanf("%f", &subj3[i]);

        // Calculate the average for the student
        averages[i] = (subj1[i] + subj2[i] + subj3[i]) / NUM_GRADES;

        // Determine the letter grade based on the average
        grades[i] = getLetterGrade(averages[i]);

        getchar(); // Clear the newline left by the previous scanf
    }

    // Display the results
    printf("\nStudent Grades and Averages:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student: %s", names[i]);
        printf("Subject 1: %.2f, Subject 2: %.2f, Subject 3: %.2f\n", subj1[i], subj2[i], subj3[i]);
        printf("Average grade: %.2f, Final grade: %c\n\n", averages[i], grades[i]);
    }

    return 0;
}
