# Hospital Management System
### A lightweight, file-based hospital management solution built entirely in C++

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Storage](https://img.shields.io/badge/Storage-File--Based-lightgrey)
![Status](https://img.shields.io/badge/Status-Completed-green)
![License](https://img.shields.io/badge/License-MIT-green)

---

## Overview

The Hospital Management System is a console-based application that simulates core hospital operations without relying on any external libraries or database engines. All data is persisted through structured plain-text files using a custom `#`-delimited format, with automatic data validation and cleaning performed on every startup.

---

## Table of Contents

- [Features](#features)
- [File Structure](#file-structure)
- [Data Formats](#data-formats)
- [Data Cleaning](#data-cleaning)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Technical Highlights](#technical-highlights)
- [Known Limitations](#known-limitations)
- [Author](#author)

---

## Features

**Patient Management**
- Add, view, update, and delete patient records
- Search patients by ID or name
- Fields: ID, name, age, gender, contact, balance

**Doctor Management**
- Add, view, update, and delete doctor records
- Search doctors by ID or specialty
- Sort doctors by years of experience (ascending)
- Fields: ID, name, specialty, experience

**Appointment Management**
- Schedule, view, and cancel appointments
- Appointments linked to both patient and doctor IDs

**Treatment & Billing**
- Add and view treatment records per patient
- Generate bills and automatically deduct cost from patient balance
- Toggle payment status between Paid and Unpaid

**Search & Reports**
- Cross-reference appointments and treatments by doctor
- Generate billing reports per patient

---

## File Structure

```
hospital-management-system/
│
├── main.cpp                  # Main source file
│
├── patients.txt              # Patient records
├── doctors.txt               # Doctor records
├── appointments.txt          # Appointment records
├── treatments.txt            # Treatment records
└── bills.txt                 # Billing records
```

---

## Data Formats

| File | Format | Example |
|------|--------|---------|
| `patients.txt` | `ID#Name#Age#Gender#Contact#Balance` | `101#Ali Raza#25#Male#03001234567#5000` |
| `doctors.txt` | `ID#Name#Specialty#Experience` | `201#Dr. Kamran Yousaf#Cardiologist#10` |
| `appointments.txt` | `PatientID#DoctorID#Date#Time` | `101#201#03-30-2026#10:00 AM` |
| `treatments.txt` | `PatientID#Description#Cost#Paid` | `101#Blood Test#500#false` |
| `bills.txt` | `PatientID#Cost#Status` | `101#500#Unpaid` |

---

## Data Cleaning

The system runs `cleanFile()` automatically on every startup, validating and sanitizing all five data files before the user interacts with the system.

| Check | Details |
|-------|---------|
| Missing fields | Records are validated by counting `#` delimiters. Any record with an incorrect count is removed. |
| Invalid contact | Patient contacts must be exactly 11 numeric digits. Non-conforming records are removed. |
| Invalid age | Patient age must be 10 or above. Records below this threshold are removed. |
| Date normalization | Both `YYYY-MM-DD` and `MM-DD-YYYY` formats are detected and standardized to `MM-DD-YYYY`. |
| Time normalization | 24-hour times (e.g. `17:57`) are converted to 12-hour AM/PM format (e.g. `05:57 PM`). |
| Gender normalization | Shorthand values `M` and `F` are expanded to `Male` and `Female` respectively. |

---

## Getting Started

### Prerequisites

- g++ (GCC C++ compiler)
- Compatible with Linux, Windows, and macOS

### Compilation

```bash
g++ main.cpp -o main
```

Or using make:

```bash
make main
```

### Running

```bash
./main
```

---

## Usage

On launch, the system prompts for a user ID and password.

```
Enter User ID: 1
Enter Password: 123
```

> The default password is `123`. This can be changed by modifying the `passwd` constant in `main.cpp`.

After login, a menu-driven interface guides the user through all available operations. After each operation, the user is asked whether they want to continue or exit.

```
========== Welcome to Hospital Management System ==========
1. Patient Management
2. Doctor Management
3. Appointment Management
4. Treatments and Billings
5. Search / Reports
6. Exit
```

---

## Author

Developed as a semester project for **Programming Fundamentals**.

---

> This project demonstrates file handling, struct-based data modeling, and menu-driven console application design in C++ without the use of any external libraries or database systems.