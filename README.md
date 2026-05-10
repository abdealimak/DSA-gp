# 📊 College Marks Ranker

---

## 👥 Team Members & Contributions

| Member                      | Role                                                          |
| --------------------------- | ------------------------------------------------------------- |
| **Aayush Dattatray Jadhav** | Student Input, Linear Search, Fail-Risk Detection             |
| **Yatharth Mishra**         | Bubble Sort, Selection Sort, Step Counting                    |
| **Abdeali Makda**           | Base System Design, File Handling, Insertion Sort, Merge Sort |
| **Rutuja Lokhande**         | Quick Sort, Binary Search, Comparison Report                  |

---

## 📌 Problem Statement

A degree college needs a system to:

* Rank students based on marks
* Identify toppers
* Detect fail-risk students
* Compare 5 sorting algorithms on real data

Each sorting algorithm must display:

* Step count
* Execution time

---

## 🎯 Project Objective

* Apply **Data Structures & Algorithms** in a real-world scenario
* Compare efficiency of multiple sorting techniques
* Implement searching methods with step-by-step visualization
* Build a modular and scalable system

---

## ⚙️ Core Features

### 1. Student Record Management

* Stores:

  * Roll Number
  * Name
  * Marks (5 subjects)
  * Average marks

---

### 2. Searching Algorithms

#### 🔍 Linear Search

* Search student by roll number
* **Step-by-step visualization** — prints each index checked with roll number and name, marking `→ No match` or `→ MATCH FOUND!`
* Time Complexity: **O(n)** | Space Complexity: **O(1)**

#### 🔎 Binary Search

* Search student by name
* Requires sorted data (sorting is done on a copy automatically)
* **Step-by-step visualization** — prints `left`, `mid`, `right` pointer values at every iteration, shows the sorted name order before searching, and explains which half is discarded and why
* Time Complexity: **O(log n)** | Space Complexity: **O(1)**

---

### 3. Sorting Algorithms with Step-by-Step Visualization (Key Feature)

Sorting is done based on **average marks (Descending)**. When run from **Option 6 (Visualize)**, every algorithm prints a header with complexity info, a plain-English description of how it works, and narrates every internal operation:

| Algorithm      | Average Complexity | Space Complexity | Visualization Detail |
| -------------- | ------------------ | ---------------- | -------------------- |
| Bubble Sort    | O(n²)              | O(1)             | Each adjacent comparison and swap per pass; early-exit announcement |
| Selection Sort | O(n²)              | O(1)             | Each comparison against max candidate; swap before position is locked |
| Insertion Sort | O(n²)              | O(1)             | Each rightward shift in sorted portion; final insertion index |
| Merge Sort     | O(n log n)         | O(n)             | Each `[Split]` division going down; left/right half contents; element-by-element pick during merge |
| Quick Sort     | O(n log n) avg     | O(log n)         | Pivot selection; each element's comparison against pivot; resulting sub-array ranges |

> **Note:** When run from **Option 7 (Comparison Table)**, visualization is suppressed and algorithms run silently for accurate benchmarking.

---

### 4. Step Count Tracking

* Each algorithm counts:

  * Comparisons
  * Swaps / placements
* Displayed at end of each visualization run
* Used in the comparison table for efficiency analysis

---

### 5. Performance Comparison

Displays a benchmarking table across all 5 algorithms:

| Algorithm | Steps | Time (ms) |
| --------- | ----- | --------- |

Helps analyze:

* Fastest algorithm for the current dataset
* Most efficient algorithm by step count

---

### 6. Fail-Risk Detection

* Identifies students with:

  **Average < 40**

* Uses linear scan → O(n)

---

## ⭐ Custom Features

### 📊 Class Analytics (Option 9)

* Overall class topper with average
* Subject-wise toppers with marks scored

---

### 💾 File Storage System

#### Load (Option 2)
* Reads student records from `students_db.txt`
* Format per line: `RollNo,Name,Sub1,Sub2,Sub3,Sub4,Sub5`

#### Export — Analytical Report (Option 10)
* Exports a structured **analytical report** to `exported_students.txt`
* The report contains **5 sections**:

  1. **Overall Class Performance** — total students, class average, class topper, lowest scorer
  2. **Subject-wise Toppers & Statistics** — per subject: topper, class average, highest mark, lowest mark
  3. **Class Rank List** — all students ranked by average (descending) with individual subject marks
  4. **Fail-Risk Students** — students with average < 40, or a "no risk" message
  5. **Performance vs Class Average** — who is above and who is below the class average

---

## 🧠 Concepts Used

* Arrays
* Structures (`struct`)
* Searching Algorithms (with pointer/index visualization)
* Sorting Algorithms (with pass/step-level visualization)
* Time Complexity Analysis
* File Handling (Load & Analytical Export)
* Step Counting

---

## 📁 File Structure

```
CollegeMarksRanker/
│
├── main.cpp                  # Main program (all logic)
├── students_db.txt           # Input: stored student records
├── exported_students.txt     # Output: generated analytical report
└── README.md                 # Project documentation
```

---

## 🚀 How to Run

### Compile:

```
g++ main.cpp -o ranker
```

### Run:

```
./ranker
```

---

## 📋 Program Flow

1. Load data from `students_db.txt` (Option 2)
2. Display menu
3. Perform selected operation (search / sort / analyze / export)
4. Exit

---

## 📋 Menu Options Reference

| Option | Description |
| ------ | ----------- |
| 1 | Add a student record manually |
| 2 | Load records from `students_db.txt` |
| 3 | Display all students |
| 4 | Linear Search by Roll No (step-by-step) |
| 5 | Binary Search by Name (step-by-step) |
| 6 | Visualize a sorting algorithm step-by-step |
| 7 | Performance comparison table (all 5 algorithms) |
| 8 | Flag fail-risk students (avg < 40) |
| 9 | Class analytics & toppers |
| 10 | Export analytical report to file |
| 0 | Exit |

---

## ⚠️ Important Notes

* Maximum students: **20**
* Sorting is done on **copied arrays** — the original database is never modified by a sort
* Binary search automatically sorts a copy alphabetically before searching
* Step count may vary slightly per algorithm depending on input order
* Visualization (Option 6) and benchmarking (Option 7) are separate — visualization is suppressed during benchmarking for accurate timing

---

## 📊 Learning Outcomes

* Understanding real-world use of sorting and searching
* Comparing algorithm efficiency through step counts and execution time
* Visualizing how algorithms operate internally at each step
* Generating structured analytical outputs from raw data
* Working in a team-based coding environment

---

## 📌 Conclusion

This project demonstrates how fundamental DSA concepts can be used to build a practical system. It highlights the importance of choosing efficient algorithms, provides hands-on experience with real data processing, and makes algorithm behavior transparent through step-by-step visualization of every comparison, swap, and pointer movement.

---
