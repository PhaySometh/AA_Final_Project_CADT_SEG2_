#include <iostream>
#include "../include/Student.h"

using namespace std;

// Function to modify personal information of a student based on their ID
void modifyPersonalInfo(Student* root, int id) {
    if (root == nullptr) {
        cout << "Student ID not found." << endl;
        return;
    }

    if (id < root->studentID) {
        modifyPersonalInfo(root->left, id);
    } else if (id > root->studentID) {
        modifyPersonalInfo(root->right, id);
    } else {
        // ID matches, prompt for new personal information
        cout << "Enter new Full Name: ";
        cin.ignore();
        getline(cin, root->fullName);

        cout << "Enter new Date of Birth (YYYY-MM-DD): ";
        getline(cin, root->dateOfBirth);

        cout << "Enter new Gender (M/F): ";
        cin >> root->gender;

        cout << "Enter new Address: ";
        cin.ignore();
        getline(cin, root->address);

        cout << "Enter new Contact Number: ";
        getline(cin, root->contactNumber);

        cout << "Enter new Emergency Contact Number: ";
        getline(cin, root->emergencyContactNumber);

        cout << "\nPersonal information updated successfully.\n";

        // Save the updated personal information back to the file
        savePersonalInfoToFile(root, "students.csv");
    }
}