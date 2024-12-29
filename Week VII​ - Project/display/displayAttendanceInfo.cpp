#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Function to display attendance information of a student based on their ID
void displayAttendanceInfo(Student* root, int id) {
    if (root == nullptr) {
        cout << "Student ID not found." << endl;
        return;
    }

    if (id < root->studentID) {
        displayAttendanceInfo(root->left, id);
    } else if (id > root->studentID) {
        displayAttendanceInfo(root->right, id);
    } else {
        // ID matches, display the attendance information
        cout << "Total Days Present: " << root->totalDaysPresent << endl;
        cout << "Total Days Absent: " << root->totalDaysAbsent << endl;
        cout << "Attendance Percentage: " << root->attendancePercentage << "%" << endl;
    }
}