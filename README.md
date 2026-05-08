# 📊 College Marks Ranker (DSA Project)

## 👥 Team Members

* **P1:** Aayush Dattatray Jadhav
* **P2:** Yatharth Mishra
* **P3:** Abdeali Makda
* **P4:** Rutuja Lokhande

---

## 📌 Project Overview

The **College Marks Ranker** is a Data Structures and Algorithms (DSA) project designed to simulate a real-world academic system.

The system performs:

* Student data management
* Searching operations
* Sorting using multiple algorithms
* Performance comparison of algorithms

The main objective is to **analyze and compare 5 sorting algorithms** based on:

* Number of steps (operations)
* Execution time

---

## 🎯 Objectives

* Implement and understand different **sorting algorithms**
* Apply **searching techniques**
* Compare algorithm efficiency using real data
* Build a structured and modular program

---

## 🧾 Features

### 1. Student Record Management

Each student record contains:

* Roll Number
* Name
* Marks in 5 subjects
* Average Marks

---

### 2. Searching Operations

#### 🔍 Linear Search (P1)

* Search student by **roll number**
* Time Complexity: O(n)

#### 🔎 Binary Search (P4)

* Search student by **name**
* Requires data to be **sorted first**
* Time Complexity: O(log n)

---

### 3. Sorting Algorithms (Core DSA)

Students are sorted based on **average marks** using:

| Algorithm      | Implemented By |
| -------------- | -------------- |
| Bubble Sort    | P2             |
| Selection Sort | P2             |
| Insertion Sort | P3             |
| Merge Sort     | P3             |
| Quick Sort     | P4             |

Each algorithm:

* Sorts student records
* Counts number of steps (comparisons)
* Measures execution time

---

### 4. Algorithm Comparison

A comparison table is generated showing:

| Algorithm | Steps | Time |
| --------- | ----- | ---- |

This helps analyze:

* Efficiency
* Performance differences

---

### 5. Fail-Risk Detection (P1)

* Identifies students with:

  **Average < 40**

* Uses O(n) traversal

---

### 6. Menu-Driven Interface

The program provides options such as:

* Search student
* Display records
* Sort and compare algorithms
* Identify fail-risk students

---

## ⚙️ Implementation Details

### 🔹 Data Structure Used

* `struct Student` to store student details

### 🔹 Key Concepts Applied

* Arrays
* Searching Algorithms
* Sorting Algorithms
* Time Complexity Analysis
* Step Counting Mechanism

---

## 🧠 Step Counting Strategy

* Each comparison in sorting algorithms increments a counter
* Used to compare algorithm efficiency
* Ensures fair analysis across all methods

---

## ⚠️ Important Constraints

* Maximum students: 20
* All sorting must be done on **copied data** (to ensure fairness)
* Binary search must be applied only after sorting by name

---

## 🧩 Custom Features (Extended Functionality)

* 🎯 Find Topper (highest average)
* 📈 Class Average Calculation

---

## 👨‍💻 Role Distribution

### 👤 P1 – Aayush Dattatray Jadhav

* Student input & structure handling
* Linear Search implementation
* Fail-risk student detection

---

### 👤 P2 – Yatharth Mishra

* Bubble Sort implementation
* Selection Sort implementation
* Step counting logic

---

### 👤 P3 – Abdeali Makda

* Insertion Sort implementation
* Merge Sort implementation
* Step counting logic

---

### 👤 P4 – Rutuja Lokhande

* Quick Sort implementation
* Binary Search implementation
* Algorithm comparison report

---

## 🚀 How to Run

1. Compile the program:

```
g++ main.cpp -o ranker
```

2. Run the executable:

```
./ranker
```

3. Follow on-screen menu instructions

---

## 📊 Learning Outcomes

* Practical understanding of sorting algorithms
* Real-world application of searching techniques
* Performance comparison using step count and execution time
* Team-based modular programming

---

## 📌 Conclusion

This project demonstrates how fundamental DSA concepts can be applied to build a real-world system. By comparing multiple algorithms, it highlights the importance of choosing efficient solutions based on data size and requirements.

---
