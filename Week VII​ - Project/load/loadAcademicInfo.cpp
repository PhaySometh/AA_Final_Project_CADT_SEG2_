#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Function to load academic information from a CSV file and update the BST
void loadAcademicInfo(Student* root, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int id, gradeLevel, subjects[10];
            char delim;
            string room, enrollDate;
            char gradePerformance;

            ss >> id >> delim >> gradeLevel >> delim;
            getline(ss, room, ',');
            getline(ss, enrollDate, ',');

            for (int i = 0; i < 10; ++i) {
                ss >> subjects[i] >> delim;
            }

            ss >> gradePerformance;

            // Find the student in the BST by ID and update the academic information
            Student* student = root;
            while (student != nullptr) {
                if (id == student->studentID) {
                    student->gradeLevel = gradeLevel;
                    student->room = room;
                    student->enrollDate = enrollDate;
                    for (int i = 0; i < 10; ++i) {
                        student->subjects[i] = subjects[i];
                    }
                    student->gradePerformance = gradePerformance;
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