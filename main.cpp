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

// --- CHANGE 1: Linear Search now shows each step of the traversal ---
// Time Complexity: O(n)
void linearSearchByRollNo(int targetRoll) {
    bool found = false;
    cout << "\n--- Linear Search ---\n";
    cout << "[Algorithm Info] Linear Search\n";
    cout << "Time Complexity: O(n) | Space Complexity: O(1)\n";
    cout << "How it works: Checks each element one by one from left to right.\n";
    cout << "              Stops as soon as a match is found.\n";
    cout << "Searching for Roll No: " << targetRoll << "\n";
    cout << string(60, '-') << endl;

    for (int i = 0; i < currentStudentCount; i++) {
        cout << "Step " << setw(2) << i + 1 << ": Checking Index [" << i << "] | Roll=" 
             << setw(4) << database[i].rollNo << " | Name=" << database[i].name;
        if (database[i].rollNo == targetRoll) {
            cout << " --> MATCH FOUND!\n";
            cout << string(60, '-') << endl;
            cout << "Student found at index " << i << ":\n";
            printStudent(database[i]);
            found = true;
            break; // Stop searching once found
        } else {
            cout << " --> No match\n";
        }
    }
    if (!found) {
        cout << string(60, '-') << endl;
        cout << "Exhausted all " << currentStudentCount << " entries. Roll No " << targetRoll << " not found.\n";
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

// --- CHANGE 1: Bubble Sort now shows each individual comparison and swap ---
// Steps counter tracks comparisons and swaps.
void bubbleSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Bubble Sort\n";
        cout << "Time Complexity: O(n^2) | Space Complexity: O(1)\n";
        cout << "How it works: Repeatedly compares adjacent elements and swaps\n";
        cout << "             them if they are in wrong order. The largest element\n";
        cout << "             'bubbles up' to its correct position each pass.\n";
        cout << "Sorting " << n << " students by average (Descending).\n";
    }
    steps = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        if(visualize) {
            cout << "\n--- Pass " << i + 1 << " (locking position " << n - 1 - i << " from right) ---\n";
        }
        for (int j = 0; j < n - i - 1; j++) {
            steps++; // Comparison count
            if(visualize) {
                cout << "  Compare [" << j << "] " << left << setw(15) << arr[j].name
                     << "(avg=" << fixed << setprecision(2) << arr[j].avg << ")"
                     << " vs [" << j + 1 << "] " << setw(15) << arr[j + 1].name
                     << "(avg=" << arr[j + 1].avg << ")";
            }
            if (arr[j].avg < arr[j + 1].avg) {
                // Swap logic without pointers
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                steps++; // Swap step count
                if(visualize) cout << " --> SWAPPED\n";
            } else {
                if(visualize) cout << " --> No swap\n";
            }
        }
        if(visualize) {
            cout << "State after Pass " << i + 1 << ":\n";
            displayArray(arr, n);
        }
        if (!swapped) {
            if(visualize) cout << "No swaps this pass - array is already sorted! Early exit.\n";
            break; // Optimization if already sorted
        }
    }
}

// --- CHANGE 1: Selection Sort now shows each comparison and min/max selection ---
void selectionSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Selection Sort\n";
        cout << "Time Complexity: O(n^2) | Space Complexity: O(1)\n";
        cout << "How it works: Finds the maximum element in the unsorted portion\n";
        cout << "             and swaps it to the front of that portion.\n";
        cout << "Sorting " << n << " students by average (Descending).\n";
    }
    steps = 0;
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        if(visualize) {
            cout << "\n--- Pass " << i + 1 << ": Finding max in indices [" << i << " to " << n - 1 << "] ---\n";
            cout << "  Current max candidate: [" << i << "] " << arr[i].name
                 << " (avg=" << fixed << setprecision(2) << arr[i].avg << ")\n";
        }
        for (int j = i + 1; j < n; j++) {
            steps++; // Comparison step
            if(visualize) {
                cout << "  Compare [" << j << "] " << left << setw(15) << arr[j].name
                     << "(avg=" << fixed << setprecision(2) << arr[j].avg << ")"
                     << " vs max [" << maxIndex << "] " << setw(15) << arr[maxIndex].name
                     << "(avg=" << arr[maxIndex].avg << ")";
            }
            if (arr[j].avg > arr[maxIndex].avg) {
                if(visualize) cout << " --> New max! Updating candidate to [" << j << "]\n";
                maxIndex = j;
            } else {
                if(visualize) cout << " --> No change\n";
            }
        }
        if (maxIndex != i) {
            if(visualize) {
                cout << "  Swapping [" << i << "] " << arr[i].name
                     << " <--> [" << maxIndex << "] " << arr[maxIndex].name << "\n";
            }
            // Swap
            Student temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
            steps++; // Swap step
        } else {
            if(visualize) cout << "  [" << i << "] " << arr[i].name << " already in correct position. No swap.\n";
        }
        if(visualize) {
            cout << "State after Pass " << i + 1 << " (position " << i << " locked):\n";
            displayArray(arr, n);
        }
    }
}


// ==============================================================================
// CONTRIBUTOR: Rutuja Lokhande
// Role: Quick Sort + Binary Search + comparison report
// ==============================================================================

// --- CHANGE 1: Partition now prints each element's comparison against the pivot ---
int partition(Student arr[], int low, int high, long long& steps, bool visualize) {
    double pivot = arr[high].avg;
    if(visualize) {
        cout << "  Pivot chosen: [" << high << "] " << arr[high].name
             << " (avg=" << fixed << setprecision(2) << pivot << ")\n";
    }
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        steps++; // Comparison
        if(visualize) {
            cout << "    Check [" << j << "] " << left << setw(15) << arr[j].name
                 << "(avg=" << fixed << setprecision(2) << arr[j].avg
                 << ") >= pivot(" << pivot << ")?";
        }
        if (arr[j].avg >= pivot) {
            i++;
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            steps++; // Swap
            if(visualize) cout << " YES --> Moved to position [" << i << "]\n";
        } else {
            if(visualize) cout << " NO\n";
        }
    }
    Student temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    steps++; // Swap pivot
    if(visualize) cout << "  Pivot placed at final position [" << i + 1 << "]\n";
    return (i + 1);
}

// --- CHANGE 1: Quick Sort now shows each partition segment and its sub-divisions ---
void quickSortAlgo(Student arr[], int low, int high, long long& steps, bool visualize) {
    if (low < high) {
        if(visualize) {
            cout << "\n[Partition] Working on segment [" << low << " to " << high << "]:\n";
        }
        int pi = partition(arr, low, high, steps, visualize);
        if(visualize) {
            cout << "  Result: Left subarray [" << low << " to " << pi - 1
                 << "] | Right subarray [" << pi + 1 << " to " << high << "]\n";
        }
        quickSortAlgo(arr, low, pi - 1, steps, visualize);
        quickSortAlgo(arr, pi + 1, high, steps, visualize);
    }
}

// Wrapper for Quick Sort to match signature style and print info
void quickSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Quick Sort\n";
        cout << "Time Complexity: O(n log n) avg, O(n^2) worst | Space Complexity: O(log n)\n";
        cout << "How it works: Picks a pivot element, partitions so all elements\n";
        cout << "             >= pivot go left, < pivot go right, then recursively\n";
        cout << "             sorts each sub-array.\n";
        cout << "Sorting " << n << " students by average (Descending).\n";
    }
    steps = 0;
    quickSortAlgo(arr, 0, n - 1, steps, visualize);
    if(visualize) {
        cout << "\nFinal sorted array:\n";
        displayArray(arr, n);
    }
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

// --- CHANGE 1: Binary Search now shows left/mid/right pointers at every step ---
// Time Complexity: O(log n)
void binarySearchByName(string targetName) {
    if(currentStudentCount == 0) return;
    
    // Create copy and sort by name first (Required for Binary Search)
    Student tempArr[MAX_STUDENTS];
    copyArray(database, tempArr, currentStudentCount);
    sortAlphabetically(tempArr, currentStudentCount);
    
    cout << "\n--- Binary Search ---\n";
    cout << "[Algorithm Info] Binary Search\n";
    cout << "Time Complexity: O(log n) | Space Complexity: O(1)\n";
    cout << "How it works: On a sorted array, checks the middle element each step.\n";
    cout << "             If the target is smaller, search the left half; if larger,\n";
    cout << "             search the right half. Discards half the space each step.\n";
    cout << "Pre-requisite: Array sorted alphabetically. Searching on a copy.\n";
    cout << "Sorted name order: ";
    for(int i = 0; i < currentStudentCount; i++) {
        cout << tempArr[i].name;
        if(i < currentStudentCount - 1) cout << " | ";
    }
    cout << "\nSearching for: \"" << targetName << "\"\n";
    cout << string(60, '-') << endl;
    
    int left = 0, right = currentStudentCount - 1;
    bool found = false;
    int step = 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "Step " << step++ << ": left=[" << left << "] mid=[" << mid << "] right=[" << right << "]\n";
        cout << "  Checking mid element: \"" << tempArr[mid].name << "\"";
        
        if (tempArr[mid].name == targetName) {
            cout << " --> MATCH FOUND!\n";
            cout << string(60, '-') << endl;
            cout << "Student found:\n";
            printStudent(tempArr[mid]);
            found = true;
            break;
        }
        if (tempArr[mid].name < targetName) {
            cout << " --> Target comes AFTER mid alphabetically.\n";
            cout << "  Discarding left half. New left = " << mid + 1 << "\n";
            left = mid + 1;
        } else {
            cout << " --> Target comes BEFORE mid alphabetically.\n";
            cout << "  Discarding right half. New right = " << mid - 1 << "\n";
            right = mid - 1;
        }
    }
    
    if (!found) {
        cout << string(60, '-') << endl;
        cout << "Search space exhausted. Student named '" << targetName << "' not found.\n";
    }
}


// ==============================================================================
// CONTRIBUTOR: Abdeali Makda
// Role: Insertion Sort, Merge Sort, Base Code, Custom Features, Error Handling
// ==============================================================================

// --- CHANGE 1: Insertion Sort now shows each element's insertion into sorted portion ---
void insertionSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Insertion Sort\n";
        cout << "Time Complexity: O(n^2) | Space Complexity: O(1)\n";
        cout << "How it works: Builds a sorted portion from left to right. Each new\n";
        cout << "             element is shifted leftward until it reaches its correct\n";
        cout << "             position in the already-sorted portion.\n";
        cout << "Sorting " << n << " students by average (Descending).\n";
    }
    steps = 0;
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        
        if(visualize) {
            cout << "\n--- Iteration " << i << ": Inserting \"" << key.name
                 << "\" (avg=" << fixed << setprecision(2) << key.avg
                 << ") into sorted portion [0.." << i - 1 << "] ---\n";
        }
        
        steps++; // Initial comparison
        while (j >= 0 && arr[j].avg < key.avg) {
            if(visualize) {
                cout << "  [" << j << "] " << left << setw(15) << arr[j].name
                     << "(avg=" << fixed << setprecision(2) << arr[j].avg
                     << ") < key --> Shift right to [" << j + 1 << "]\n";
            }
            arr[j + 1] = arr[j];
            j = j - 1;
            steps += 2; // Loop condition comparison + shift
        }
        arr[j + 1] = key;
        steps++; // Placement
        
        if(visualize) {
            cout << "  Inserted \"" << key.name << "\" at position [" << j + 1 << "]\n";
            cout << "State after Iteration " << i << ":\n";
            displayArray(arr, n);
        }
    }
}

// --- CHANGE 1: Merge now shows which elements are picked from each half ---
void merge(Student arr[], int left, int mid, int right, long long& steps, bool visualize) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Temporary arrays
    Student L[MAX_STUDENTS];
    Student R[MAX_STUDENTS];
    
    for (int i = 0; i < n1; i++) { L[i] = arr[left + i]; steps++; }
    for (int j = 0; j < n2; j++) { R[j] = arr[mid + 1 + j]; steps++; }

    if(visualize) {
        cout << "\n  Merging [" << left << ".." << mid << "] and [" << mid + 1 << ".." << right << "]\n";
        cout << "  Left  half: ";
        for(int i = 0; i < n1; i++) cout << L[i].name << "(" << fixed << setprecision(1) << L[i].avg << ") ";
        cout << "\n";
        cout << "  Right half: ";
        for(int j = 0; j < n2; j++) cout << R[j].name << "(" << fixed << setprecision(1) << R[j].avg << ") ";
        cout << "\n";
    }
        
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        steps++; // comparison
        if (L[i].avg >= R[j].avg) {
            if(visualize) cout << "    Pick from Left:  " << L[i].name << " (" << fixed << setprecision(2) << L[i].avg << ")\n";
            arr[k] = L[i];
            i++;
        } else {
            if(visualize) cout << "    Pick from Right: " << R[j].name << " (" << fixed << setprecision(2) << R[j].avg << ")\n";
            arr[k] = R[j];
            j++;
        }
        k++;
        steps++; // placement
    }
    
    while (i < n1) { arr[k] = L[i]; i++; k++; steps++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; steps++; }

    if(visualize) {
        cout << "  Merged result [" << left << ".." << right << "]: ";
        for(int x = left; x <= right; x++)
            cout << arr[x].name << "(" << fixed << setprecision(1) << arr[x].avg << ") ";
        cout << "\n";
    }
}

// --- CHANGE 1: Merge Sort now shows each divide step before merging ---
void mergeSortAlgo(Student arr[], int left, int right, long long& steps, bool visualize) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    if(visualize) {
        cout << "\n[Split] Dividing [" << left << ".." << right << "] --> "
             << "[" << left << ".." << mid << "] and [" << mid + 1 << ".." << right << "]\n";
    }
    mergeSortAlgo(arr, left, mid, steps, visualize);
    mergeSortAlgo(arr, mid + 1, right, steps, visualize);
    merge(arr, left, mid, right, steps, visualize);
}

// Wrapper for Merge Sort
void mergeSort(Student arr[], int n, long long& steps, bool visualize) {
    if(visualize) {
        cout << "\n[Algorithm Info] Merge Sort\n";
        cout << "Time Complexity: O(n log n) | Space Complexity: O(n)\n";
        cout << "How it works: Recursively divides array into halves until single\n";
        cout << "             elements remain, then merges them back in sorted order.\n";
        cout << "Sorting " << n << " students by average (Descending).\n";
    }
    steps = 0;
    mergeSortAlgo(arr, 0, n - 1, steps, visualize);
    if(visualize) {
        cout << "\nFinal sorted array:\n";
        displayArray(arr, n);
    }
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

// --- CHANGE 2: Export now writes a full analytical report instead of raw data ---
// Includes: overall topper, subject-wise toppers, rank list, fail-risk list,
// above/below average breakdown, and per-subject statistics.
void exportDatabaseToFile(const string& filename) {
    if (currentStudentCount == 0) {
        cout << "Database is empty. Nothing to export.\n";
        return;
    }
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    // ---- Pre-compute statistics ----
    int overallMaxIdx = 0, overallMinIdx = 0;
    double classTotal = 0;
    for(int i = 0; i < currentStudentCount; i++) {
        if(database[i].avg > database[overallMaxIdx].avg) overallMaxIdx = i;
        if(database[i].avg < database[overallMinIdx].avg) overallMinIdx = i;
        classTotal += database[i].avg;
    }
    double classAvg = classTotal / currentStudentCount;

    // Sort a copy for rank list
    Student sorted[MAX_STUDENTS];
    copyArray(database, sorted, currentStudentCount);
    for(int i = 0; i < currentStudentCount - 1; i++) {
        for(int j = 0; j < currentStudentCount - i - 1; j++) {
            if(sorted[j].avg < sorted[j+1].avg) {
                Student tmp = sorted[j]; sorted[j] = sorted[j+1]; sorted[j+1] = tmp;
            }
        }
    }

    // ---- Write Report ----
    file << "============================================================\n";
    file << "         COLLEGE MARKS RANKER - ANALYTICAL REPORT          \n";
    file << "============================================================\n\n";

    // Section 1: Overall performance
    file << "1. OVERALL CLASS PERFORMANCE\n";
    file << "------------------------------------------------------------\n";
    file << "Total Students   : " << currentStudentCount << "\n";
    file << fixed << setprecision(2);
    file << "Class Average    : " << classAvg << "\n";
    file << "Class Topper     : " << database[overallMaxIdx].name
         << " (Roll No: " << database[overallMaxIdx].rollNo
         << ", Avg: " << database[overallMaxIdx].avg << ")\n";
    file << "Lowest Average   : " << database[overallMinIdx].name
         << " (Roll No: " << database[overallMinIdx].rollNo
         << ", Avg: " << database[overallMinIdx].avg << ")\n\n";

    // Section 2: Subject-wise toppers and stats
    file << "2. SUBJECT-WISE TOPPERS & STATISTICS\n";
    file << "------------------------------------------------------------\n";
    for(int sub = 0; sub < 5; sub++) {
        int subMaxIdx = 0;
        int subMin = database[0].marks[sub];
        double subTotal = 0;
        for(int i = 0; i < currentStudentCount; i++) {
            if(database[i].marks[sub] > database[subMaxIdx].marks[sub]) subMaxIdx = i;
            if(database[i].marks[sub] < subMin) subMin = database[i].marks[sub];
            subTotal += database[i].marks[sub];
        }
        double subAvg = subTotal / currentStudentCount;
        file << "Subject " << sub + 1 << " | Topper: " << left << setw(20) << database[subMaxIdx].name
             << " (" << database[subMaxIdx].marks[sub] << " marks)"
             << " | Class Avg: " << fixed << setprecision(2) << subAvg
             << " | Highest: " << database[subMaxIdx].marks[sub]
             << " | Lowest: " << subMin << "\n";
    }
    file << "\n";

    // Section 3: Rank list
    file << "3. CLASS RANK LIST (Sorted by Average - Descending)\n";
    file << "------------------------------------------------------------\n";
    file << left << setw(6) << "Rank" << setw(8) << "Roll"
         << setw(22) << "Name" << setw(10) << "Average" << "Subject Marks\n";
    file << string(68, '-') << "\n";
    for(int i = 0; i < currentStudentCount; i++) {
        file << left << setw(6) << i + 1
             << setw(8) << sorted[i].rollNo
             << setw(22) << sorted[i].name
             << setw(10) << fixed << setprecision(2) << sorted[i].avg
             << "[" << sorted[i].marks[0] << ","
             << sorted[i].marks[1] << ","
             << sorted[i].marks[2] << ","
             << sorted[i].marks[3] << ","
             << sorted[i].marks[4] << "]\n";
    }
    file << "\n";

    // Section 4: Fail-risk students
    file << "4. FAIL-RISK STUDENTS (Average < 40)\n";
    file << "------------------------------------------------------------\n";
    bool anyRisk = false;
    for(int i = 0; i < currentStudentCount; i++) {
        if(database[i].avg < 40.0) {
            file << "  Roll " << database[i].rollNo << " | " << database[i].name
                 << " | Avg: " << fixed << setprecision(2) << database[i].avg << "\n";
            anyRisk = true;
        }
    }
    if(!anyRisk) file << "  No fail-risk students. All students have avg >= 40.\n";
    file << "\n";

    // Section 5: Above/below class average
    file << "5. PERFORMANCE RELATIVE TO CLASS AVERAGE ("
         << fixed << setprecision(2) << classAvg << ")\n";
    file << "------------------------------------------------------------\n";
    file << "Above Average:\n";
    for(int i = 0; i < currentStudentCount; i++) {
        if(database[i].avg >= classAvg)
            file << "  " << left << setw(22) << database[i].name
                 << " Avg: " << fixed << setprecision(2) << database[i].avg << "\n";
    }
    file << "Below Average:\n";
    for(int i = 0; i < currentStudentCount; i++) {
        if(database[i].avg < classAvg)
            file << "  " << left << setw(22) << database[i].name
                 << " Avg: " << fixed << setprecision(2) << database[i].avg << "\n";
    }
    file << "\n";

    file << "============================================================\n";
    file << "                      END OF REPORT                        \n";
    file << "============================================================\n";

    file.close();
    cout << "Analytical report successfully exported to '" << filename << "'\n";
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
