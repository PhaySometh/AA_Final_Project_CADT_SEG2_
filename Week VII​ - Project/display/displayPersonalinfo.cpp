#include <iostream>
#include "../include/Student.h"

using namespace std;

// Function to search the BST for a student by their ID and display personal information
void displayPersonalInfo(Student* root, int id) {
    if (root == nullptr) {
        cout << "Student ID not found." << endl;
        return;
    }

    if (id < root->studentID) {
        displayPersonalInfo(root->left, id);
    } else if (id > root->studentID) {
        displayPersonalInfo(root->right, id);
    } else {
        // ID matches, display the personal information
        cout << "Full Name: " << root->fullName << endl;
        cout << "Date of Birth: " << root->dateOfBirth << endl;
        cout << "Gender: " << root->gender << endl;
        cout << "Address: " << root->address << endl;
        cout << "Contact Number: " << root->contactNumber << endl;
        cout << "Emergency Contact Number: " << root->emergencyContactNumber << endl;
    }
}