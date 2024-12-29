#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../include/Student.h"

using namespace std;

// Function to read students from CSV and return a vector of Student pointers
vector<Student*> readStudentsFromCSV(const string& filename) {
    vector<Student*> students;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int id;
            char delim;
            string fullName, dateOfBirth, gender, address, contactNumber, emergencyContactNumber;

            ss >> id >> delim;
            getline(ss, fullName, ',');
            getline(ss, dateOfBirth, ',');
            getline(ss, gender, ',');
            if (ss.peek() == '"') {
                ss.ignore(); // Ignore the opening quote of the address
                getline(ss, address, '"');
                ss.ignore(); // Ignore the closing quote and comma
            } else {
                getline(ss, address, ',');
            }
            getline(ss, contactNumber, ',');
            getline(ss, emergencyContactNumber, ',');

            students.push_back(new Student(id, fullName, dateOfBirth, gender[0], address, contactNumber, emergencyContactNumber));
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }
    return students;
}

// Function to build a balanced BST from sorted student IDs
Student* buildBST(vector<Student*>& students, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Student* root = students[mid];

    root->left = buildBST(students, start, mid - 1);
    root->right = buildBST(students, mid + 1, end);

    return root;
}

// Function to build a balanced BST from the student file
Student* buildBalancedBST(const string& filename) {
    vector<Student*> students = readStudentsFromCSV(filename);

    // Sort students based on their IDs
    sort(students.begin(), students.end(), [](Student* a, Student* b) {
        return a->studentID < b->studentID;
    });

    // Build a balanced BST
    return buildBST(students, 0, students.size() - 1);
}