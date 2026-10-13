# B.Tech CSE Laboratory Programs

![Course](https://img.shields.io/badge/Course-B.Tech%20CSE-orange.svg)
![University](https://img.shields.io/badge/University-Royal%20Global%20University-maroon.svg)
![Languages](https://img.shields.io/badge/Languages-C%20%7C%20C++%20%7C%20Python%20%7C%20SQL%20%7C%20Assembly-blue.svg)

Laboratory programs and experiment write-ups from the **Bachelor of Technology in Computer
Science and Engineering** at **Royal Global University**, organised by subject. Each folder is
self-contained, and the larger ones have their own README with an experiment index and run
instructions.

---

## Contents

| Folder | Subject | Language | Experiments |
|--------|---------|----------|:-----------:|
| [`DAA/`](DAA/) | Design & Analysis of Algorithms | C | 21 |
| [`DS/`](DS/) | Introduction to Data Science | Python | 40 |
| [`DBMS/`](DBMS/) | Database Management Systems | MySQL | 9 |
| [`c++/`](c++/) | Object-Oriented Programming in C++ | C++ | 56 |
| [`mp/`](mp/) | Microprocessors (8085 / 8086) | Assembly | 15 |
| [`python/`](python/) | Python Programming | Python | 5 |

### Design & Analysis of Algorithms — [`DAA/`](DAA/)
Searching, sorting, divide and conquer, dynamic programming, greedy methods, backtracking and
graph traversal. Every program times its algorithm with `clock()` and counts its basic
operations. Each file follows the lab-record layout: aim, algorithm, program, sample output.

### Introduction to Data Science — [`DS/`](DS/)
A complete data pipeline across 40 experiments: importing, cleaning, exploratory analysis,
modelling and evaluation with Pandas, NumPy, SciPy, Scikit-learn and Seaborn. Each experiment
lives in its own numbered folder.

### Database Management Systems — [`DBMS/`](DBMS/)
MySQL experiments covering queries, joins and unions, stored procedures and triggers. Each guide
contains the schema, setup scripts, query-by-query solutions and expected output tables.

### Object-Oriented Programming in C++ — [`c++/`](c++/)
Programs on classes, constructors and destructors, inheritance, polymorphism, operator and
function overloading, friend functions, templates, exception handling and file I/O. Includes
[`prerequisites.md`](c++/prerequisites.md) and [`viva.md`](c++/viva.md) for revision.

### Microprocessors — [`mp/`](mp/)
8085 and 8086 assembly programs for arithmetic, factorial, squares and finding the largest or
smallest value, each with aim, algorithm and program. Includes an
[instruction reference](mp/microprocessor-instruction-reference.md) and
[viva questions](mp/microprocessor-viva-questions.md).

### Python Programming — [`python/`](python/)
Matrix operations, dictionaries, 2D and 3D arrays, and file handling.

---

## Getting Started

```bash
git clone https://github.com/vxwshxl/Programs.git
cd Programs
```

| Language | Requirement | Compile and run |
|----------|-------------|-----------------|
| C | GCC or Clang | `gcc file.c -o prog && ./prog` |
| C++ | G++ or Clang++ | `g++ "file.cpp" -o prog && ./prog` |
| Python | Python 3 | `python3 file.py` |
| SQL | MySQL | Paste the setup block, then each query, into the MySQL client |
| Assembly | 8085 / 8086 simulator or trainer kit | Enter the program at the listed memory addresses |

The Data Science experiments also need the scientific Python stack:

```bash
pip install pandas numpy scipy scikit-learn matplotlib seaborn openpyxl
```

On macOS, `xcode-select --install` provides `gcc`, `g++` and `clang`. On Windows, use MinGW-w64
or WSL.

---

## Repository Conventions

- **Numbered files.** Files and folders are numbered to match the experiment order of the lab
  record.
- **Sample output included.** Most programs carry a sample run, either as a comment block at the
  end of the source or as a table in the Markdown guide.
- **Build artefacts are ignored.** `*.out`, `*.o` and `*.exe` are listed in `.gitignore`, so
  compiled binaries never reach a commit.

---

## Disclaimer

This repository is intended for educational reference. Read the logic and write your own
solution, because that is how the material sticks.
