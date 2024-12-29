#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Function to load attendance information from a CSV file and update the BST
void loadAttendanceInfo(Student* root, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int id, totalDaysPresent, totalDaysAbsent;
            float attendancePercentage;
            char delim;

            ss >> id >> delim >> totalDaysPresent >> delim >> totalDaysAbsent >> delim >> attendancePercentage;

            // Find the student in the BST by ID and update the attendance information
            Student* student = root;
            while (student != nullptr) {
                if (id == student->studentID) {
                    student->totalDaysPresent = totalDaysPresent;
                    student->totalDaysAbsent = totalDaysAbsent;
                    student->attendancePercentage = attendancePercentage;
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