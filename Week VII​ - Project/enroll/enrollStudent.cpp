#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include "../include/Student.h"

using namespace std;

vector<int> usedIDs; // Define the static vector

// Function to read used IDs from CSV file
void loadUsedIDs() {
    ifstream file("students.csv");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int id;
            ss >> id;
            usedIDs.push_back(id);
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }
    sort(usedIDs.begin(), usedIDs.end()); // Sort the IDs for efficient binary search
}

// Function to generate a unique Student ID
int generateStudentID() {
    int id;
    srand(time(nullptr)); // Seed for random number generation
    do {
        id = rand() % 100000 + 1; // Generate random ID within a range (e.g., 1 to 100000)
    } while (binary_search(usedIDs.begin(), usedIDs.end(), id)); // Ensure ID is unique
    usedIDs.push_back(id);
    sort(usedIDs.begin(), usedIDs.end()); // Maintain sorted order
    return id;
}

// Function to insert a student into the BST
void insertToBST(Student*& root, Student* newStudent) {
    if (root == nullptr) {
        root = newStudent;
    } else if (newStudent->studentID < root->studentID) {
        insertToBST(root->left, newStudent);
    } else {
        insertToBST(root->right, newStudent);
    }
}

// Function to save a student's information to a CSV file
void saveStudentToCSV(Student* student) {
    ofstream file("students.csv", ios::app);
    if (file.is_open()) {
        file << student->studentID << ","
             << student->fullName << ","
             << student->dateOfBirth << ","
             << student->gender << ","
             << "\"" << student->address << "\"" << "," // Enclose address in double quotes
             << student->contactNumber << ","
             << student->emergencyContactNumber << "\n";
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }
}

// Function to enroll a student
Student* enrollStudent(Student*& root) {
    int id = generateStudentID();
    string fullName, dateOfBirth, gender, address, contactNumber, emergencyContactNumber;

    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, fullName);
    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    getline(cin, dateOfBirth);
    cout << "Enter Gender (M/F): ";
    cin >> gender;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Contact Number: ";
    getline(cin, contactNumber);
    cout << "Enter Emergency Contact Number: ";
    getline(cin, emergencyContactNumber);

    // Create a new Student object using the parameterized constructor
    Student* newStudent = new Student(id, fullName, dateOfBirth, gender[0], address, contactNumber, emergencyContactNumber);

    // Insert new student into the BST
    insertToBST(root, newStudent);

    // Save to CSV file
    saveStudentToCSV(newStudent);

    return newStudent;
}