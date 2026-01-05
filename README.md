`# Modules CPP - Programmation Orientée Objet en C++

## 📌 Description

Les **Modules CPP** de l'école **42** permettent d'apprendre la programmation orientée objet en utilisant le standard **C++98**. À travers ces modules, les étudiants découvrent des concepts clés tels que :

- 📦 **Classes et objets**
- 🔄 **Héritage et polymorphisme**
- 🧩 **Interfaces et classes abstraites**
- 🛠 **Formes canoniques des classes**
- ⚠️ **Gestion de la mémoire** (copies profondes, allocation dynamique)
- 🗃 **Encapsulation et abstraction des données**
- 🎯 **Templates et programmation générique**
- 🧪 **Conteneurs et algorithmes STL**
- 💾 **Gestion avancée des exceptions**

Les modules progressent depuis l'implémentation de classes basiques jusqu'aux comportements polymorphes et abstraits avancés.

---

## 🎯 Modules Complétés et Concepts Clés

### ✅ Module 00 - Introduction au C++
- ✅ Namespaces et portée
- ✅ Flux d'entrée/sortie (iostream)
- ✅ Classes simples et fonctions membres
- ✅ ex00 : Megaphone
- ✅ ex01 : Mon Répertoire Téléphonique
- ✅ ex02 : Le Job de tes Rêves

### ✅ Module 01 - Gestion de la Mémoire
- ✅ Références et pointeurs
- ✅ Allocation et désallocation dynamique
- ✅ Copie profonde vs. copie superficielle
- ✅ ex00 : BraiiiiiiinnnzzzZ
- ✅ ex01 : Moar brainz!
- ✅ ex02 : HI THIS IS BRAIN
- ✅ ex03 : Violence inutile
- ✅ ex04 : Sed is for losers
- ✅ ex05 : Harl 2.0
- ✅ ex06 : Harl filter

### ✅ Module 02 - Arithmétique en Virgule Fixe
- ✅ Surcharge d'opérateurs
- ✅ Forme canonique orthodoxe
- ✅ Constructeurs, destructeurs, constructeurs de copie
- ✅ ex00 : Ma première classe en forme canonique orthodoxe
- ✅ ex01 : Vers un nombre à virgule fixe plus utile
- ✅ ex02 : Maintenant on parle
- ✅ ex03 : BSP

### ✅ Module 03 - Héritage
- ✅ Héritage simple et multiple
- ✅ Problème du diamant
- ✅ Héritage virtuel
- ✅ ex00 : Aaaaand... OPEN!
- ✅ ex01 : Serena, ma ClapTrap!
- ✅ ex02 : Répétitif, non?
- ✅ ex03 : Now it's weird!

### ✅ Module 04 - Polymorphisme et Interfaces
- ✅ Fonctions virtuelles pures
- ✅ Classes abstraites
- ✅ Interfaces
- ✅ Copies profondes dans les hiérarchies polymorphes
- ✅ ex00 : Polymorphisme
- ✅ ex01 : I don't want to set the world on fire
- ✅ ex02 : Abstract class
- ✅ ex03 : Interface & recap

### ✅ Module 05 - Exceptions et Bureaucratie
- ✅ Gestion des exceptions (try/catch/throw)
- ✅ Classes d'exceptions personnalisées
- ✅ Hiérarchie d'exceptions
- ✅ ex00 : Bureaucrate de base
- ✅ ex01 : Formulaire et bureaucrate
- ✅ ex02 : Formulaires concrets
- ✅ ex03 : L'Intern fait les formulaires

### ✅ Module 06 - Conversions de Types en C++
- ✅ Casts C++ (static_cast, dynamic_cast, reinterpret_cast, const_cast)
- ✅ Conversion de types scalaires
- ✅ Sérialisation et désérialisation
- ✅ Identification de type à l'exécution (RTTI)
- ✅ ex00 : Conversion de types scalaires
- ✅ ex01 : Sérialisation
- ✅ ex02 : Identification du type réel

### ✅ Module 07 - Templates
- ✅ Templates de fonctions
- ✅ Templates de classes
- ✅ Spécialisation de templates
- ✅ Programmation générique
- ✅ ex00 : Quelques fonctions
- ✅ ex01 : iter
- ✅ ex02 : Array

### ✅ Module 08 - Conteneurs Templatés
- ✅ Conteneurs STL (vector, list, stack, etc.)
- ✅ Itérateurs
- ✅ Algorithmes STL
- ✅ Conteneurs personnalisés
- ✅ ex00 : easyfind
- ✅ ex01 : Span
- ✅ ex02 : Mutated abomination

### ✅ Module 09 - Conteneurs STL Avancés
- ✅ std::map et conteneurs associatifs
- ✅ Parsing et traitement de données
- ✅ Algorithmes de tri et recherche
- ✅ Notation polonaise inversée (RPN)
- ✅ ex00 : Bitcoin Exchange
- ✅ ex01 : Reverse Polish Notation
- ✅ ex02 : PmergeMe

---

## 🛠 Compilation et Exécution

### 🔧 **Compilation**

Chaque exercice inclut un `Makefile`. Pour compiler :

```sh
make
```

### ▶️ **Exécution**

Exécuter le programme compilé :

```sh
./nom_executable
```

### 🧹 **Nettoyage**

Pour nettoyer les fichiers objets :

```sh
make clean
```

Pour tout supprimer (objets + exécutable) :

```sh
make fclean
```

---

## 📁 Structure du Projet

```
42_CPP_Modules/
├── 00/                    # Introduction au C++
│   ├── ex00/             # Megaphone
│   ├── ex01/             # Mon Répertoire
│   ├── ex02/             # Le Job de tes Rêves
│   └── Sujet FR.pdf
├── 01/                    # Gestion de la mémoire
│   ├── ex00/             # BraiiiiiiinnnzzzZ
│   ├── ex01/             # Moar brainz!
│   ├── ex02/             # HI THIS IS BRAIN
│   ├── ex03/             # Violence inutile
│   ├── ex04/             # Sed is for losers
│   ├── ex05/             # Harl 2.0
│   └── ex06/             # Harl filter
├── 02/                    # Virgule fixe
│   ├── ex00/             # Forme canonique orthodoxe
│   ├── ex01/             # Nombre à virgule fixe
│   ├── ex02/             # Surcharge d'opérateurs
│   └── ex03/             # BSP
├── 03/                    # Héritage
│   ├── ex00/             # ClapTrap
│   ├── ex01/             # ScavTrap
│   ├── ex02/             # FragTrap
│   └── ex03/             # DiamondTrap
├── 04/                    # Polymorphisme
│   ├── ex00/             # Polymorphisme basique
│   ├── ex01/             # Matérias
│   ├── ex02/             # Classes abstraites
│   └── ex03/             # Interface & recap
├── 05/                    # Exceptions
│   ├── ex00/             # Bureaucrat
│   ├── ex01/             # Form
│   ├── ex02/             # Formulaires concrets
│   └── ex03/             # Intern
├── 06/                    # Conversions
│   ├── ex00/             # ScalarConverter
│   ├── ex01/             # Serialization
│   └── ex02/             # Type identification
├── 07/                    # Templates
│   ├── ex00/             # Fonctions templates
│   ├── ex01/             # iter
│   └── ex02/             # Array
├── 08/                    # Conteneurs templatés
│   ├── ex00/             # easyfind
│   ├── ex01/             # Span
│   └── ex02/             # MutantStack
├── 09/                    # STL avancé
│   ├── ex00/             # Bitcoin Exchange
│   ├── ex01/             # RPN
│   └── ex02/             # PmergeMe
└── README.md
```

---

## 📊 Progression

| Module | Status | Exercices | Concepts Clés |
|--------|--------|-----------|---------------|
| **00** | ✅ Complété | 3/3 | Introduction, Classes de base |
| **01** | ✅ Complété | 7/7 | Mémoire, Références, Pointeurs |
| **02** | ✅ Complété | 4/4 | Surcharge d'opérateurs, Forme canonique |
| **03** | ✅ Complété | 4/4 | Héritage, Héritage virtuel |
| **04** | ✅ Complété | 4/4 | Polymorphisme, Classes abstraites |
| **05** | ✅ Complété | 4/4 | Exceptions, Hiérarchie d'exceptions |
| **06** | ✅ Complété | 3/3 | Casts C++, Sérialisation, RTTI |
| **07** | ✅ Complété | 3/3 | Templates de fonctions et classes |
| **08** | ✅ Complété | 3/3 | Conteneurs STL, Itérateurs |
| **09** | ✅ Complété | 3/3 | Conteneurs associatifs, Algorithmes |

**Total : 10/10 modules complétés** 🎉

---

## 🎓 Compétences Acquises

Au cours de ces modules, j'ai développé une expertise dans :

- ✅ **Programmation orientée objet** en C++98
- ✅ **Gestion manuelle de la mémoire** (allocation/désallocation)
- ✅ **Hiérarchies de classes** complexes avec héritage multiple
- ✅ **Polymorphisme** et comportements virtuels
- ✅ **Templates** et programmation générique
- ✅ **STL** (Standard Template Library) : conteneurs, itérateurs, algorithmes
- ✅ **Gestion d'exceptions** robuste et hiérarchisée
- ✅ **Bonnes pratiques** C++ : RAII, forme canonique orthodoxe
- ✅ **Optimisation** et choix de structures de données appropriées
- ✅ **Parsing et traitement** de données complexes

---

## 📜 Auteur

- **Vincent Bonnard** (<vbonnard@student.42perpignan.fr>)

---

## 📌 Note

Cette série de modules a été développée dans le cadre du cursus de l'**École 42**. Les contributions et suggestions d'amélioration sont toujours les bienvenues ! 🚀

---

## 📚 Ressources Utiles

- [CPP Reference](https://en.cppreference.com/)
- [CPlusPlus.com](https://www.cplusplus.com/)
- [LearnCPP](https://www.learncpp.com/)
- [42 Docs](https://harm-smits.github.io/42docs/)
