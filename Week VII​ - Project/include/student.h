#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student {
    public:
        // Personal Information
        string fullName;
        string dateOfBirth;
        char gender;
        string address;
        string contactNumber;
        string emergencyContactNumber;

        // Academic Performance
        int studentID;
        int gradeLevel;
        string room;
        string enrollDate;
        int subjects[10];
        char gradePerformance;

        // Attendance Records
        int totalDaysPresent;
        int totalDaysAbsent;
        float attendancePercentage;

        // Parental/Guardian Information
        string parentOrGuardianName;
        string firstContactNumber;
        string secondContactNumber;
        string occupation;
        string relationshipToStudent;

        // Financial Information 
        string tuitionFeeStatus; 
        float tuitionFeeAmount; 
        string scholarshipName;

        // For BST
        Student* left;
        Student* right;

        // Constructor to initialize pointers
        Student(int id, const string& name, const string& dob, char gen, const string& addr, const string& contact, const string& emergency) 
        : studentID(id), fullName(name), dateOfBirth(dob), gender(gen), address(addr), contactNumber(contact), emergencyContactNumber(emergency), left(nullptr), right(nullptr) {}

        // Default constructor 
        Student() : left(nullptr), right(nullptr) {}
};

// Extern declarations for static variables and functions
extern vector<int> usedIDs;

extern void loadUsedIDs();
extern int generateStudentID();
extern void insertToBST(Student*& root, Student* newStudent);
extern void saveStudentToCSV(Student* student);
extern Student* enrollStudent(Student*& root);

// Function to display personal information
void displayPersonalInfo(int id);
void modifyPersonalInfo(Student* root, int id);
void savePersonalInfoToFile(Student* root, const string& filename);
vector<string> loadAllStudentsInfo(const string& filename);

void displayParentalInfo(Student* root, int id);
void addParentalInfo(int id);

void insertAcademicInfo(Student* root, const string& filename); 
void displayAcademicInfo(Student* root, int id);
void addOrModifyAcademicInfo(int id);
void loadAcademicInfo(Student* root, const string& filename);

void addAttendanceInfo(int id); 
void displayAttendanceInfo(Student* root, int id);
void loadAttendanceInfo(Student* root, const string& filename);

void addOrModifyFinancialInfo(int id); 
void displayFinancialInfo(Student* root, int id);

Student* buildBalancedBST(const string& filename);

void updateParentalInfo(Student* root, const string& filename);

void countStudentsPerGrade(const Student* root);


#endif // STUDENT_H