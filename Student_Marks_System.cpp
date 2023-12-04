#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;
};

void addStudent(const string& fileName) {
    ofstream outFile(fileName, ios::app);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    Student newStudent;

    cout << "Enter student name: ";
    getline(cin, newStudent.name);

    cout << "Enter student score: ";
    cin >> newStudent.score;

    // Flush the newline character from the buffer
    cin.ignore();

    outFile << newStudent.name << " " << newStudent.score << endl;

    cout << "Student added successfully.\n";
    outFile.close();
}

void displayStudents(const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    Student student;

    cout << "Student List:\n";
    cout << "-----------------\n";
    cout << "Name\tScore\n";

    while (inFile >> student.name >> student.score) {
        cout << student.name << "\t" << student.score << endl;
    }

    inFile.close();
}

int main() {
    const string fileName = "student_data.txt";
    int choice;

    do {
        cout << "\nSimple Student Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Flush the newline character from the buffer
                addStudent(fileName);
                break;
            case 2:
                displayStudents(fileName);
                break;
            case 3:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
