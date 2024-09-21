---

# Medical Management System

## Overview

This project is a **Medical Management System** built using C++ and Qt, aimed at managing doctors, patients, and their interactions. The system supports adding, removing, and displaying doctors and patients, as well as filtering patients by specializations. The user interface allows doctors to manage their patients in an intuitive manner, and the system stores data in text files.

### Features

- **Doctor and Patient Management**: Add, remove, and update doctors and patients in the system.
- **Patient Filtering**: Filter patients by their specialization and the responsible doctor.
- **Persistent Storage**: Doctor and patient data are saved to and loaded from text files.
- **GUI**: A simple and user-friendly graphical user interface (GUI) using Qt.
- **Date Validation**: Ensures that patients cannot be added with past dates of admission.

## Project Structure

```bash
.
├── domain/               # Domain models for Doctor and Patient
│   ├── doctor.h          # Doctor class declaration
│   └── doctor.cpp        # Doctor class definition
│   ├── patient.h         # Patient class declaration
│   └── patient.cpp       # Patient class definition
├── repository/           # Repository to manage Doctors and Patients
│   ├── repository.h      # Repository class declaration
│   └── repository.cpp    # Repository class definition
├── service/              # Business logic for the system
│   ├── service.h         # Service class declaration
│   └── service.cpp       # Service class definition
├── gui/                  # GUI files for managing the system
│   ├── gui.h             # GUI class declaration
│   └── gui.cpp           # GUI class definition
├── data/                 # Data files for doctors and patients
│   ├── doctors.txt       # Preloaded doctor data
│   └── patients.txt      # Preloaded patient data
├── main.cpp              # Application entry point
```

## How It Works

- **Doctor and Patient Models**: 
  - The system has two core models: `Doctor` and `Patient`. Each has attributes like `name`, `specialization`, and (for patients) `diagnosis` and `admissionDate`.
  - The `Doctor` and `Patient` classes can be serialized and deserialized for storage.

- **Repository**: 
  - The `Repository` class manages the collection of doctors and patients, with support for adding, removing, and persisting data.

- **Service**:
  - The `Service` class implements the business logic, interfacing with the `Repository`. It provides methods to filter patients by their specialization and get a list of all doctors and patients.

- **GUI**:
  - The system uses the Qt framework for the graphical user interface. Doctors can manage their assigned patients, add new patients, and view filtered lists of patients based on their specialization.

## Build and Run Instructions

### Prerequisites

- **Qt**: Install Qt on your system.
- **C++11**: Make sure your compiler supports C++11 or later.

### Build Instructions

1. Clone the repository:

   ```bash
   git clone https://github.com/your-repository-link/medical-management-system.git
   ```

2. Open the project in Qt Creator, or navigate to the project folder and build it using qmake:

   ```bash
   qmake
   make
   ```

3. Run the application:

   ```bash
   ./medical-management-system
   ```

### Usage

- **Loading Data**: Upon startup, the system loads doctors and patients from the respective `doctors.txt` and `patients.txt` files in the `data` folder.
- **Doctor Interface**: A GUI window will be opened for each doctor loaded from the file, displaying their patients and allowing them to add new patients or filter by their current patients.
  
### Example Data

Sample data in the `doctors.txt` file:

```
Adrian;Pediatrician
Andrei;Ginecologist
```

Sample data in the `patients.txt` file:

```
Bianca;Liver failure;Dentist;Ion;2024-23-07
Alice;Toothache;Dentist;Ion;2024-06-20
Bob;Undiagnosed;;Unknown;2024-06-22
```

### Extending the System

- **Add New Features**: You can extend the system by implementing additional features like searching, sorting, or exporting patient data in different formats.
- **Expand the Domain Model**: Add more attributes to the `Doctor` or `Patient` classes, or introduce new entities (e.g., `Appointment`, `Treatment`).

## License

MIT License. Feel free to use, modify, and distribute this project.

---


