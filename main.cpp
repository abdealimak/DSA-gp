#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

// ==============================================================================
// GLOBAL DEFINITIONS & DATA STRUCTURES
// Contributor: Abdeali Makda
// ==============================================================================
const int MAX_STUDENTS = 20;

struct Student {
    int rollNo;
    string name;
    int marks[5]; // Marks for 5 subjects
    double avg;
};

// Global array and counter as per constraints (no vectors, max size 20)
Student database[MAX_STUDENTS];
int currentStudentCount = 0;

// Utility function to copy arrays so algorithms work on copies
// Used before sorting algorithms and searches.
void copyArray(const Student src[], Student dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Utility function to print a student's data
void printStudent(const Student& s) {
    cout << left << setw(8) << s.rollNo 
         << setw(20) << s.name 
         << "Marks: [" << s.marks[0] << "," << s.marks[1] << "," 
         << s.marks[2] << "," << s.marks[3] << "," << s.marks[4] << "] "
         << "Avg: " << fixed << setprecision(2) << s.avg << endl;
}

// Utility function to display the entire array
void displayArray(const Student arr[], int n) {
    cout << string(70, '-') << endl;
    for (int i = 0; i < n; i++) {
        printStudent(arr[i]);
    }
    cout << string(70, '-') << endl;
}


// ==============================================================================
// CONTRIBUTOR: Aayush Jadhav
// Role: Student records + Linear Search + fail-risk flag
// ==============================================================================

// Function to manually add a student record from CLI
// Used in the main menu for data entry.
void addStudentRecord() {
    if (currentStudentCount >= MAX_STUDENTS) {
        cout << "Database is full! Cannot add more students (Max 20).\n";
        return;
    }
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    
    double total = 0;
    cout << "Enter marks for 5 subjects (separated by space): ";
    for (int i = 0; i < 5; i++) {
        cin >> s.marks[i];
        total += s.marks[i];
    }
    s.avg = total / 5.0;
    
    database[currentStudentCount] = s;
    currentStudentCount++;
    cout << "Student added successfully!\n";
}

// Linear search to find a student by roll number
// Used in the main menu. Time Complexity: O(n)
void linearSearchByRollNo(int targetRoll) {
    bool found = false;
    cout << "\n--- Linear Search ---\n";
    for (int i = 0; i < currentStudentCount; i++) {
        if (database[i].rollNo == targetRoll) {
            cout << "Student found at index " << i << ":\n";
            printStudent(database[i]);
            found = true;
            break; // Stop searching once found
        }
    }
    if (!found) {
        cout << "Student with Roll No " << targetRoll << " not found.\n";
    }
}

// Scans the array in O(n) time to find students with avg < 40
// Used in the main menu. Time Complexity: O(n)
void flagFailRiskStudents() {
    cout << "\n--- Fail-Risk Students (Avg < 40) ---\n";
    bool riskFound = false;
    for (int i = 0; i < currentStudentCount; i++) {
        if (database[i].avg < 40.0) {
            printStudent(database[i]);
            riskFound = true;
        }
    }
    if (!riskFound) {
        cout << "No fail-risk students found! Everyone is passing.\n";
    }
}


// ==============================================================================
// CONTRIBUTOR: Yatharth Mishra
// Role: Bubble Sort + Selection Sort + step counter
// ==============================================================================

// Bubble Sort implementation based on average marks (Descending for Rank)
// Steps counter tracks comparisons and swaps.
void bubbleSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Bubble Sort\n";
        cout << "Time Complexity: O(n^2) | Space Complexity: O(1)\n";
    }
    steps = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            steps++; // Comparison count
            if (arr[j].avg < arr[j + 1].avg) {
                // Swap logic without pointers
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                steps++; // Swap step count
            }
        }
        if(visualize) {
            cout << "Pass " << i + 1 << " complete. Array state:\n";
            displayArray(arr, n);
        }
        if (!swapped) break; // Optimization if already sorted
    }
}

// Selection Sort implementation based on average marks (Descending)
void selectionSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Selection Sort\n";
        cout << "Time Complexity: O(n^2) | Space Complexity: O(1)\n";
    }
    steps = 0;
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            steps++; // Comparison step
            if (arr[j].avg > arr[maxIndex].avg) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            // Swap
            Student temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
            steps++; // Swap step
        }
        if(visualize) {
            cout << "Pass " << i + 1 << " complete. Array state:\n";
            displayArray(arr, n);
        }
    }
}


// ==============================================================================
// CONTRIBUTOR: Rutuja Lokhande
// Role: Quick Sort + Binary Search + comparison report
// ==============================================================================

// Partition logic for Quick Sort (Descending by avg)
int partition(Student arr[], int low, int high, long long& steps) {
    double pivot = arr[high].avg;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        steps++; // Comparison
        if (arr[j].avg >= pivot) {
            i++;
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            steps++; // Swap
        }
    }
    Student temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    steps++; // Swap pivot
    return (i + 1);
}

// Quick Sort implementation
void quickSortAlgo(Student arr[], int low, int high, long long& steps, bool visualize) {
    if (low < high) {
        int pi = partition(arr, low, high, steps);
        
        if (visualize) {
            cout << "Partition around " << arr[pi].avg << " (Index " << pi << ").\n";
        }

        quickSortAlgo(arr, low, pi - 1, steps, visualize);
        quickSortAlgo(arr, pi + 1, high, steps, visualize);
    }
}

// Wrapper for Quick Sort to match signature style and print info
void quickSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Quick Sort\n";
        cout << "Time Complexity: O(n log n) avg | Space Complexity: O(log n)\n";
    }
    steps = 0;
    quickSortAlgo(arr, 0, n - 1, steps, visualize);
    if(visualize) displayArray(arr, n);
}

// Helper for Binary Search: Sorts array alphabetically by name
void sortAlphabetically(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name > arr[j + 1].name) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search implementation to find a student by name
void binarySearchByName(string targetName) {
    if(currentStudentCount == 0) return;
    
    // Create copy and sort by name first (Required for Binary Search)
    Student tempArr[MAX_STUDENTS];
    copyArray(database, tempArr, currentStudentCount);
    sortAlphabetically(tempArr, currentStudentCount);
    
    cout << "\n--- Binary Search ---\n";
    cout << "Note: Array copy sorted alphabetically by name before searching.\n";
    
    int left = 0, right = currentStudentCount - 1;
    bool found = false;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (tempArr[mid].name == targetName) {
            cout << "Student found:\n";
            printStudent(tempArr[mid]);
            found = true;
            break;
        }
        if (tempArr[mid].name < targetName) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (!found) {
        cout << "Student named '" << targetName << "' not found.\n";
    }
}


// ==============================================================================
// CONTRIBUTOR: Abdeali Makda
// Role: Insertion Sort, Merge Sort, Base Code, Custom Features, Error Handling
// ==============================================================================

// Insertion Sort implementation based on average marks (Descending)
void insertionSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Insertion Sort\n";
        cout << "Time Complexity: O(n^2) | Space Complexity: O(1)\n";
    }
    steps = 0;
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        
        steps++; // Initial comparison
        while (j >= 0 && arr[j].avg < key.avg) {
            arr[j + 1] = arr[j];
            j = j - 1;
            steps += 2; // Loop condition comparison + shift
        }
        arr[j + 1] = key;
        steps++; // Placement
        
        if(visualize) {
            cout << "After inserting element at index " << i << ":\n";
            displayArray(arr, n);
        }
    }
}

// Merge logic for Merge Sort
void merge(Student arr[], int left, int mid, int right, long long& steps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Temporary arrays
    Student L[MAX_STUDENTS];
    Student R[MAX_STUDENTS];
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        steps++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        steps++;
    }
        
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        steps++; // comparison
        if (L[i].avg >= R[j].avg) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        steps++; // placement
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        steps++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        steps++;
    }
}

// Recursive Merge Sort function
void mergeSortAlgo(Student arr[], int left, int right, long long& steps, bool visualize) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortAlgo(arr, left, mid, steps, visualize);
    mergeSortAlgo(arr, mid + 1, right, steps, visualize);
    merge(arr, left, mid, right, steps);
    
    if (visualize) {
         cout << "Merged segment [" << left << " to " << right << "]:\n";
    }
}

// Wrapper for Merge Sort
void mergeSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Merge Sort\n";
        cout << "Time Complexity: O(n log n) | Space Complexity: O(n)\n";
    }
    steps = 0;
    mergeSortAlgo(arr, 0, n - 1, steps, visualize);
    if(visualize) displayArray(arr, n);
}

// P4 Function implementation explicitly placed here because it depends on all sorting functions
void displayComparisonReport() {
    if (currentStudentCount == 0) {
        cout << "Database is empty.\n";
        return;
    }
    cout << "\n=== Performance Comparison Report ===\n";
    cout << "Benchmarking 5 algorithms on N = " << currentStudentCount << " students.\n";
    cout << left << setw(18) << "Algorithm" << setw(15) << "Step Count" << "Time Taken (ms)\n";
    cout << string(50, '-') << endl;

    Student tempArr[MAX_STUDENTS];
    long long steps = 0;

    // 1. Bubble Sort
    copyArray(database, tempArr, currentStudentCount);
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(tempArr, currentStudentCount, steps, false);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> durBubble = end - start;
    cout << left << setw(18) << "Bubble Sort" << setw(15) << steps << durBubble.count() << endl;

    // 2. Selection Sort
    copyArray(database, tempArr, currentStudentCount);
    start = chrono::high_resolution_clock::now();
    selectionSort(tempArr, currentStudentCount, steps, false);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> durSel = end - start;
    cout << left << setw(18) << "Selection Sort" << setw(15) << steps << durSel.count() << endl;

    // 3. Insertion Sort
    copyArray(database, tempArr, currentStudentCount);
    start = chrono::high_resolution_clock::now();
    insertionSort(tempArr, currentStudentCount, steps, false);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> durIns = end - start;
    cout << left << setw(18) << "Insertion Sort" << setw(15) << steps << durIns.count() << endl;

    // 4. Merge Sort
    copyArray(database, tempArr, currentStudentCount);
    start = chrono::high_resolution_clock::now();
    mergeSort(tempArr, currentStudentCount, steps, false);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> durMerge = end - start;
    cout << left << setw(18) << "Merge Sort" << setw(15) << steps << durMerge.count() << endl;

    // 5. Quick Sort
    copyArray(database, tempArr, currentStudentCount);
    start = chrono::high_resolution_clock::now();
    quickSort(tempArr, currentStudentCount, steps, false);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> durQuick = end - start;
    cout << left << setw(18) << "Quick Sort" << setw(15) << steps << durQuick.count() << endl;
    cout << string(50, '-') << endl;
}

// --- Custom Feature 1: Load Data from Text File (Abdeali Makda) ---
void loadDatabaseFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    currentStudentCount = 0; // Reset
    while (getline(file, line) && currentStudentCount < MAX_STUDENTS) {
        stringstream ss(line);
        string token;
        Student s;
        double total = 0;
        
        getline(ss, token, ','); s.rollNo = stoi(token);
        getline(ss, s.name, ',');
        for(int i=0; i<5; i++) {
            getline(ss, token, ',');
            s.marks[i] = stoi(token);
            total += s.marks[i];
        }
        s.avg = total / 5.0;
        database[currentStudentCount] = s;
        currentStudentCount++;
    }
    file.close();
    cout << "Successfully loaded " << currentStudentCount << " records from " << filename << endl;
}

// --- Custom Feature 2: Export Data to Text File (Abdeali Makda) ---
void exportDatabaseToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }
    for (int i = 0; i < currentStudentCount; i++) {
        file << database[i].rollNo << "," << database[i].name;
        for (int j = 0; j < 5; j++) {
            file << "," << database[i].marks[j];
        }
        file << "\n";
    }
    file.close();
    cout << "Database successfully exported to " << filename << endl;
}

// --- Custom Feature 3: Subject-wise and Overall Toppers (Abdeali Makda) ---
void displayToppers() {
    if (currentStudentCount == 0) return;
    
    cout << "\n=== Class Analytics & Toppers ===\n";
    
    // Overall topper
    int overallMaxIdx = 0;
    for(int i=1; i<currentStudentCount; i++) {
        if(database[i].avg > database[overallMaxIdx].avg) {
            overallMaxIdx = i;
        }
    }
    cout << "🏆 Overall Class Topper: " << database[overallMaxIdx].name 
         << " (Avg: " << database[overallMaxIdx].avg << ")\n";
         
    // Subject wise
    for(int sub = 0; sub < 5; sub++) {
        int subMaxIdx = 0;
        for(int i=1; i<currentStudentCount; i++) {
            if(database[i].marks[sub] > database[subMaxIdx].marks[sub]) {
                subMaxIdx = i;
            }
        }
        cout << "Highest in Subject " << sub + 1 << ": " 
             << database[subMaxIdx].name << " (" << database[subMaxIdx].marks[sub] << " marks)\n";
    }
}


// Base Structure, Main Menu and Loop (Abdeali Makda)

int main() {
    int choice;
    do {
        cout << "\n=======================================";
        cout << "\n      College Marks Ranker System      ";
        cout << "\n=======================================";
        cout << "\n1. Add Student Record Manually";
        cout << "\n2. Load Data from 'students_db.txt'";
        cout << "\n3. Display All Students";
        cout << "\n4. Linear Search by Roll No";
        cout << "\n5. Binary Search by Name";
        cout << "\n6. Visualize Sorting Algorithm (Pick One)";
        cout << "\n7. Display Comparison Table (All Algos)";
        cout << "\n8. Flag Fail-Risk Students (<40 Avg)";
        cout << "\n9. Class Analytics & Toppers";
        cout << "\n10. Export Data to File";
        cout << "\n0. Exit";
        cout << "\n=======================================";
        cout << "\nEnter your choice: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        switch (choice) {
            case 1:
                addStudentRecord();
                break;
            case 2:
                loadDatabaseFromFile("students_db.txt");
                break;
            case 3:
                displayArray(database, currentStudentCount);
                break;
            case 4: {
                int roll;
                cout << "Enter Roll No to search: ";
                cin >> roll;
                linearSearchByRollNo(roll);
                break;
            }
            case 5: {
                string name;
                cout << "Enter Exact Name to search: ";
                cin.ignore();
                getline(cin, name);
                binarySearchByName(name);
                break;
            }
            case 6: {
                if (currentStudentCount == 0) {
                    cout << "Database empty. Load data first.\n";
                    break;
                }
                int algoChoice;
                cout << "\nSelect Algorithm to Visualize:\n";
                cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\nChoice: ";
                cin >> algoChoice;
                
                Student temp[MAX_STUDENTS];
                copyArray(database, temp, currentStudentCount);
                long long steps = 0;
                
                switch(algoChoice) {
                    case 1: bubbleSort(temp, currentStudentCount, steps, true); break;
                    case 2: selectionSort(temp, currentStudentCount, steps, true); break;
                    case 3: insertionSort(temp, currentStudentCount, steps, true); break;
                    case 4: mergeSort(temp, currentStudentCount, steps, true); break;
                    case 5: quickSort(temp, currentStudentCount, steps, true); break;
                    default: cout << "Invalid algo choice.\n";
                }
                cout << "Total Steps Executed: " << steps << "\n";
                break;
            }
            case 7:
                displayComparisonReport();
                break;
            case 8:
                flagFailRiskStudents();
                break;
            case 9:
                displayToppers();
                break;
            case 10:
                exportDatabaseToFile("exported_students.txt");
                break;
            case 0:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}