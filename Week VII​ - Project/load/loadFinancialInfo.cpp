#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Function to load financial information from a CSV file and update the BST
void loadFinancialInfo(Student* root, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int id;
            float tuitionFeeAmount;
            string tuitionFeeStatus, scholarshipName;
            char delim;

            ss >> id >> delim;
            getline(ss, tuitionFeeStatus, ',');
            ss >> tuitionFeeAmount >> delim;
            getline(ss, scholarshipName, ',');

            // Find the student in the BST by ID and update the financial information
            Student* student = root;
            while (student != nullptr) {
                if (id == student->studentID) {
                    student->tuitionFeeStatus = tuitionFeeStatus;
                    student->tuitionFeeAmount = tuitionFeeAmount;
                    student->scholarshipName = scholarshipName;
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