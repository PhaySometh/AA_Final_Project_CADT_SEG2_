#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Helper function to load all students' information into a vector
vector<string> loadAllStudentsInfo(const string& filename) {
    vector<string> lines;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    return lines;
}

// Function to save personal information to a CSV file
void savePersonalInfoToFile(Student* root, const string& filename) {
    vector<string> lines = loadAllStudentsInfo(filename);
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& line : lines) {
            stringstream ss(line);
            int id;
            char delim;
            ss >> id >> delim;
            if (id == root->studentID) {
                file << root->studentID << ","
                     << root->fullName << ","
                     << root->dateOfBirth << ","
                     << root->gender << ","
                     << root->address << ","
                     << root->contactNumber << ","
                     << root->emergencyContactNumber << "\n";
            } else {
                file << line << "\n";
            }
        }
        file.close();
        cout << "\nPersonal information saved to file successfully.\n";
    } else {
        cerr << "Unable to open file" << endl;
    }
}