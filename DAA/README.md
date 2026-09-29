# ⚡ Design & Analysis of Algorithms

![Language](https://img.shields.io/badge/Language-C++-blue.svg)
![Course](https://img.shields.io/badge/Course-DAA%20Lab-red.svg)
![University](https://img.shields.io/badge/University-Royal%20Global%20University-maroon.svg)
![Programs](https://img.shields.io/badge/Programs-13-green.svg)

> Searching and sorting, written the plain way — then **timed with `clock()`** so the Big-O
> on the whiteboard shows up as an actual number in your terminal.

Every program here follows the same four beats:

```
   read input  ─→  start = clock()  ─→  run algorithm  ─→  end = clock()
                                                            │
                        result + comparisons + seconds  ←────┘
```

---

## 📁 The Programs

| # | File | Algorithm | Best | Average | Worst |
|:-:|------|-----------|:----:|:-------:|:-----:|
| 1 | [1_linear.cpp](1_linear.cpp) | 🔍 Linear Search | `O(1)` | `O(n)` | `O(n)` |
| 2 | [2_binary.cpp](2_binary.cpp) | 🎯 Binary Search | `O(1)` | `O(log n)` | `O(log n)` |
| 3 | [3_bubble.cpp](3_bubble.cpp) | 🫧 Bubble Sort | `O(n²)` | `O(n²)` | `O(n²)` |
| 4 | [4_selection.cpp](4_selection.cpp) | 🎪 Selection Sort | `O(n²)` | `O(n²)` | `O(n²)` |
| 5 | [5_insertion.cpp](5_insertion.cpp) | 🃏 Insertion Sort | `O(n)` | `O(n²)` | `O(n²)` |
| 6 | [6_radix.cpp](6_radix.cpp) | 🔢 Radix Sort | `O(d·n)` | `O(d·n)` | `O(d·n)` |
| 7 | [7_bucket.cpp](7_bucket.cpp) | 🪣 Bucket Sort | `O(n+k)` | `O(n+k)` | `O(n²)` |
| 8 | [8_quick.cpp](8_quick.cpp) | ⚡ Quick Sort | `O(n log n)` | `O(n log n)` | `O(n²)` |
| 9 | [9_merge.cpp](9_merge.cpp) | 🧬 Merge Sort | `O(n log n)` | `O(n log n)` | `O(n log n)` |
| 10 | [10_fibonacci_recursive.cpp](10_fibonacci_recursive.cpp) | 🌀 Fibonacci (Recursion) | `O(2ⁿ)` | `O(2ⁿ)` | `O(2ⁿ)` |
| 11 | [11_fibonacci_dynamic.cpp](11_fibonacci_dynamic.cpp) | 📋 Fibonacci (DP) | `O(n)` | `O(n)` | `O(n)` |
| 12 | [12_matrix_chain_multi.cpp](12_matrix_chain_multi.cpp) | 🔗 Matrix Chain Multiplication | `O(n³)` | `O(n³)` | `O(n³)` |
| 13 | [13_knapsack_algorithm.cpp](13_knapsack_algorithm.cpp) | 🎒 0/1 Knapsack (DP) | `O(nW)` | `O(nW)` | `O(nW)` |

Each `.cpp` carries a sample run pasted at the bottom as an `// Output:` comment block — handy
when you need to write the lab record and the terminal is already closed.

---

## 🚀 Quick Start

```bash
cd ~/Programs/DAA

g++ -o 5.out 5_insertion.cpp    # compile
./5.out                         # run
```

Build all twelve in one shot:

```bash
for f in *.cpp; do g++ -o "${f%.cpp}.out" "$f"; done
```

The `.out` binaries are gitignored, so build freely — nothing leaks into commits.
Recompile after every edit; the binary is only a snapshot of the source.

---

## 💻 A Real Session

```console
$ ./3.out
Enter the number of elements:6
Enter the elements:42 8 27 14 35 19

After bubble sorting:	8	14	19	27	35	42
Number of comparisons:15
Time taken:0.000005 seconds
Time complexity: O(n^2)
```

Three numbers come back every time:

| Line | What it tells you |
|------|-------------------|
| **Result** | the sorted array, or where the key was found |
| **Comparisons** | the operation count — the honest, machine-independent measure |
| **Time taken** | wall-clock seconds from `clock()`, the point of the exercise |

---

## ⏱️ Why Two Measurements?

`clock()` is coarse. On a hand-typed array of six elements the whole algorithm finishes in a
few microseconds, so the timer reports something near zero and the growth curve stays invisible.
The comparison counter never lies — it's the theory, counted directly.

Want to *see* the curve? Feed the sorts a few thousand elements and watch the pattern:

| n | comparisons (bubble/selection) | what happens to the time |
|--:|-------------------------------:|--------------------------|
| 1,000  | 499,500     | baseline |
| 2,000  | 1,999,000   | ~4× longer |
| 4,000  | 7,998,000   | ~16× longer |
| 8,000  | 31,996,000  | ~64× longer |

Double the input, quadruple the work — `O(n²)` made visible. Binary search, meanwhile, needs
about 10 comparisons for 1,000 elements and only ~20 for a million. That gap *is* the course.

Quick way to generate a big input:

```bash
{ echo 5000; seq 5000 | sort -R; } | ./3.out
```

---

## 🛠️ Built With

- `<iostream>` — I/O, nothing more
- `<time.h>` — `clock()`, `clock_t`, `CLOCKS_PER_SEC`

No STL containers, no `<algorithm>`, no `std::sort`. Every loop is written out by hand,
because the point is the loop.

<details>
<summary>📌 A note on <code>int a[n]</code></summary>

<br>

The arrays are sized from a runtime variable. That's a **variable length array** — standard in C,
a compiler extension in C++. GCC and Clang accept it happily, and every lab compiler does too;
`-Wall` will mention it. Swap in `int *a = new int[n];` if you ever need it strictly standard.

</details>

---

## ⚙️ Requirements

A C++ compiler — that's the whole list.

- **macOS** → `xcode-select --install`
- **Linux** → `sudo apt install g++`
- **Windows** → MinGW-w64, or WSL

---

<div align="center">

**Educational use.** Read the logic, then write it yourself — that's where it sticks.

</div>
