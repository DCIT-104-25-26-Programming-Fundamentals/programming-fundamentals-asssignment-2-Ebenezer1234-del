// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void addStudent(vector<Student>& students) {
    Student student;
    int numScores;

    cout << "Student name: ";
    getline(cin >> ws, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 1; i <= numScores; i++) {
        double score;
        cout << "Enter score " << i << ": ";
        cin >> score;
        student.scores.push_back(score);
    }

    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully." << endl;
}

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) {
        return 0.0;
    }

    double total = 0.0;
    for (size_t i = 0; i < scores.size(); i++) {
        total += scores[i];
    }
    return total / scores.size();
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available." << endl;
        return;
    }

    cout << left << setw(20) << "Name" << setw(12) << "ID" << "Scores" << "\tAverage" << endl;
    cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

    for (size_t i = 0; i < students.size(); i++) {
        cout << left << setw(20) << students[i].name
             << setw(12) << students[i].id;

        for (size_t j = 0; j < students[i].scores.size(); j++) {
            cout << students[i].scores[j];
            if (j + 1 < students[i].scores.size()) {
                cout << ", ";
            }
        }

        cout << "\t" << fixed << setprecision(2) << calculateAverage(students[i].scores) << endl;
    }
}

void calculateAverageForStudent(const vector<Student>& students) {
    int targetId;
    cout << "Enter student ID: ";
    cin >> targetId;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == targetId) {
            cout << students[i].name << "'s average score: "
                 << fixed << setprecision(2) << calculateAverage(students[i].scores) << endl;
            return;
        }
    }

    cout << "Student ID not found." << endl;
}

void showMenu() {
    cout << "\n================================" << endl;
    cout << "    STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

