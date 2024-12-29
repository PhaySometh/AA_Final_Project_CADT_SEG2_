#include <iostream>
#include "../include/Student.h"

using namespace std;

// Function to display financial information of a student based on their ID
void displayFinancialInfo(Student* root, int id) {
    if (root == nullptr) {
        cout << "Student ID not found." << endl;
        return;
    }

    if (id < root->studentID) {
        displayFinancialInfo(root->left, id);
    } else if (id > root->studentID) {
        displayFinancialInfo(root->right, id);
    } else {
        // ID matches, display the financial information
        cout << "Tuition Fee Status: " << root->tuitionFeeStatus << endl;
        cout << "Tuition Fee Amount: $" << root->tuitionFeeAmount << endl;
        cout << "Scholarship Name: " << root->scholarshipName << endl;
    }
}