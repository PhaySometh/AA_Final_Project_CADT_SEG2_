#include <iostream>
#include "../include/Student.h"

using namespace std;

// Function to count students who have not paid their fees
int countUnpaidStudents(Student* root) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;
    if (root->tuitionFeeStatus != "Paid") {
        count = 1;
    }

    return count + countUnpaidStudents(root->left) + countUnpaidStudents(root->right);
}

// Function to count students who did not receive scholarships
int countNoScholarshipStudents(Student* root) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;
    if (root->scholarshipName.empty()) {
        count = 1;
    }

    return count + countNoScholarshipStudents(root->left) + countNoScholarshipStudents(root->right);
}