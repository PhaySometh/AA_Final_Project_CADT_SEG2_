#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Student.h"

using namespace std;

// Function to add parental information for a student and save it to another file
void addParentalInfo(int id) {
    string parentOrGuardianName, firstContactNumber, secondContactNumber, occupation, relationshipToStudent;
    
    cout << "Enter Parent or Guardian Name: ";
    cin.ignore();
    getline(cin, parentOrGuardianName);
    
    cout << "Enter First Contact Number: ";
    getline(cin, firstContactNumber);
    
    cout << "Enter Second Contact Number: ";
    getline(cin, secondContactNumber);
    
    cout << "Enter Occupation: ";
    getline(cin, occupation);
    
    cout << "Enter Relationship to Student: ";
    getline(cin, relationshipToStudent);

    // Save parental information to another CSV file
    ofstream file("parental_info.csv", ios::app);
    if (file.is_open()) {
        file << id << ","
             << parentOrGuardianName << ","
             << firstContactNumber << ","
             << secondContactNumber << ","
             << occupation << ","
             << relationshipToStudent << "\n";
        file.close();
        cout << "\nParental information saved successfully.\n";
    } else {
        cerr << "Unable to open file" << endl;
    }
}