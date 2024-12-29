#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Function to calculate attendance percentage
float calculateAttendancePercentage(int totalDaysPresent, int totalDaysAbsent) {
    int totalDays = totalDaysPresent + totalDaysAbsent;
    if (totalDays == 0) return 0;
    return (static_cast<float>(totalDaysPresent) / totalDays) * 100;
}

// Function to add attendance information for a student and save it to a file
void addAttendanceInfo(int id) {
    int totalDaysPresent, totalDaysAbsent;

    cout << "Enter Total Days Present: ";
    cin >> totalDaysPresent;

    cout << "Enter Total Days Absent: ";
    cin >> totalDaysAbsent;

    float attendancePercentage = calculateAttendancePercentage(totalDaysPresent, totalDaysAbsent);

    // Load existing attendance information from file
    vector<string> lines;
    bool found = false;
    ifstream inFile("attendance_info.csv");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            int existingID;
            ss >> existingID;
            if (existingID == id) {
                found = true;
                stringstream newLine;
                newLine << id << ","
                        << totalDaysPresent << ","
                        << totalDaysAbsent << ","
                        << attendancePercentage;
                lines.push_back(newLine.str());
            } else {
                lines.push_back(line);
            }
        }
        inFile.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    if (!found) {
        stringstream newLine;
        newLine << id << ","
                << totalDaysPresent << ","
                << totalDaysAbsent << ","
                << attendancePercentage;
        lines.push_back(newLine.str());
    }

    // Save updated attendance information to file
    ofstream outFile("attendance_info.csv");
    if (outFile.is_open()) {
        for (const auto& line : lines) {
            outFile << line << "\n";
        }
        outFile.close();
        cout << "\nAttendance information saved successfully.\n";
    } else {
        cerr << "Unable to open file" << endl;
    }
}