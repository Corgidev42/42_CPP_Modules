# CPP Modules - Object-Oriented Programming in C++

## 📌 Description

The **CPP Modules** from **42 School** introduce students to object-oriented programming using **C++98**. Throughout these modules, students learn key concepts such as:

- 📦 **Classes and objects**
- 🔄 **Inheritance and polymorphism**
- 🧩 **Interfaces and abstract classes**
- 🛠 **Canonical class forms**
- ⚠️ **Memory management** (deep copies, dynamic allocation)
- 🗃 **Encapsulation and data abstraction**

The modules progressively guide students from basic class implementation to advanced polymorphic and abstract behaviors.

---

## 🎯 Modules and Key Concepts

### Module 00 - Introduction
- ✅ Namespaces
- ✅ Input/Output Streams
- ✅ Simple classes and member functions

### Module 01 - Memory Management
- ✅ References and pointers
- ✅ Dynamic allocation and deallocation
- ✅ Deep copy vs. shallow copy

### Module 02 - Fixed-point Arithmetic
- ✅ Operator overloading
- ✅ Canonical form
- ✅ Constructors, destructors, copy constructors

### Module 03 - Inheritance
- ✅ Single and multiple inheritance
- ✅ Diamond inheritance problem
- ✅ Virtual inheritance

### Module 04 - Polymorphism & Interfaces
- ✅ Pure virtual functions
- ✅ Abstract classes
- ✅ Interfaces
- ✅ Deep copies in polymorphic hierarchies

---

## 🛠 Compilation and Execution

### 🔧 **Compilation**

Each exercise includes a `Makefile`. Compile using:

```sh
make
```

### ▶️ **Execution**

Run the compiled executable:

```sh
./executable_name
```

---

## 📚 Example Project Structure

```
cpp_module/
├── ex00/
│   ├── main.cpp              # Entry point
│   ├── ClassName.cpp         # Implementation
│   ├── ClassName.hpp         # Declaration
│   └── Makefile              # Compilation
├── ex01/
│   ├── main.cpp
│   ├── ClassName.cpp
│   ├── ClassName.hpp
│   └── Makefile
└── ...                       # Further exercises
```

---

## 📖 Summary of Exercises

### Module 03 (Example)
- **ClapTrap** 🤖: Basic combat robot class.
- **ScavTrap** 🛡️: Defensive robot with gatekeeper mode.
- **FragTrap** 💥: Offensive robot with high damage.
- **DiamondTrap** 💎: Combines ScavTrap and FragTrap behaviors through virtual inheritance.

### Module 04 (Example)
- **Animal Hierarchy** 🐶🐱: Implement polymorphic behavior for animals (Dog, Cat).
- **AMateria Interface** ✨: Create and manage magical materias (Ice, Cure).
- **MateriaSource & Characters** 🎭: Equip and use materias in a polymorphic context.

---

## 📜 Author

- **Vincent Bonnard** (<vbonnard@student.42perpignan.fr>)

---

## 📌 Note

This series of modules was developed as part of the **42 School** curriculum. Contributions and suggestions for improvement are always welcome! 🚀
