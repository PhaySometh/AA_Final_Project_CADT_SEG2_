#include <iostream>
#include "../include/Student.h"

using namespace std;

// Function to search the BST for a student by their ID and display parental/guardian information
void displayParentalInfo(Student* root, int id) {
    if (root == nullptr) {
        cout << "Student ID not found." << endl;
        return;
    }

    if (id < root->studentID) {
        displayParentalInfo(root->left, id);
    } else if (id > root->studentID) {
        displayParentalInfo(root->right, id);
    } else {
        // ID matches, display the parental information
        cout << "Parent/Guardian Name: " << root->parentOrGuardianName << endl;
        cout << "First Contact Number: " << root->firstContactNumber << endl;
        cout << "Second Contact Number: " << root->secondContactNumber << endl;
        cout << "Occupation: " << root->occupation << endl;
        cout << "Relationship to Student: " << root->relationshipToStudent << endl;
    }
}