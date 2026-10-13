# ⚡ Design & Analysis of Algorithms

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Course](https://img.shields.io/badge/Course-DAA%20Lab-red.svg)
![University](https://img.shields.io/badge/University-Royal%20Global%20University-maroon.svg)
![Programs](https://img.shields.io/badge/Programs-21-green.svg)

> Searching, sorting, DP, greedy, backtracking and graphs — written the plain way — then **timed with `clock()`** so the Big-O
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
| 01 | [01_linear.c](01_linear.c) | 🔍 Linear Search | `O(1)` | `O(n)` | `O(n)` |
| 02 | [02_binary.c](02_binary.c) | 🎯 Binary Search | `O(1)` | `O(log n)` | `O(log n)` |
| 03 | [03_bubble.c](03_bubble.c) | 🫧 Bubble Sort | `O(n²)` | `O(n²)` | `O(n²)` |
| 04 | [04_selection.c](04_selection.c) | 🎪 Selection Sort | `O(n²)` | `O(n²)` | `O(n²)` |
| 05 | [05_insertion.c](05_insertion.c) | 🃏 Insertion Sort | `O(n)` | `O(n²)` | `O(n²)` |
| 06 | [06_radix.c](06_radix.c) | 🔢 Radix Sort | `O(d·n)` | `O(d·n)` | `O(d·n)` |
| 07 | [07_bucket.c](07_bucket.c) | 🪣 Bucket Sort | `O(n+k)` | `O(n+k)` | `O(n²)` |
| 08 | [08_quick.c](08_quick.c) | ⚡ Quick Sort | `O(n log n)` | `O(n log n)` | `O(n²)` |
| 09 | [09_merge.c](09_merge.c) | 🧬 Merge Sort | `O(n log n)` | `O(n log n)` | `O(n log n)` |
| 10 | [10_fibonacci_recursive.c](10_fibonacci_recursive.c) | 🌀 Fibonacci (Recursion) | `O(2ⁿ)` | `O(2ⁿ)` | `O(2ⁿ)` |
| 11 | [11_fibonacci_dynamic.c](11_fibonacci_dynamic.c) | 📋 Fibonacci (DP) | `O(n)` | `O(n)` | `O(n)` |
| 12 | [12_matrix_chain_multi.c](12_matrix_chain_multi.c) | 🔗 Matrix Chain Multiplication | `O(n³)` | `O(n³)` | `O(n³)` |
| 13 | [13_knapsack_algorithm.c](13_knapsack_algorithm.c) | 🎒 0/1 Knapsack (DP) | `O(nW)` | `O(nW)` | `O(nW)` |
| 14 | [14_lcs.c](14_lcs.c) | 🧵 Longest Common Subsequence (DP) | `O(mn)` | `O(mn)` | `O(mn)` |
| 15 | [15_fractional_knapsack.c](15_fractional_knapsack.c) | 🧀 Fractional Knapsack (Greedy) | `O(n log n)` | `O(n log n)` | `O(n log n)` |
| 16 | [16_job_scheduling.c](16_job_scheduling.c) | 📅 Job Sequencing with Deadlines (Greedy) | `O(n log n)` | `O(n²)` | `O(n²)` |
| 17 | [17_huffman.c](17_huffman.c) | 🌳 Huffman Coding (Greedy) | `O(n log n)` | `O(n log n)` | `O(n log n)` |
| 18 | [18_n_queen.c](18_n_queen.c) | ♛ N-Queen (Backtracking) | `O(n!)` | `O(n!)` | `O(n!)` |
| 19 | [19_travelling_salesman.c](19_travelling_salesman.c) | 🧳 Travelling Salesman (DP) | `O(n²·2ⁿ)` | `O(n²·2ⁿ)` | `O(n²·2ⁿ)` |
| 20 | [20_bfs.c](20_bfs.c) | 🌊 Breadth First Search | `O(V+E)` | `O(V+E)` | `O(V+E)` |
| 21 | [21_dfs.c](21_dfs.c) | 🕳️ Depth First Search | `O(V+E)` | `O(V+E)` | `O(V+E)` |

BFS and DFS read the graph as an adjacency matrix, which makes them `O(V²)` in practice —
`O(V+E)` is the adjacency-list bound.

Each `.c` file is laid out the way it goes into the lab record:

1. **Aim** — the question, as the first comment line
2. **Algorithm** — numbered steps in a `/* ... */` block, matching the code line for line
3. **Program** — the C source
4. **Output** — a sample run pasted at the bottom as an `// Output:` comment block

Handy when you need to write the record and the terminal is already closed.

---

## 📒 Lab Record Index

Copied from the index page of the lab notebook. **Date of Submission** is left blank to fill in.

| S. No. | Name of the Experiment | Page No. | Date of Experiment | Date of Submission |
|:------:|------------------------|:--------:|:------------------:|:------------------:|
| 01 | Linear Search | 01 | 05/08/26 | |
| 02 | Binary Search | 02–03 | 05/08/26 | |
| 03 | Bubble Sort | 04 | 05/08/26 | |
| 04 | Selection Sort | 05 | 05/08/26 | |
| 05 | Insertion Sort | 06 | 12/08/26 | |
| 06 | Radix Sort | 07–08 | 12/08/26 | |
| 07 | Bucket Sort | 09–10 | 12/08/26 | |
| 08 | Quick Sort | 11–12 | 02/09/26 | |
| 09 | Merge Sort | 13–14 | 02/09/26 | |
| 10 | Fibonacci Series – Recursive | 15 | 02/09/26 | |
| 11 | Fibonacci – DP | 16 | 02/09/26 | |
| 12 | MCM (Matrix Chain Multiplication) | 17 | 09/09/26 | |
| 13 | 0/1 Knapsack | 18 | 09/09/26 | |
| 14 | LCS (Longest Common Subsequence) | 19 | 09/09/26 | |
| 15 | Fractional Knapsack | 20–21 | 16/09/26 | |
| 16 | Task / Job Scheduling | 22–23 | 30/09/26 | |
| 17 | Huffman Coding | 23–24 | 30/09/26 | |
| 18 | N-Queen Problem | 26–27 | 07/10/26 | |
| 19 | Travelling Salesman | 28–29 | 07/10/26 | |
| 20 | BFS | 30 | 07/10/26 | |
| 21 | DFS | 31 | 07/10/26 | |

Experiment numbers match the file numbers above.

---

## 🚀 Quick Start

```bash
cd ~/Programs/DAA

gcc -o 05.out 05_insertion.c     # compile
./05.out                        # run
```

Build all of them in one shot:

```bash
for f in *.c; do gcc -o "${f%.c}.out" "$f"; done
```

The `.out` binaries are gitignored, so build freely — nothing leaks into commits.
Recompile after every edit; the binary is only a snapshot of the source.

---

## 💻 A Real Session

```console
$ ./03.out
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
{ echo 5000; seq 5000 | sort -R; } | ./03.out
```

---

## 🛠️ Built With

- `<stdio.h>` — `printf` and `scanf`, nothing more
- `<string.h>` — `strlen`, only in LCS
- `<time.h>` — `clock()`, `clock_t`, `CLOCKS_PER_SEC`

No library sorting, no `qsort`. Every loop is written out by hand,
because the point is the loop.

<details>
<summary>📌 A note on <code>int a[n]</code></summary>

<br>

The arrays are sized from a runtime variable. That's a **variable length array**, standard since
C99, and GCC and Clang accept it by default. On a very old compiler such as Turbo C, give the array
a fixed size like `int a[100];` instead.

</details>

---

## ⚙️ Requirements

A C compiler — that's the whole list.

- **macOS** → `xcode-select --install`
- **Linux** → `sudo apt install gcc`
- **Windows** → MinGW-w64, or WSL

---

<div align="center">

**Educational use.** Read the logic, then write it yourself — that's where it sticks.

</div>
