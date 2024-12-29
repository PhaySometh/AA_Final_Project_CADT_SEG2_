#include <iostream>
#include "../include/Student.h"

using namespace std;

// Function to display academic performance information of a student based on their ID
void displayAcademicInfo(Student* root, int id) {
    if (root == nullptr) {
        cout << "Student ID not found." << endl;
        return;
    }

    if (id < root->studentID) {
        displayAcademicInfo(root->left, id);
    } else if (id > root->studentID) {
        displayAcademicInfo(root->right, id);
    } else {
        // ID matches, display the academic performance information
        cout << "Grade Level: " << root->gradeLevel << endl;
        cout << "Room: " << root->room << endl;
        cout << "Enroll Date: " << root->enrollDate << endl;
        cout << "Subjects and Scores:" << endl;

        string subjectNames[10] = {
            "Mathematics", "Science", "History", "Geography",
            "English", "Arts", "Physical Education", "Music",
            "Computer Science", "Foreign Language"
        };

        for (int i = 0; i < 10; ++i) {
            cout << subjectNames[i] << ": " << root->subjects[i] << endl;
        }

        cout << "Grade Performance: " << root->gradePerformance << endl;
    }
}