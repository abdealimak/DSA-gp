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
* Implement searching methods
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
* Time Complexity: **O(n)**

#### 🔎 Binary Search

* Search student by name
* Requires sorted data
* Time Complexity: **O(log n)**

---

### 3. Sorting Algorithms (Key Feature)

Sorting is done based on **average marks**

| Algorithm      | Complexity |
| -------------- | ---------- |
| Bubble Sort    | O(n²)      |
| Selection Sort | O(n²)      |
| Insertion Sort | O(n²)      |
| Merge Sort     | O(n log n) |
| Quick Sort     | O(n log n) |

---

### 4. Step Count Tracking

* Each algorithm counts:

  * Comparisons
  * Swaps (partially)
* Used to compare efficiency

---

### 5. Performance Comparison

Displays table:

| Algorithm | Steps | Time |
| --------- | ----- | ---- |

Helps analyze:

* Fastest algorithm
* Most efficient algorithm

---

### 6. Fail-Risk Detection

* Identifies students with:

  **Average < 40**

* Uses linear scan → O(n)

---

## ⭐ Custom Features

### 📊 Class Analytics

* Calculates overall class average
* Displays top-performing student

---

### 💾 File Storage System

* Saves student data in `.txt` file
* Loads data on program start
* Ensures persistence

---

## 🧠 Concepts Used

* Arrays
* Structures (`struct`)
* Searching Algorithms
* Sorting Algorithms
* Time Complexity Analysis
* File Handling
* Step Counting

---

## 📁 File Structure

```
CollegeMarksRanker/
│
├── main.cpp            # Main program (all logic)
├── students_db.txt     # Stored student records
└── README.md           # Project documentation
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

1. Load data from file
2. Display menu
3. Perform selected operation
4. Save updated data
5. Exit

---

## ⚠️ Important Notes

* Maximum students: **20**
* Sorting is done on **copied arrays** for fairness
* Binary search only works after sorting
* Step count may vary slightly per algorithm

---

## 📊 Learning Outcomes

* Understanding real-world use of sorting
* Comparing algorithm efficiency
* Implementing search techniques
* Working in a team-based coding environment

---

## 📌 Conclusion

This project demonstrates how fundamental DSA concepts can be used to build a practical system. It highlights the importance of choosing efficient algorithms and provides hands-on experience with real data processing.

---
