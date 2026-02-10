# CPP Modules - Object-Oriented Programming in C++

## Description

The **CPP Modules** from **42** teach object-oriented programming using the
**C++98** standard. Across these modules, students work through key concepts:

- **Classes and objects**
- **Inheritance and polymorphism**
- **Interfaces and abstract classes**
- **Canonical form**
- **Memory management** (deep copies, dynamic allocation)
- **Encapsulation and data abstraction**
- **Templates and generic programming**
- **STL containers and algorithms**
- **Advanced exception handling**

The progression goes from basic class design to advanced polymorphic behavior
and abstraction.

---

## Completed Modules and Key Concepts

### Module 00 - C++ Introduction
- Namespaces and scope
- IO streams (iostream)
- Simple classes and member functions
- ex00: Megaphone
- ex01: My PhoneBook
- ex02: The Job of Your Dreams

### Module 01 - Memory Management
- References and pointers
- Dynamic allocation and deallocation
- Deep copy vs shallow copy
- ex00: BraiiiiiiinnnzzzZ
- ex01: Moar brainz!
- ex02: HI THIS IS BRAIN
- ex03: Unnecessary violence
- ex04: Sed is for losers
- ex05: Harl 2.0
- ex06: Harl filter

### Module 02 - Fixed-Point Arithmetic
- Operator overloading
- Orthodox canonical form
- Constructors, destructors, copy constructors
- ex00: My first canonical form class
- ex01: A more useful fixed-point number
- ex02: Now we're talking
- ex03: BSP

### Module 03 - Inheritance
- Single and multiple inheritance
- Diamond problem
- Virtual inheritance
- ex00: Aaaaand... OPEN!
- ex01: Serena, my ClapTrap!
- ex02: Repetitive, isn't it?
- ex03: Now it's weird!

### Module 04 - Polymorphism and Interfaces
- Pure virtual functions
- Abstract classes
- Interfaces
- Deep copies in polymorphic hierarchies
- ex00: Polymorphism
- ex01: I don't want to set the world on fire
- ex02: Abstract class
- ex03: Interface & recap

### Module 05 - Exceptions and Bureaucracy
- Exception handling (try/catch/throw)
- Custom exception classes
- Exception hierarchies
- ex00: Basic Bureaucrat
- ex01: Form and bureaucrat
- ex02: Concrete forms
- ex03: The Intern makes the forms

### Module 06 - Type Conversions in C++
- C++ casts (static_cast, dynamic_cast, reinterpret_cast, const_cast)
- Scalar type conversion
- Serialization and deserialization
- Runtime type identification (RTTI)
- ex00: Scalar conversion
- ex01: Serialization
- ex02: Real type identification

### Module 07 - Templates
- Function templates
- Class templates
- Template specialization
- Generic programming
- ex00: Some template functions
- ex01: iter
- ex02: Array

### Module 08 - Templated Containers
- STL containers (vector, list, stack, etc.)
- Iterators
- STL algorithms
- Custom containers
- ex00: easyfind
- ex01: Span
- ex02: Mutated abomination

### Module 09 - Advanced STL Containers
- std::map and associative containers
- Parsing and data processing
- Sorting and searching algorithms
- Reverse Polish Notation (RPN)
- ex00: Bitcoin Exchange
- ex01: Reverse Polish Notation
- ex02: PmergeMe

---

## Build and Run

### Compilation

Each exercise includes a `Makefile`. To compile:

```sh
make
```

### Execution

Run the compiled program:

```sh
./executable_name
```

### Cleanup

Remove object files:

```sh
make clean
```

Remove objects and executables:

```sh
make fclean
```

---

## Project Structure

```
42_CPP_Modules/
├── 00/                    # C++ introduction
│   ├── ex00/             # Megaphone
│   ├── ex01/             # My PhoneBook
│   ├── ex02/             # The Job of Your Dreams
│   └── Subject FR.pdf
├── 01/                    # Memory management
│   ├── ex00/             # BraiiiiiiinnnzzzZ
│   ├── ex01/             # Moar brainz!
│   ├── ex02/             # HI THIS IS BRAIN
│   ├── ex03/             # Unnecessary violence
│   ├── ex04/             # Sed is for losers
│   ├── ex05/             # Harl 2.0
│   └── ex06/             # Harl filter
├── 02/                    # Fixed-point arithmetic
│   ├── ex00/             # Orthodox canonical form
│   ├── ex01/             # Fixed-point numbers
│   ├── ex02/             # Operator overloading
│   └── ex03/             # BSP
├── 03/                    # Inheritance
│   ├── ex00/             # ClapTrap
│   ├── ex01/             # ScavTrap
│   ├── ex02/             # FragTrap
│   └── ex03/             # DiamondTrap
├── 04/                    # Polymorphism
│   ├── ex00/             # Basic polymorphism
│   ├── ex01/             # Materia
│   ├── ex02/             # Abstract classes
│   └── ex03/             # Interface & recap
├── 05/                    # Exceptions
│   ├── ex00/             # Bureaucrat
│   ├── ex01/             # Form
│   ├── ex02/             # Concrete forms
│   └── ex03/             # Intern
├── 06/                    # Conversions
│   ├── ex00/             # ScalarConverter
│   ├── ex01/             # Serialization
│   └── ex02/             # Type identification
├── 07/                    # Templates
│   ├── ex00/             # Template functions
│   ├── ex01/             # iter
│   └── ex02/             # Array
├── 08/                    # Templated containers
│   ├── ex00/             # easyfind
│   ├── ex01/             # Span
│   └── ex02/             # MutantStack
├── 09/                    # Advanced STL
│   ├── ex00/             # Bitcoin Exchange
│   ├── ex01/             # RPN
│   └── ex02/             # PmergeMe
└── README.md
```

---

## Progress

| Module | Status | Exercises | Key Concepts |
|--------|--------|-----------|--------------|
| **00** | Completed | 3/3 | Basics, classes |
| **01** | Completed | 7/7 | Memory, references, pointers |
| **02** | Completed | 4/4 | Operator overloading, canonical form |
| **03** | Completed | 4/4 | Inheritance, virtual inheritance |
| **04** | Completed | 4/4 | Polymorphism, abstract classes |
| **05** | Completed | 4/4 | Exceptions, exception hierarchies |
| **06** | Completed | 3/3 | Casts, serialization, RTTI |
| **07** | Completed | 3/3 | Function/class templates |
| **08** | Completed | 3/3 | STL containers, iterators |
| **09** | Completed | 3/3 | Associative containers, algorithms |

**Total: 10/10 modules completed**

---

## Skills Gained

Through these modules, I developed expertise in:

- **Object-oriented programming** in C++98
- **Manual memory management** (allocation/deallocation)
- **Complex class hierarchies** with multiple inheritance
- **Polymorphism** and virtual behavior
- **Templates** and generic programming
- **STL**: containers, iterators, algorithms
- **Exception handling** and custom error types
- **C++ good practices**: RAII, canonical form
- **Optimization** and data structure choices
- **Parsing and data processing**

---

## Author

- **Vincent Bonnard** (<vbonnard@student.42perpignan.fr>)

---

## Note

This project was developed as part of the **42 School** curriculum. Suggestions
and improvements are welcome.

---

## Useful Resources

- [CPP Reference](https://en.cppreference.com/)
- [CPlusPlus.com](https://www.cplusplus.com/)
- [LearnCPP](https://www.learncpp.com/)
- [42 Docs](https://harm-smits.github.io/42docs/)
