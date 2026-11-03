<div align="center">

<img src="assets/banner.svg" width="100%" alt="ShellScripts banner"/>

<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/bash/bash-original.svg" width="110" alt="Bash logo"/>

<br/>

<a href="https://github.com/vxwshxl/ShellScripts">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=20&duration=2800&pause=800&color=4EAA25&center=true&vCenter=true&width=520&lines=%24+.%2F01_add.sh;%24+.%2F07_prime.sh+%E2%9C%94;%24+gcc+15_fcfs.c+-o+15_fcfs;%24+.%2F28_pascal_triangle.sh;%24+.%2F30_linux_commands.sh" alt="Typing SVG"/>
</a>

<br/>

<img src="https://img.shields.io/badge/Shell-Bash-4EAA25?style=for-the-badge&logo=gnubash&logoColor=white" alt="Shell"/>
<img src="https://img.shields.io/badge/C-gcc-A8B9CC?style=for-the-badge&logo=c&logoColor=black" alt="C"/>
<img src="https://img.shields.io/badge/macOS-Linux-000000?style=for-the-badge&logo=apple&logoColor=white" alt="Platform"/>
<img src="https://img.shields.io/badge/Lessons-30-1f6f3f?style=for-the-badge&logo=files&logoColor=white" alt="Lessons"/>
<img src="https://img.shields.io/badge/Subject-OS%20Lab-8A2BE2?style=for-the-badge&logo=linux&logoColor=white" alt="OS Lab"/>

</div>

---

## 📑 Contents

- [⚡ Quick start](#-quick-start)
- [📚 All lessons](#-all-lessons)
- [🖥️ Outputs](#%EF%B8%8F-outputs)
- [🛠️ Troubleshooting](#%EF%B8%8F-troubleshooting)

---

## ⚡ Quick start

```bash
# 1. Clone the repo
git clone https://github.com/vxwshxl/ShellScripts.git
cd ShellScripts

# 2. Make every script executable (one time only)
chmod +x *.sh

# 3. Run any shell script
./07_prime.sh

# 4. Compile and run a C program (lessons 15 and 16)
gcc 15_fcfs.c -o 15_fcfs
./15_fcfs
```

> [!TIP]
> Every file is named `<lesson>_<name>`, and the sample output is also saved as a comment at the bottom of each file.

> [!NOTE]
> Programs are interactive: type what they ask for and press <kbd>Enter</kbd>. Where a prompt asks for several values (like `85 90 78 92`), type them on one line separated by spaces.

---

## 📚 All lessons

| # | | File | What it does | Run |
|:--:|:--:|:--|:--|:--|
| [1](#lesson-1) | ➕ | [`01_add.sh`](01_add.sh) | Add two numbers | `./01_add.sh` |
| [2](#lesson-2) | 💰 | [`02_simple_interest.sh`](02_simple_interest.sh) | Simple interest and total amount | `./02_simple_interest.sh` |
| [3](#lesson-3) | ⚖️ | [`03_odd_even.sh`](03_odd_even.sh) | Odd or even check | `./03_odd_even.sh` |
| [4](#lesson-4) | ❗ | [`04_factorial.sh`](04_factorial.sh) | Factorial of a number | `./04_factorial.sh` |
| [5](#lesson-5) | 🔄 | [`05_reverse.sh`](05_reverse.sh) | Reverse of a number | `./05_reverse.sh` |
| [6](#lesson-6) | 🔢 | [`06_sum_of_digits.sh`](06_sum_of_digits.sh) | Sum of the digits of a number | `./06_sum_of_digits.sh` |
| [7](#lesson-7) | 🔍 | [`07_prime.sh`](07_prime.sh) | Prime number check | `./07_prime.sh` |
| [8](#lesson-8) | 🌀 | [`08_fibonacci.sh`](08_fibonacci.sh) | Fibonacci series of *n* terms | `./08_fibonacci.sh` |
| [9](#lesson-9) | ⭕ | [`09_area_of_circle.sh`](09_area_of_circle.sh) | Area of a circle | `./09_area_of_circle.sh` |
| [10](#lesson-10) | 🤝 | [`10_gcd.sh`](10_gcd.sh) | GCD of two numbers (Euclid) | `./10_gcd.sh` |
| [11](#lesson-11) | 3️⃣ | [`11_sum_of_3_digits.sh`](11_sum_of_3_digits.sh) | Sum of the digits of a 3 digit number | `./11_sum_of_3_digits.sh` |
| [12](#lesson-12) | ➗ | [`12_sum_odd_even.sh`](12_sum_odd_even.sh) | Sum of odd and even numbers from 1 to 50 | `./12_sum_odd_even.sh` |
| [13](#lesson-13) | ✖️ | [`13_multiplication_table.sh`](13_multiplication_table.sh) | Multiplication table | `./13_multiplication_table.sh` |
| [14](#lesson-14) | 📐 | [`14_circumference_of_circle.sh`](14_circumference_of_circle.sh) | Circumference of a circle | `./14_circumference_of_circle.sh` |
| [15](#lesson-15) | 🚦 | [`15_fcfs.c`](15_fcfs.c) | **C:** FCFS CPU scheduling | `gcc 15_fcfs.c -o 15_fcfs && ./15_fcfs` |
| [16](#lesson-16) | 🏁 | [`16_priority_scheduling.c`](16_priority_scheduling.c) | **C:** Priority CPU scheduling (non-preemptive) | `gcc 16_priority_scheduling.c -o 16_priority_scheduling && ./16_priority_scheduling` |
| [17](#lesson-17) | 📅 | [`17_leap_year.sh`](17_leap_year.sh) | Leap year check | `./17_leap_year.sh` |
| [18](#lesson-18) | 🔁 | [`18_menu_case.sh`](18_menu_case.sh) | Infinite loop menu: multiply / subtract with `case` | `./18_menu_case.sh` |
| [19](#lesson-19) | 🔀 | [`19_swap.sh`](19_swap.sh) | Swap two numbers without a third variable | `./19_swap.sh` |
| [20](#lesson-20) | 🎓 | [`20_grade.sh`](20_grade.sh) | Grade from the marks of 4 subjects | `./20_grade.sh` |
| [21](#lesson-21) | ⚡ | [`21_power.sh`](21_power.sh) | Power of a number without predefined functions | `./21_power.sh` |
| [22](#lesson-22) | 🧩 | [`22_factorial_function.sh`](22_factorial_function.sh) | Factorial using a shell function | `./22_factorial_function.sh` |
| [23](#lesson-23) | 🪪 | [`23_full_name.sh`](23_full_name.sh) | Full name from title and name | `./23_full_name.sh` |
| [24](#lesson-24) | 🔺 | [`24_pyramid.sh`](24_pyramid.sh) | Star pyramid | `./24_pyramid.sh` |
| [25](#lesson-25) | 🔢 | [`25_number_pattern.sh`](25_number_pattern.sh) | Number pattern for *n* terms | `./25_number_pattern.sh` |
| [26](#lesson-26) | 📦 | [`26_array_input.sh`](26_array_input.sh) | Input array elements and display them | `./26_array_input.sh` |
| [27](#lesson-27) | 🏆 | [`27_largest_in_array.sh`](27_largest_in_array.sh) | Largest element in an array | `./27_largest_in_array.sh` |
| [28](#lesson-28) | 🔻 | [`28_pascal_triangle.sh`](28_pascal_triangle.sh) | Pascal's triangle for *n* terms | `./28_pascal_triangle.sh` |
| [29](#lesson-29) | 🥇 | [`29_largest_of_three.sh`](29_largest_of_three.sh) | Largest of three numbers | `./29_largest_of_three.sh` |
| [30](#lesson-30) | 🐧 | [`30_linux_commands.sh`](30_linux_commands.sh) | Linux commands: `mkdir` `cd` `ls` `cat` `>>` `grep` `sed` `cal` `xclock` `oclock` | `./30_linux_commands.sh` |

---

## 🖥️ Outputs

Each output below is a real run of the program. What you type (the input) appears right after the prompt that asks for it.

<a id="lesson-1"></a>
<details>
<summary><b>➕ Lesson 1: <code>01_add.sh</code></b> &nbsp;·&nbsp; input: 12, 8</summary>

```text
Enter the first number:
12
Enter the second number:
8
Sum of 12 and 8 = 20
```

</details>

<a id="lesson-2"></a>
<details>
<summary><b>💰 Lesson 2: <code>02_simple_interest.sh</code></b> &nbsp;·&nbsp; input: P=5000, R=8, T=3</summary>

```text
Enter the principal amount:
5000
Enter the rate of interest (% per year):
8
Enter the time (in years):
3
Simple Interest = 1200.00
Total Amount    = 6200.00
```

</details>

<a id="lesson-3"></a>
<details>
<summary><b>⚖️ Lesson 3: <code>03_odd_even.sh</code></b> &nbsp;·&nbsp; input: 7</summary>

```text
Enter a number:
7
7 is an Odd number
```

</details>

<a id="lesson-4"></a>
<details>
<summary><b>❗ Lesson 4: <code>04_factorial.sh</code></b> &nbsp;·&nbsp; input: 5</summary>

```text
Enter a number:
5
Factorial of 5 = 120
```

</details>

<a id="lesson-5"></a>
<details>
<summary><b>🔄 Lesson 5: <code>05_reverse.sh</code></b> &nbsp;·&nbsp; input: 12345</summary>

```text
Enter a number:
12345
Reverse of 12345 = 54321
```

</details>

<a id="lesson-6"></a>
<details>
<summary><b>🔢 Lesson 6: <code>06_sum_of_digits.sh</code></b> &nbsp;·&nbsp; input: 4567</summary>

```text
Enter a number:
4567
Sum of digits of 4567 = 22
```

</details>

<a id="lesson-7"></a>
<details>
<summary><b>🔍 Lesson 7: <code>07_prime.sh</code></b> &nbsp;·&nbsp; input: 29</summary>

```text
Enter a number:
29
29 is a Prime number
```

</details>

<a id="lesson-8"></a>
<details>
<summary><b>🌀 Lesson 8: <code>08_fibonacci.sh</code></b> &nbsp;·&nbsp; input: 10</summary>

```text
Enter the number of terms:
10
Fibonacci Series of 10 terms:
0 1 1 2 3 5 8 13 21 34
```

</details>

<a id="lesson-9"></a>
<details>
<summary><b>⭕ Lesson 9: <code>09_area_of_circle.sh</code></b> &nbsp;·&nbsp; input: r = 7</summary>

```text
Enter the radius of the circle:
7
Area of the circle = 153.86
```

</details>

<a id="lesson-10"></a>
<details>
<summary><b>🤝 Lesson 10: <code>10_gcd.sh</code></b> &nbsp;·&nbsp; input: 48, 18</summary>

```text
Enter the first number:
48
Enter the second number:
18
GCD of 48 and 18 = 6
```

</details>

<a id="lesson-11"></a>
<details>
<summary><b>3️⃣ Lesson 11: <code>11_sum_of_3_digits.sh</code></b> &nbsp;·&nbsp; input: 456</summary>

```text
Enter a 3 digit number:
456
4 + 5 + 6 = 15
Sum of digits of 456 = 15
```

</details>

<a id="lesson-12"></a>
<details>
<summary><b>➗ Lesson 12: <code>12_sum_odd_even.sh</code></b> &nbsp;·&nbsp; input: no input</summary>

```text
Sum of odd numbers from 1 to 50  = 625
Sum of even numbers from 1 to 50 = 650
```

</details>

<a id="lesson-13"></a>
<details>
<summary><b>✖️ Lesson 13: <code>13_multiplication_table.sh</code></b> &nbsp;·&nbsp; input: 7</summary>

```text
Enter a number:
7
7 x 1 = 7
7 x 2 = 14
7 x 3 = 21
7 x 4 = 28
7 x 5 = 35
7 x 6 = 42
7 x 7 = 49
7 x 8 = 56
7 x 9 = 63
7 x 10 = 70
```

</details>

<a id="lesson-14"></a>
<details>
<summary><b>📐 Lesson 14: <code>14_circumference_of_circle.sh</code></b> &nbsp;·&nbsp; input: r = 7</summary>

```text
Enter the radius of the circle:
7
Circumference of the circle = 43.96
```

</details>

<a id="lesson-15"></a>
<details>
<summary><b>🚦 Lesson 15: <code>15_fcfs.c</code></b> &nbsp;·&nbsp; input: burst 5, 3, 8</summary>

```text
Enter number of processes: 3
Enter burst time for each process:
P1: 5
P2: 3
P3: 8

Process Burst Time      Waiting Time    Turnaround Time
P1      5               0               5
P2      3               5               8
P3      8               8               16

Average Waiting Time    = 4.33
Average Turnaround Time = 9.67
```

</details>

<a id="lesson-16"></a>
<details>
<summary><b>🏁 Lesson 16: <code>16_priority_scheduling.c</code></b> &nbsp;·&nbsp; input: 4 processes</summary>

```text
Enter number of processes: 4
Enter burst time and priority for each process:
P1: 10 3
P2: 1 1
P3: 2 4
P4: 5 2

Process Priority        Burst Time      Waiting Time    Turnaround Time
P2      1               1               0               1
P4      2               5               1               6
P1      3               10              6               16
P3      4               2               16              18

Average Waiting Time    = 5.75
Average Turnaround Time = 10.25
```

</details>

<a id="lesson-17"></a>
<details>
<summary><b>📅 Lesson 17: <code>17_leap_year.sh</code></b> &nbsp;·&nbsp; input: 2024</summary>

```text
Enter a year:
2024
2024 is a Leap Year
```

</details>

<a id="lesson-18"></a>
<details>
<summary><b>🔁 Lesson 18: <code>18_menu_case.sh</code></b> &nbsp;·&nbsp; input: 6×7, 20−8, exit</summary>

```text

1. Multiply
2. Subtract
3. Exit
Enter your choice:
1
Enter two numbers:
6 7
6 x 7 = 42

1. Multiply
2. Subtract
3. Exit
Enter your choice:
2
Enter two numbers:
20 8
20 - 8 = 12

1. Multiply
2. Subtract
3. Exit
Enter your choice:
3
Exiting...
```

</details>

<a id="lesson-19"></a>
<details>
<summary><b>🔀 Lesson 19: <code>19_swap.sh</code></b> &nbsp;·&nbsp; input: 10, 20</summary>

```text
Enter the first number (a):
10
Enter the second number (b):
20
Before swapping: a = 10, b = 20
After swapping:  a = 20, b = 10
```

</details>

<a id="lesson-20"></a>
<details>
<summary><b>🎓 Lesson 20: <code>20_grade.sh</code></b> &nbsp;·&nbsp; input: 85 90 78 92</summary>

```text
Enter the marks of 4 subjects (out of 100):
85 90 78 92
Total      = 345 / 400
Percentage = 86%
Grade      = A
```

</details>

<a id="lesson-21"></a>
<details>
<summary><b>⚡ Lesson 21: <code>21_power.sh</code></b> &nbsp;·&nbsp; input: 2 ^ 10</summary>

```text
Enter the base:
2
Enter the exponent:
10
2 ^ 10 = 1024
```

</details>

<a id="lesson-22"></a>
<details>
<summary><b>🧩 Lesson 22: <code>22_factorial_function.sh</code></b> &nbsp;·&nbsp; input: 6</summary>

```text
Enter a number:
6
Factorial of 6 = 720
```

</details>

<a id="lesson-23"></a>
<details>
<summary><b>🪪 Lesson 23: <code>23_full_name.sh</code></b> &nbsp;·&nbsp; input: Mr, John Smith</summary>

```text
Enter the title (Mr/Ms/Dr):
Mr
Enter the name:
John Smith
Full Name: Mr. John Smith
```

</details>

<a id="lesson-24"></a>
<details>
<summary><b>🔺 Lesson 24: <code>24_pyramid.sh</code></b> &nbsp;·&nbsp; input: 5 rows</summary>

```text
Enter the number of rows:
5
    *
   ***
  *****
 *******
*********
```

</details>

<a id="lesson-25"></a>
<details>
<summary><b>🔢 Lesson 25: <code>25_number_pattern.sh</code></b> &nbsp;·&nbsp; input: n = 3</summary>

```text
Enter the number of terms:
3
1
1 2
1 2 3
```

</details>

<a id="lesson-26"></a>
<details>
<summary><b>📦 Lesson 26: <code>26_array_input.sh</code></b> &nbsp;·&nbsp; input: 5 elements</summary>

```text
Enter the number of elements:
5
Enter 5 elements:
10
20
30
40
50
The array elements are:
arr[0] = 10
arr[1] = 20
arr[2] = 30
arr[3] = 40
arr[4] = 50
```

</details>

<a id="lesson-27"></a>
<details>
<summary><b>🏆 Lesson 27: <code>27_largest_in_array.sh</code></b> &nbsp;·&nbsp; input: 12 45 7 89 23</summary>

```text
Enter the number of elements:
5
Enter 5 elements:
12
45
7
89
23
Array: 12 45 7 89 23
Largest element = 89
```

</details>

<a id="lesson-28"></a>
<details>
<summary><b>🔻 Lesson 28: <code>28_pascal_triangle.sh</code></b> &nbsp;·&nbsp; input: 5</summary>

```text
Enter the number of terms:
5
           1
         1   1
       1   2   1
     1   3   3   1
   1   4   6   4   1
```

</details>

<a id="lesson-29"></a>
<details>
<summary><b>🥇 Lesson 29: <code>29_largest_of_three.sh</code></b> &nbsp;·&nbsp; input: 15 42 27</summary>

```text
Enter three numbers:
15 42 27
Largest of 15, 42 and 27 = 42
```

</details>

<a id="lesson-30"></a>
<details>
<summary><b>🐧 Lesson 30: <code>30_linux_commands.sh</code></b> &nbsp;·&nbsp; input: no input</summary>

```text
== mkdir: create a directory ==
Created demo/

== cd: change directory ==
Now in: demo

== > (write) and >> (append) ==
Wrote 1 line with > and appended 3 with >>

== ls: list files ==
fruits.txt

== cat: show file contents ==
apple
banana
cherry
mango

== grep: search for lines containing 'an' ==
banana
mango

== sed: replace 'apple' with 'grape' ==
grape
banana
cherry
mango

== cal: calendar for July 2026 ==
     July 2026
Su Mo Tu We Th Fr Sa
          1  2  3  4
 5  6  7  8  9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30 31


== xclock / oclock: graphical clocks (need X11) ==
xclock: not available here (install x11-apps and run inside X11)
oclock: not available here (install x11-apps and run inside X11)
```

</details>

> [!NOTE]
> `xclock` and `oclock` (lesson 30) open graphical clocks, so they need X11. On Linux install them with `sudo apt install x11-apps`; the script skips them when they are missing.

---

## 🛠️ Troubleshooting

| 😵 Problem | ✅ Fix |
|:--|:--|
| `permission denied: ./script.sh` | Run `chmod +x script.sh` once |
| `bc: command not found` (lessons 2, 9, 14) | Install it: `sudo apt install bc` on Linux (macOS already has it) |
| `gcc: command not found` (lessons 15, 16) | Linux: `sudo apt install gcc` &nbsp;•&nbsp; macOS: `xcode-select --install` |
| `xclock: not available here` (lesson 30) | Install `x11-apps` and run inside an X11 session |
| Want to feed input without typing | Pipe it in: `printf '7\n' \| ./07_prime.sh` |

---

<div align="center">

**Made with 🐚 and ☕ by [vxwshxl](https://github.com/vxwshxl)**

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:4EAA25,50:1f6f3f,100:0d1117&height=110&section=footer" width="100%" alt="footer"/>

</div>
