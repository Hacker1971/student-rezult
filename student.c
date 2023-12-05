#include <stdio.h>
#include <string.h>

// Student structure
struct Student
{
    int id;
    char name[50];
    int class;
    float mathScore;
    float englishScore;
    float cProgrammingScore;
};

// Array of students
struct Student students[100];

// Number of students
int numStudents = 0;

// Function prototypes
void addStudent();
void deleteStudent();
void updateStudent();
void studentResult();
void printStudents();

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Student rezult\n");
        printf("5. Print Student List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            studentResult();
            break;
        case 5:
            printStudents();
            break;
        case 6:
            return 0;
            break;
        }
    }
}

// Add new student
void addStudent()
{
    int id;

    // Get student details
    printf("Enter student ID: ");
    scanf("%d", &id);
    students[numStudents].id = id;

    printf("Enter name: ");
    scanf("%s", students[numStudents].name);

    printf("Enter class: ");
    scanf("%d", &students[numStudents].class);

    printf("Enter math score: ");
    scanf("%f", &students[numStudents].mathScore);

    printf("Enter english score: ");
    scanf("%f", &students[numStudents].englishScore);

    printf("Enter C Programming score: ");
    scanf("%f", &students[numStudents].cProgrammingScore);

    // Increment student count
    numStudents++;

    printf("New student added successfully!\n");
}

// Functions for other operations
// Delete student by ID
void deleteStudent()
{
    int id;
    int i;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    // Find index of student with given ID
    for (i = 0; i < numStudents; i++)
    {
        if (students[i].id == id)
        {
            break;
        }
    }

    // If ID found, shift elements after i
    if (i < numStudents)
    {
        for (int j = i; j < numStudents - 1; j++)
        {
            students[j] = students[j + 1];
        }

        numStudents--;
        printf("Student deleted.\n");
    }
    else
    {
        printf("Student with ID %d not found\n", id);
    }
}

// Update student score
void updateStudent()
{
    int id;
    int choice;
    float score;

    // Get student id
    printf("Enter student ID to update: ");
    scanf("%d", &id);

    // Find student index
    int i;
    for (i = 0; i < numStudents; i++)
    {
        if (students[i].id == id)
        {
            break;
        }
    }

    // Not found
    if (i == numStudents)
    {
        printf("Student with ID %d not found\n", id);
        return;
    }

    // Found - Print scores
    printf("Current scores:\n");
    printf("Math: %.2f \n", students[i].mathScore);
    printf("English: %.2f \n", students[i].englishScore);
    printf("C Programming: %.2f\n", students[i].cProgrammingScore);

    // Choose score to update
    printf("1. Update Math score\n");
    printf("2. Update English score \n");
    printf("3. Update C Programming score\n");
    printf("Choice: ");
    scanf("%d", &choice);

    // Input updated score
    printf("Enter updated score: ");
    scanf("%f", &score);

    // Update selected score
    if (choice == 1)
    {
        students[i].mathScore = score;
    }
    else if (choice == 2)
    {
        students[i].englishScore = score;
    }
    else if (choice == 3)
    {
        students[i].cProgrammingScore = score;
    }

    printf("Score updated successfully!\n");
}
// Calculate student result
void studentResult()
{
    // Calculate average score for each student
    float studentAverage[100];
    for (int i = 0; i < numStudents; i++)
    {
        studentAverage[i] = (students[i].mathScore + students[i].englishScore + students[i].cProgrammingScore) / 3.0;
    }

    // Print average score for each student
    printf("\n");
    printf("Average Scores:\n");
    for (int i = 0; i < numStudents; i++)
    {
        printf("Student %s (ID: %d): %.2f \n", students[i].name, students[i].id, studentAverage[i]);
    }

    // Calculate average score for each course
    float mathSum = 0, englishSum = 0, cSum = 0;
    for (int i = 0; i < numStudents; i++)
    {
        mathSum += students[i].mathScore;
        englishSum += students[i].englishScore;
        cSum += students[i].cProgrammingScore;
    }
    float mathAvg = mathSum / numStudents;
    float englishAvg = englishSum / numStudents;
    float cAvg = cSum / numStudents;

    // Print average for each course
    printf("\n");
    printf("Average Math score: %.2f\n", mathAvg);
    printf("Average English score: %.2f\n", englishAvg);
    printf("Average C Programming score: %.2f\n", cAvg);
}

// Function to print all students
void printStudents()
{
    printf("\n");
    printf("List of Students:\n");
    for (int i = 0; i < numStudents; i++)
    {
        printf("Student %d: ID: %d, Name: %s, Class: %d, Math: %.2f, English: %.2f, C Programming: %.2f\n",
               i + 1, students[i].id, students[i].name, students[i].class,
               students[i].mathScore, students[i].englishScore, students[i].cProgrammingScore);
    }
}