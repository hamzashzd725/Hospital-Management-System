# 🏥 Hospital Management System

A file-based Hospital Management System built in **C++** that manages patients, doctors, appointments, treatments, and billing through structured text files.

---

## 📋 Features

### 👤 Patient Management
- Add new patients
- View all patients
- Update patient details (name, age, contact, balance, gender)
- Delete patients

### 🩺 Doctor Management
- Add new doctors
- View all doctors
- Update doctor details (name, specialty, experience)
- Delete doctors
- Sort doctors by years of experience

### 📅 Appointment Management
- Schedule appointments
- View all appointments
- Cancel appointments

### 💊 Treatment & Billing
- Add treatment records
- View all treatments
- Update payment status (Paid / Unpaid)
- Generate bills and deduct from patient balance

### 🔍 Search & Reports
- Search patient by ID or name
- Search doctor by ID or specialty
- View treatments provided by a specific doctor
- Generate billing reports

---

## 🗂️ File Structure

```
.
├── main.cpp
├── patients.txt
├── doctors.txt
├── appointments.txt
├── treatments.txt
└── bills.txt
```

### Data Formats

| File | Format |
|------|--------|
| `patients.txt` | `ID#Name#Age#Gender#Contact#Balance` |
| `doctors.txt` | `ID#Name#Specialty#Experience` |
| `appointments.txt` | `PatientID#DoctorID#Date#Time` |
| `treatments.txt` | `PatientID#Description#Cost#Paid` |
| `bills.txt` | `PatientID#Cost#Status` |

---

## ⚙️ Data Cleaning (Auto-run on startup)

On every startup, the system automatically cleans all data files by:
- Removing records with missing fields (validated by `#` count)
- Removing invalid patient contacts (must be 11 digits)
- Normalizing date formats (`YYYY-MM-DD` and `MM-DD-YYYY` → `MM-DD-YYYY`)
- Converting 24-hour times to 12-hour AM/PM format
- Standardizing gender shorthand (`M` → `Male`, `F` → `Female`)

---

## 🚀 Getting Started

### Prerequisites
- g++ compiler
- Linux / Windows / macOS

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

### Login
The system requires a user ID and password on startup.

```
Enter User ID: 1
Enter Password: 123
```

> Default password is `123`

---

## 🛠️ Built With

- **C++** — core language
- **File I/O** (`ifstream`, `ofstream`) — persistent storage
- **Structs** — data modeling
- No external libraries or databases

---

## 📌 Notes

- All data is stored in plain text files using `#` as a delimiter
- The system uses a temp file strategy for safe in-place updates and deletions
- Dynamic memory is used for struct pointers throughout the system

---

## 👨‍💻 Author

Developed as a semester project for **Programming Fundamentals** course.