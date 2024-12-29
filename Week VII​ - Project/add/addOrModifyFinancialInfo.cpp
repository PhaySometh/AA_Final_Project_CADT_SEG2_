#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Function to add or modify financial information for a student and save it to a file
void addOrModifyFinancialInfo(int id) {
    string tuitionFeeStatus;
    float tuitionFeeAmount;
    string scholarshipName;

    cout << "Enter Tuition Fee Status (Paid): ";
    cin.ignore();
    getline(cin, tuitionFeeStatus);

    cout << "Enter Tuition Fee Amount: ";
    cin >> tuitionFeeAmount;

    cout << "Enter Scholarship Name: ";
    cin.ignore();
    getline(cin, scholarshipName);

    // Load existing financial information from file
    vector<string> lines;
    bool found = false;
    ifstream inFile("financial_info.csv");
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
                        << tuitionFeeStatus << ","
                        << tuitionFeeAmount << ","
                        << scholarshipName;
                lines.push_back(newLine.str());
            } else {
                lines.push_back(line);
            }
        }
        inFile.close();
    }

    if (!found) {
        stringstream newLine;
        newLine << id << ","
                << tuitionFeeStatus << ","
                << tuitionFeeAmount << ","
                << scholarshipName;
        lines.push_back(newLine.str());
    }

    // Save updated financial information to file
    ofstream outFile("financial_info.csv");
    if (outFile.is_open()) {
        for (const auto& line : lines) {
            outFile << line << "\n";
        }
        outFile.close();
        cout << "\nFinancial information saved successfully.\n";
    } else {
        cerr << "Unable to open file" << endl;
    }
}