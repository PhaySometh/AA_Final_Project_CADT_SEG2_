#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/Student.h"

using namespace std;

// Function to calculate grade performance based on the average score
// char calculateGradePerformance(int subjects[10]) {
//     int sum = 0;
//     for (int i = 0; i < 10; ++i) {
//         sum += subjects[i];
//     }
//     int average = sum / 10;

//     if (average >= 90) return 'A';
//     else if (average >= 80) return 'B';
//     else if (average >= 70) return 'C';
//     else if (average >= 60) return 'D';
//     else return 'F';
// }

// Function to add or modify academic information for a student and save it to the file
void addOrModifyAcademicInfo(int id) {
    int gradeLevel;
    string room, enrollDate;
    int subjects[10];
    char gradePerformance;
    
    cout << "Enter Grade Level: ";
    cin >> gradeLevel;
    cin.ignore(); // To ignore the newline character left by previous input

    cout << "Enter Room: ";
    getline(cin, room);

    cout << "Enter Enroll Date (YYYY-MM-DD): ";
    getline(cin, enrollDate);

    cout << "Enter scores for the following subjects:\n";
    string subjectNames[10] = {
        "Mathematics", "Science", "History", "Geography",
        "English", "Arts", "Physical Education", "Music",
        "Computer Science", "Foreign Language"
    };
    for (int i = 0; i < 10; ++i) {
        cout << subjectNames[i] << ": ";
        cin >> subjects[i];
    }

    gradePerformance = calculateGradePerformance(subjects);

    // Load existing academic information
    vector<string> lines;
    ifstream inFile("academic_info.csv");
    string line;
    bool found = false;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            stringstream ss(line);
            int existingID;
            ss >> existingID;
            if (existingID == id) {
                found = true;
                // Replace existing information with new data
                stringstream newLine;
                newLine << id << ","
                        << gradeLevel << ","
                        << room << ","
                        << enrollDate << ",";
                for (int i = 0; i < 10; ++i) {
                    newLine << subjects[i];
                    if (i < 9) {
                        newLine << ",";
                    }
                }
                newLine << "," << gradePerformance;
                lines.push_back(newLine.str());
            } else {
                lines.push_back(line);
            }
        }
        inFile.close();
    }

    // If ID not found, add new information
    if (!found) {
        stringstream newLine;
        newLine << id << ","
                << gradeLevel << ","
                << room << ","
                << enrollDate << ",";
        for (int i = 0; i < 10; ++i) {
            newLine << subjects[i];
            if (i < 9) {
                newLine << ",";
            }
        }
        newLine << "," << gradePerformance;
        lines.push_back(newLine.str());
    }

    // Save updated academic information to the file
    ofstream outFile("academic_info.csv");
    if (outFile.is_open()) {
        for (const auto& entry : lines) {
            outFile << entry << "\n";
        }
        outFile.close();
        cout << "\nAcademic information saved successfully.\n";
    } else {
        cerr << "Unable to open file" << endl;
    }
}
