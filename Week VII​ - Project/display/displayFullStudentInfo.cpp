#include <iostream>
#include "../include/Student.h"

using namespace std;

// Function to display all information of a student based on their ID
void displayFullStudentInfo(Student* root, int id) {
    if (root == nullptr) {
        cout << "Student ID not found." << endl;
        return;
    }

    if (id < root->studentID) {
        displayFullStudentInfo(root->left, id);
    } else if (id > root->studentID) {
        displayFullStudentInfo(root->right, id);
    } else {
        // ID matches, display all the information
        cout << "Student ID: " << root->studentID << endl;
        cout << "Full Name: " << root->fullName << endl;
        cout << "Date of Birth: " << root->dateOfBirth << endl;
        cout << "Gender: " << root->gender << endl;
        cout << "Address: " << root->address << endl;
        cout << "Contact Number: " << root->contactNumber << endl;
        cout << "Emergency Contact Number: " << root->emergencyContactNumber << endl;

        // Display academic information
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

        // Display attendance information
        cout << "Total Days Present: " << root->totalDaysPresent << endl;
        cout << "Total Days Absent: " << root->totalDaysAbsent << endl;
        cout << "Attendance Percentage: " << root->attendancePercentage << "%" << endl;

        // Display parental/guardian information
        cout << "Parent or Guardian Name: " << root->parentOrGuardianName << endl;
        cout << "First Contact Number: " << root->firstContactNumber << endl;
        cout << "Second Contact Number: " << root->secondContactNumber << endl;
        cout << "Occupation: " << root->occupation << endl;
        cout << "Relationship to Student: " << root->relationshipToStudent << endl;

        // Display financial information
        cout << "Tuition Fee Status: " << root->tuitionFeeStatus << endl;
        cout << "Tuition Fee Amount: $" << root->tuitionFeeAmount << endl;
        cout << "Scholarship Name: " << root->scholarshipName << endl;

        cout << "----------------------------------------" << endl;
    }
}