# Hospital Management System

**[Uni · OOP & Advanced Programming · 2022]**

A C++ console application for managing hospital staff and patients using object-oriented design principles — inheritance, polymorphism, and file-based persistence.

## Class Hierarchy

```
Human (base)
├── Doctor
├── Nurse
└── Patient
```

All entities share common attributes (name, ID, age) defined in `Human`. Subclasses extend with role-specific data: doctors have a specialty, nurses have a shift, patients have a diagnosis and assigned doctor.

## Features

- Add / remove / search doctors, nurses, and patients
- Assign doctors to patients
- File-based persistence — data saved across runs (plain text files in `Files/`)
- Tabular display using the bundled `tabulate-master` library

## Build

Requires CMake 3.x and a C++17-compatible compiler.

```bash
mkdir build && cd build
cmake ..
cmake --build .
./hospital_management
```

## Stack

- C++17
- CMake
- [tabulate](https://github.com/p-ranav/tabulate) — terminal table formatting
