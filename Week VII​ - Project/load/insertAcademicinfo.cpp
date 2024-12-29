#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Function to calculate grade performance based on the average score
char calculateGradePerformance(int subjects[10]) {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += subjects[i];
    }
    int average = sum / 10;

    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

// Function to insert academic information into the BST
void insertAcademicInfo(Student* root, const string& filename) {
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

            gradePerformance = calculateGradePerformance(subjects);

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