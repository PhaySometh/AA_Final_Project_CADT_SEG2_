#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Function to update parental/guardian information in the BST
void updateParentalInfo(Student* root, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int id;
            char delim;
            string parentOrGuardianName, firstContactNumber, secondContactNumber, occupation, relationshipToStudent;

            ss >> id >> delim;
            getline(ss, parentOrGuardianName, ',');
            getline(ss, firstContactNumber, ',');
            getline(ss, secondContactNumber, ',');
            getline(ss, occupation, ',');
            getline(ss, relationshipToStudent, ',');

            // Find the student in the BST by ID and update the parental information
            Student* student = root;
            while (student != nullptr) {
                if (id == student->studentID) {
                    student->parentOrGuardianName = parentOrGuardianName;
                    student->firstContactNumber = firstContactNumber;
                    student->secondContactNumber = secondContactNumber;
                    student->occupation = occupation;
                    student->relationshipToStudent = relationshipToStudent;
                    break;
                } else if (id < student->studentID) {
                    student = student->left;
                } else {
                    student = student->right;
                }
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }
}