#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "include/Student.h"

#include "enroll/enrollStudent.cpp"

#include "display/displayPersonalinfo.cpp"
#include "add/modifyPersonalInfo.cpp"
#include "save/savePersonalInfoToFile.cpp"

#include "display/displayParental.cpp"
#include "add/addParentalinfo.cpp"
#include "load/buildBST.cpp"
#include "load/updateParentalInfo.cpp"

#include "load/InsertAcademicinfo.cpp"
#include "display/displayAcademicinfo.cpp"
#include "save/saveAcademicInfo.cpp"
#include "load/loadAcademicInfo.cpp"

#include "add/addAttendanceInfo.cpp" 
#include "display/displayAttendanceInfo.cpp" 
#include "load/loadAttendanceInfo.cpp"

#include "add/addOrModifyFinancialInfo.cpp" 
#include "display/displayFinancialInfo.cpp"
#include "load/loadFinancialInfo.cpp"
#include "report/countStudents.cpp"

#include "display/displayFullStudentInfo.cpp"

using namespace std;

int main() {
    Student* root = buildBalancedBST("students.csv");
    
    const string studentFile = "data/students.csv";
    const string academicInfoFile = "data/academic_info.csv";
    const string attendanceInfoFile = "data/attendance_info.csv";
    const string parentalInfoFile = "data/parental_info.csv";
    const string financialInfoFile = "data/financial_info.csv";


    insertAcademicInfo(root, academicInfoFile);
    loadAttendanceInfo(root, attendanceInfoFile);
    updateParentalInfo(root, parentalInfoFile);
    loadFinancialInfo(root, financialInfoFile);

    // Load used IDs at program start
    loadUsedIDs();

    int options;
    do {
        system("cls");
        cout << "========== Student Management System ===========\n\n"
            << "1. Display Student Information\n"
            << "2. Student Report\n"
            << "3. Student Enroll\n"
            << "4. Modify Student Information\n"
            << "5. Request Transcript\n"
            << "\n================================================\n"
            << "0. Exit\n"
            << "================================================\n"
            << "=> Select an option: ";
        cin >> options;
        switch(options) {
            case 0: 
                system("cls");
                break;
            case 1:
                int option01;
                do {
                    system("cls");
                    cout << "========= Display Student Information ==========\n\n"
                        << "1. Personal Information\n"
                        << "2. Academic Performance\n"
                        << "3. Attendance Records\n"
                        << "4. Parental/Guardian Information\n"
                        << "5. Financial Information\n"
                        << "6. Display All Information\n"
                        << "\n================================================\n"
                        << "0. Back to menu\n"
                        << "================================================\n"
                        << "=> Select an option: ";
                    cin >> option01;
                    switch(option01) {
                        case 0:
                            system("cls");
                            break;
                        case 1:
                            system("cls");
                            int searchID; 
                            cout << "Enter Student ID to search: "; 
                            cin >> searchID; 
                            displayPersonalInfo(root, searchID);
                            cout << "<<<<< Press any key to go back >>>>>\n";
                            getch();
                            break;
                        case 2:
                            system("cls");
                            loadAcademicInfo(root, academicInfoFile);
                            cout << "Enter Student ID to search for academic information: "; 
                            cin >> searchID; 
                            displayAcademicInfo(root, searchID);
                            cout << "<<<<< Press any key to go back >>>>>\n";
                            getch();
                            break;
                        case 3:
                            system("cls");
                            loadAttendanceInfo(root, attendanceInfoFile);
                            cout << "Enter Student ID to display attendance information: "; 
                            cin >> searchID; 
                            displayAttendanceInfo(root, searchID);
                            cout << "<<<<< Press any key to go back >>>>>\n";
                            getch();
                            break;
                        case 4:
                            system("cls");
                            updateParentalInfo(root, parentalInfoFile);
                            cout << "Enter Student ID to search for parental information: "; 
                            cin >> searchID; 
                            displayParentalInfo(root, searchID);
                            cout << "<<<<< Press any key to go back >>>>>\n";
                            getch();
                            break;
                        case 5:
                            system("cls");
                            loadFinancialInfo(root, financialInfoFile);
                            cout << "Enter Student ID to display financial information: "; 
                            cin >> searchID; 
                            displayFinancialInfo(root, searchID);
                            getch();
                            break;
                        case 6:
                            system("cls");
                            insertAcademicInfo(root, academicInfoFile);
                            loadAttendanceInfo(root, attendanceInfoFile);
                            updateParentalInfo(root, parentalInfoFile);
                            loadFinancialInfo(root, financialInfoFile);
                            cout << "Enter Student ID to display all information: "; 
                            cin >> searchID; 
                            displayFullStudentInfo(root, searchID);
                            getch();
                            break;
                        default:
                            system("cls");
                            cout << "=== Invalid Option!!! ===\n"
                                << "<<<<< Press any key to go back >>>>>\n";
                            getch();
                            break;
                    }
                } while (option01 != 0);
                break;
            case 2:
                int option02;
                do {
                    system("cls");
                    cout << "========== Student Report ===========\n\n";
                    // Count the number of students who have not paid their fees 
                    int unpaidCount = countUnpaidStudents(root); 
                    cout << "Number of students who have not paid their fees: " << unpaidCount << endl; 
                    // Count the number of students who did not receive scholarships 
                    int noScholarshipCount = countNoScholarshipStudents(root); 
                    cout << "Number of students who did not receive scholarships: " << noScholarshipCount << endl;
                    cout << "\n================================================\n"
                        << "0. Back to menu\n"
                        << "================================================\n"
                        << "=> Select an option: ";
                    cin >> option02;
                    switch(option02) {
                        case 0:
                            system("cls");
                            break;
                        default:
                            system("cls");
                            cout << "=== Invalid Option!!! ===\n"
                                << "<<<<< Press any key to go back >>>>>\n";
                            getch();
                            break;
                    }
                } while (option02 != 0);
                break;
            case 3: 
                // Enroll a new student
                enrollStudent(root);
                break;
            case 4:
                int option04;
                do {
                    system("cls");
                    cout << "========== Modify Student Information ===========\n\n"
                        << "1. Modify Information\n"
                        << "2. Delete Information\n"
                        << "\n================================================\n"
                        << "0. Back to menu\n"
                        << "================================================\n"
                        << "=> Select an option: ";
                    cin >> option04;
                    switch(option04) {
                        case 0:
                            system("cls");
                            break;
                        case 1:
                            int option041;
                            do {
                                system("cls");
                                cout << "========== Modify Student Information ===========\n\n"
                                    << "1. Personal Information\n"
                                    << "2. Academic Performance\n"
                                    << "3. Attendance Records\n"
                                    << "4. Parental/Guardian Information\n"
                                    << "5. Financial Information\n"
                                    << "\n================================================\n"
                                    << "0. Back to menu\n"
                                    << "================================================\n"
                                    << "=> Select an option: ";
                                cin >> option041;
                                switch(option041) {
                                    case 0:
                                        system("cls");
                                        break;
                                    case 1:
                                        system("cls");
                                        int modifyID; 
                                        cout << "Enter Student ID to modify personal information: "; 
                                        cin >> modifyID; 
                                        modifyPersonalInfo(root, modifyID);
                                        getch();
                                        break;
                                    case 2:
                                        system("cls");
                                        int academicID;
                                        cout << "Enter Student ID to add academic performance information: "; 
                                        cin >> academicID;
                                        addOrModifyAcademicInfo(academicID);
                                        cout << "<<<<< Press any key to go back >>>>>\n";
                                        getch();
                                        break;
                                    case 3:
                                        int searchID;
                                        system("cls");
                                        cout << "Enter Student ID to add attendance information: "; 
                                        cin >> searchID; 
                                        addAttendanceInfo(searchID);
                                        cout << "<<<<< Press any key to go back >>>>>\n";
                                        getch();
                                        break;
                                    case 4:
                                        system("cls");
                                        int parentID; 
                                        cout << "Enter Student ID to add parental information: "; 
                                        cin >> parentID; 
                                        addParentalInfo(parentID);
                                        cout << "<<<<< Press any key to go back >>>>>\n";
                                        getch();
                                        break;
                                    case 5:
                                        system("cls");
                                        int financialID; 
                                        cout << "Enter Student ID to add or modify financial information: "; 
                                        cin >> financialID; 
                                        addOrModifyFinancialInfo(financialID);
                                        getch();
                                        break;
                                    default:
                                        system("cls");
                                        cout << "=== Invalid Option!!! ===\n"
                                            << "<<<<< Press any key to go back >>>>>\n";
                                        getch();
                                        break;
                                }
                            } while (option041 != 0);
                            break;
                        case 2:
                            int option042;
                            do {
                                system("cls");
                                cout << "========== Delete Student Information ===========\n\n"
                                    << "1. Personal Information\n"
                                    << "2. Academic Performance\n"
                                    << "3. Attendance Records\n"
                                    << "4. Parental/Guardian Information\n"
                                    << "5. Financial Information\n"
                                    << "6. Delete All Information\n"
                                    << "\n================================================\n"
                                    << "0. Back to menu\n"
                                    << "================================================\n"
                                    << "=> Select an option: ";
                                cin >> option042;
                                switch(option042) {
                                    case 0:
                                        system("cls");
                                        break;
                                    case 1:
                                        system("cls");
                                        getch();
                                        break;
                                    case 2:
                                        system("cls");
                                        getch();
                                        break;
                                    case 3:
                                        system("cls");
                                        getch();
                                        break;
                                    case 4:
                                        system("cls");
                                        getch();
                                        break;
                                    case 5:
                                        system("cls");
                                        getch();
                                        break;
                                    case 6:
                                        system("cls");
                                        getch();
                                        break;
                                    default:
                                        system("cls");
                                        cout << "=== Invalid Option!!! ===\n"
                                            << "<<<<< Press any key to go back >>>>>\n";
                                        getch();
                                        break;
                                }
                            } while (option042 != 0);
                            break;
                        default:
                            system("cls");
                            cout << "=== Invalid Option!!! ===\n"
                                << "<<<<< Press any key to go back >>>>>\n";
                            getch();
                            break;
                    }
                } while (option04 != 0);
                break;
            case 5:
                int option05;
                do {
                    system("cls");
                    cout << "========== Request Report ===========\n\n"
                        << "1. Report of the type of scholarship \n"
                        << "2. Report of the type of GPA or Ranking\n"
                        << "3. Report of student by gender \n"
                        << "\n================================================\n"
                        << "0. Back to menu\n"
                        << "================================================\n"
                        << "=> Select an option: ";
                    cin >> option05;
                    switch(option05) {
                        case 0:
                            system("cls");
                            break;
                        case 1:
                            system("cls");
                            getch();
                            break; 
                        case 2:
                            system("cls");
                            getch();
                            break;                         
                        case 3:
                            system("cls");
                            getch();
                            break;                         
                        default :
                            system("cls");
                            cout << "=== Invalid Option!!! ===\n"
                                << "<<<<< Press any key to go back >>>>>\n";
                            getch();
                            break;
                    }
                } while (option05 != 0);
                break;
            default:
                system("cls");
                cout << "=== Invalid Option!!! ===\n"
                    << "<<<<< Press any key to go back >>>>>\n";
                getch();
                break;
        }
    } while (options != 0);
    return 0;
}