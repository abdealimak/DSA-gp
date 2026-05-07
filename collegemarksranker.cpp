/************************************************************
 *  COLLEGE MARKS RANKER (DSA PROJECT BASE CODE)
 *
 *  INSTRUCTIONS:
 *  1. DO NOT change the Student structure.
 *  2. DO NOT change function names already declared.
 *  3. Each member will implement ONLY their assigned part.
 *  4. Use SAME array 'students' for all operations.
 *  5. Sorting must be done on a COPY of original data.
 *
 *  TEAM DIVISION:
 *  P1 -> Linear Search + Fail Risk Students
 *  P2 -> Bubble Sort + Selection Sort + Step Counter
 *  P3 -> Insertion Sort + Merge Sort + Step Counter
 *  P4 -> Quick Sort + Binary Search + Comparison Table
 *
 ************************************************************/

#include <iostream>
#include <cstring>
#include <chrono> // for time measurement
using namespace std;
using namespace std::chrono;

#define MAX 20

/********************* STUDENT STRUCTURE *********************/
struct Student {
    int roll;
    char name[50];
    int marks[5];
    float avg;
};

/********************* GLOBAL DATA ***************************/
Student students[MAX];
int n;

/********************* COMMON FUNCTIONS **********************/

// Calculate average marks
void calculateAvg(Student &s) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += s.marks[i];
    }
    s.avg = sum / 5.0;
}

// Input student data
void inputStudents() {
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Roll: ";
        cin >> students[i].roll;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Enter 5 subject marks: ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].marks[j];
        }

        calculateAvg(students[i]);
    }
}

// Display students
void display(Student s[], int size) {
    cout << "\nRoll\tName\tAvg\n";
    for (int i = 0; i < size; i++) {
        cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].avg << endl;
    }
}

// Copy array (IMPORTANT for fair comparison)
void copyArray(Student dest[], Student src[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

/********************* P1 FUNCTIONS **************************/
// TODO (P1): Implement Linear Search by roll number
int linearSearch(int roll) {
    // WRITE YOUR CODE HERE
    return -1;
}

// TODO (P1): Print fail-risk students (avg < 40)
void findFailRisk() {
    // WRITE YOUR CODE HERE
}

/********************* P2 FUNCTIONS **************************/
// TODO (P2): Bubble Sort by avg + step counter
void bubbleSort(Student s[], int size, int &steps) {
    // WRITE YOUR CODE HERE
}

// TODO (P2): Selection Sort by avg + step counter
void selectionSort(Student s[], int size, int &steps) {
    // WRITE YOUR CODE HERE
}

/********************* P3 FUNCTIONS **************************/
// TODO (P3): Insertion Sort by avg + step counter
void insertionSort(Student s[], int size, int &steps) {
    // WRITE YOUR CODE HERE
}

// TODO (P3): Merge Sort by avg + step counter
void mergeSort(Student s[], int left, int right, int &steps) {
    // WRITE YOUR CODE HERE
}

/********************* P4 FUNCTIONS **************************/
// TODO (P4): Quick Sort by avg + step counter
void quickSort(Student s[], int low, int high, int &steps) {
    // WRITE YOUR CODE HERE
}

// TODO (P4): Binary Search by name (AFTER sorting)
int binarySearch(Student s[], int size, char key[]) {
    // WRITE YOUR CODE HERE
    return -1;
}

// TODO (P4): Compare all algorithms (steps + time)
void compareAlgorithms() {
    Student temp[MAX];
    int steps;

    cout << "\nAlgorithm Comparison:\n";

    // Example structure (complete for all sorts)

    // Bubble Sort
    copyArray(temp, students, n);
    steps = 0;
    auto start = high_resolution_clock::now();
    bubbleSort(temp, n, steps);
    auto end = high_resolution_clock::now();
    cout << "Bubble Sort -> Steps: " << steps
         << " Time: " << duration_cast<microseconds>(end - start).count()
         << " us\n";

    // TODO: Repeat same for all 5 sorts
}

/********************* MAIN FUNCTION *************************/
int main() {

    inputStudents();

    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Linear Search (Roll)\n";
        cout << "2. Binary Search (Name)\n";
        cout << "3. Display Students\n";
        cout << "4. Fail Risk Students\n";
        cout << "5. Compare Sorting Algorithms\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                int roll;
                cout << "Enter roll: ";
                cin >> roll;
                int index = linearSearch(roll);
                if (index != -1)
                    cout << "Found: " << students[index].name << endl;
                else
                    cout << "Not Found\n";
                break;
            }

            case 2: {
                char name[50];
                cout << "Enter name: ";
                cin >> name;
                int index = binarySearch(students, n, name);
                if (index != -1)
                    cout << "Found: Roll " << students[index].roll << endl;
                else
                    cout << "Not Found\n";
                break;
            }

            case 3:
                display(students, n);
                break;

            case 4:
                findFailRisk();
                break;

            case 5:
                compareAlgorithms();
                break;
        }

    } while (choice != 0);

    return 0;
}