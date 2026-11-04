# 🎓 OS Lab Viva Notes

Everything you need for the viva, in one place: the basics first, then every program explained line by line, then quick questions and answers.

> [!TIP]
> **How to study this file**
> 1. Read **Part A** (shell basics) once. Every program uses the same 10 to 12 building blocks.
> 2. Read **Part B** (Linux commands). This builds on program 30.
> 3. Read **Part C** (CPU scheduling) before you look at programs 15 and 16.
> 4. In **Part D**, for each program: read the *idea*, follow the *dry run* with a pen, then cover the answers and try the *viva questions*.
> 5. On the day of the viva, use **Part E** (rapid fire) and **Part F** (cheat sheet).

---

## 📑 Contents

- [Part A: Shell scripting basics](#part-a-shell-scripting-basics)
- [Part B: Linux commands (more than program 30)](#part-b-linux-commands-more-than-program-30)
- [Part C: CPU scheduling theory (for programs 15 and 16)](#part-c-cpu-scheduling-theory-for-programs-15-and-16)
- [Part D: Every program explained](#part-d-every-program-explained)
- [Part E: Rapid-fire viva questions](#part-e-rapid-fire-viva-questions)
- [Part F: One-page cheat sheet](#part-f-one-page-cheat-sheet)

---

# Part A: Shell scripting basics

## A1. The big picture

```
   You  ──type──▶  SHELL  ──asks──▶  KERNEL  ──controls──▶  HARDWARE
                  (bash)            (core of OS)            (CPU, RAM, disk)
```

| Term | Meaning (say this in the viva) |
|:--|:--|
| **Operating System** | Software that manages the hardware and gives programs services like files, memory, and CPU time. Examples: Linux, Windows, macOS. |
| **Kernel** | The core of the OS. It talks directly to the hardware and manages processes, memory, files, and devices. |
| **Shell** | A program that reads your commands and asks the kernel to run them. It is the *interface* between the user and the kernel. |
| **Bash** | *Bourne Again SHell*, the most common shell on Linux. Others: `sh`, `zsh` (default on macOS), `ksh`, `csh`. |
| **Shell script** | A text file containing shell commands that run one after another. It saves typing the same commands again and again. |
| **Terminal** | The window where you type. The shell runs *inside* the terminal. |

## A2. The shebang line `#!/bin/bash`

- `#!` is called the **shebang** (or hashbang).
- `#!/bin/bash` tells the system: *"run this file using the program `/bin/bash`."*
- It **must be the very first line** of the file (no blank line or comment before it). If it is not first, the system treats it as a normal comment.

> [!WARNING]
> In our files the first line is the aim comment (`# 1. Write a shell script ...`) and `#!/bin/bash` is on line 3. So technically it acts only as a comment.
> The scripts still work when started from bash, but the safest way to run them is **`bash 01_add.sh`**.
> If the examiner asks, explain the rule above. That shows you understand it.

## A3. Running a script

```bash
chmod +x 01_add.sh     # give execute permission (one time)
./01_add.sh            # run it (./ means "in the current folder")

bash 01_add.sh         # OR run it with bash directly (no chmod needed)
```

**Why `./`?** The shell looks for commands only in folders listed in the `PATH` variable. The current folder is not in `PATH`, so you must write `./` to point at it.

## A4. Comments

```bash
# Anything after a hash is a comment, and the shell ignores it
```

## A5. Variables

```bash
a=10          # NO spaces around =
name="Vee"    # use quotes for text that has spaces
echo $a       # $ is used to READ the value
echo "$name"
```

| Rule | Example |
|:--|:--|
| No spaces around `=` | `a=10` ✅ &nbsp; `a = 10` ❌ (the shell thinks `a` is a command) |
| Use `$` to read a value | `echo $a` |
| No data types | Everything is stored as text, and arithmetic treats it as a number when needed |
| Names are case sensitive | `sum` and `Sum` are different variables |

## A6. Input and output

```bash
echo "Enter a number:"   # print a line (adds a newline at the end)
echo -n "$a "            # -n = do NOT add a newline (used for printing on one line)
echo                     # print an empty line (moves to the next line)

read n                   # read one line from the keyboard into n
read a b                 # read two values typed on ONE line (split by spaces)
read m1 m2 m3 m4         # read four values on one line

printf "%4d" $c          # formatted print, like C (used in Pascal's triangle)
```

## A7. Arithmetic: bash works with integers only

| Syntax | Use | Example |
|:--|:--|:--|
| `$(( ... ))` | **Calculate** and give back the result | `sum=$((a + b))` |
| `(( ... ))` | **Test** a condition (true/false) in `if` or `while` | `if (( n % 2 == 0 ))` |
| `bc` | **Decimal** (floating point) maths | `echo "scale=2; 22/7" \| bc` gives `3.14` |

Operators: `+  -  *  /  %` (remainder)  `**` (power)  `==  !=  <  >  <=  >=`  `&&` (AND)  `||` (OR)  `!` (NOT)

> [!IMPORTANT]
> `/` in bash is **integer division**: `$((7 / 2))` gives `3`, not `3.5`. That is why programs 2, 9 and 14 use `bc`.

### What is `bc`?
- `bc` = **basic calculator**, a command-line calculator that can handle decimals.
- `scale=2` means *keep 2 digits after the decimal point*.
- `echo "..." | bc` sends the expression to `bc` through a **pipe** (`|`).
- `$( ... )` captures the result into a variable. This is called **command substitution**.

```bash
si=$(echo "scale=2; $p * $r * $t / 100" | bc)
#    └─────── send expression ───────┘ └ calc ┘
#  └──────────── store the answer in si ──────────┘
```

## A8. Decisions: `if`

```bash
if (( condition ))
then
    commands
elif (( other condition ))
then
    commands
else
    commands
fi            # "if" written backwards closes the block
```

There are two styles of test:

| Style | Used for | Example |
|:--|:--|:--|
| `(( ))` | Numbers (C-like, easy) | `(( a > b ))` |
| `[ ]` or `test` | Strings, files, older style | `[ $a -gt $b ]`, `[ -n "$DISPLAY" ]` |

Old-style number operators for `[ ]`: `-eq` (=), `-ne` (≠), `-gt` (>), `-lt` (<), `-ge` (≥), `-le` (≤).
String tests: `-z` (empty), `-n` (not empty), `=` (equal). File tests: `-f` (file exists), `-d` (directory exists).

## A9. Loops

```bash
# while: repeat as long as the condition is true
while (( i <= n ))
do
    ...
done

# for (C style): start; condition; step
for (( i = 1; i <= 10; i++ ))
do
    ...
done

# for (list style)
for clock in xclock oclock
do
    echo $clock
done

# infinite loop
while true
do
    ...
done
```

- `break` leaves the loop. `continue` skips to the next round.
- `until` is the opposite of `while`: it runs *until* the condition becomes true.

## A10. `case` (menu style choice, like `switch` in C)

```bash
case $choice in
    1) echo "one" ;;
    2) echo "two" ;;
    *) echo "anything else" ;;    # * = default
esac                              # "case" backwards
```

`;;` ends each option, like `break` in C.

## A11. Functions

```bash
factorial()            # define it first
{
    local n=$1         # $1 = first argument given to the function
    ...
    echo $fact         # "return" the answer by printing it
}

result=$(factorial 5)  # call it and capture what it printed
```

- `$1, $2, ...` are **positional parameters** (the arguments). `$#` is the number of arguments. `$@` is all of them.
- `local` keeps the variable inside the function only.
- `return` gives back only an **exit status** (0 to 255), not a real value. That is why we use `echo` and `$( )`.

## A12. Arrays

```bash
arr[0]=10             # set one element
read arr[i]           # read into element i
echo ${arr[i]}        # get element i (braces are required)
echo ${arr[*]}        # all elements
echo ${#arr[@]}       # number of elements
```

The index starts at **0**.

## A13. Exit status

- Every command finishes with a number: **0 = success**, anything else = error.
- `exit 0` ends the script successfully. `exit 1` ends it with an error (used in program 11 for bad input).
- `$?` holds the exit status of the last command.

## A14. Special variables (often asked)

| Variable | Meaning |
|:--|:--|
| `$0` | Name of the script |
| `$1 ... $9` | Arguments |
| `$#` | Number of arguments |
| `$@` / `$*` | All arguments |
| `$?` | Exit status of the last command |
| `$$` | Process ID (PID) of the current shell |
| `$PWD` | Current folder |
| `$HOME` | Your home folder |
| `$USER` | Your username |
| `$PATH` | Folders where the shell looks for commands |

---

# Part B: Linux commands (more than program 30)

## B1. The Linux file system

```
/                     ← root (the top of everything)
├── bin               ← basic commands (ls, cp, bash ...)
├── etc               ← configuration files
├── home
│   └── vee           ← your home folder (~)
├── tmp               ← temporary files
├── usr               ← installed programs
└── dev               ← devices (dev/null is the "black hole")
```

| Symbol | Meaning |
|:--|:--|
| `/` | Root folder (at the start of a path) or a separator between folders |
| `~` | Your home folder |
| `.` | The current folder |
| `..` | The parent folder (one level up) |
| **Absolute path** | Starts from `/`, for example `/home/vee/OS/01_add.sh` |
| **Relative path** | Starts from where you are now, for example `OS/01_add.sh` |

## B2. Moving around

| Command | What it does | Example |
|:--|:--|:--|
| `pwd` | **P**rint **w**orking **d**irectory (where am I?) | `pwd` → `/home/vee` |
| `ls` | List files | `ls` |
| `ls -l` | Long list (permissions, size, date) | `ls -l` |
| `ls -a` | Show hidden files too (names starting with `.`) | `ls -a` |
| `ls -lh` | Long list with human-readable sizes (K, M) | `ls -lh` |
| `cd folder` | Go into a folder | `cd demo` |
| `cd ..` | Go up one level | |
| `cd` or `cd ~` | Go to your home folder | |
| `cd -` | Go back to the previous folder | |

## B3. Files and folders

| Command | What it does | Example |
|:--|:--|:--|
| `mkdir name` | Make a directory | `mkdir demo` |
| `mkdir -p a/b/c` | Make nested folders in one go | |
| `rmdir name` | Remove an **empty** directory | |
| `touch file` | Create an empty file (or update its time) | `touch notes.txt` |
| `cp src dest` | Copy | `cp a.txt b.txt` |
| `cp -r` | Copy a folder with everything inside | |
| `mv src dest` | Move **or rename** | `mv old.txt new.txt` |
| `rm file` | Remove a file (no recycle bin!) | |
| `rm -r folder` | Remove a folder and its contents | |
| `rm -rf folder` | Same, but force it (no questions). Dangerous. | |
| `ln -s target link` | Create a shortcut (symbolic link) | |

## B4. Looking at file contents

| Command | What it does |
|:--|:--|
| `cat file` | Show the whole file (con**cat**enate). `cat a b > c` joins files. |
| `more file` / `less file` | Show page by page (`q` to quit) |
| `head file` | First 10 lines (`head -n 3 file` for the first 3) |
| `tail file` | Last 10 lines (`tail -f log` keeps watching for new lines) |
| `wc file` | Count lines, words, characters (`wc -l` for lines only) |

## B5. Redirection and pipes (very important)

| Symbol | Meaning | Example |
|:--|:--|:--|
| `>` | Send output to a file and **overwrite** it | `echo "apple" > fruits.txt` |
| `>>` | Send output to a file and **append** to the end | `echo "banana" >> fruits.txt` |
| `<` | Take input from a file | `./01_add.sh < input.txt` |
| `2>` | Send **errors** to a file | `ls nofile 2> err.txt` |
| `2>&1` | Send errors to the same place as normal output | |
| `\|` | **Pipe**: the output of one command becomes the input of the next | `cat fruits.txt \| grep an` |

**The three standard streams:**

| No. | Name | Default |
|:--:|:--|:--|
| 0 | **stdin** (standard input) | keyboard |
| 1 | **stdout** (standard output) | screen |
| 2 | **stderr** (standard error) | screen |

**`/dev/null`** is a special file that throws away everything written to it, like a black hole.
`command > /dev/null 2>&1` means: *"run it, but hide all output and errors."* Program 30 uses this.

## B6. `grep`: search inside files

**grep** = **g**lobal **r**egular **e**xpression **p**rint. It prints the lines that match a pattern.

```bash
grep "an" fruits.txt        # lines containing "an"   → banana, mango
grep -i "APPLE" fruits.txt  # -i  ignore upper/lower case
grep -n "an" fruits.txt     # -n  show line numbers   → 2:banana  4:mango
grep -v "an" fruits.txt     # -v  lines that do NOT match → apple, cherry
grep -c "an" fruits.txt     # -c  count matching lines → 2
grep -r "echo" .            # -r  search all files in this folder and below
grep "^a" fruits.txt        # ^   lines STARTING with a
grep "o$" fruits.txt        # $   lines ENDING with o
```

## B7. `sed`: stream editor (find and replace)

```bash
sed 's/apple/grape/' fruits.txt     # replace the first "apple" on each line
sed 's/a/A/g' fruits.txt            # g = replace ALL matches on each line
sed -i 's/apple/grape/' fruits.txt  # -i = change the file itself
sed -n '2p' fruits.txt              # print only line 2
sed '3d' fruits.txt                 # delete line 3 (in the output)
```

`s/old/new/` means **s**ubstitute old with new.

> [!NOTE]
> Without `-i`, `sed` only *prints* the changed text. The file stays the same. In program 30 `fruits.txt` still contains `apple` afterwards.

## B8. Permissions (`chmod`)

`ls -l` shows something like:

```
-rwxr-xr--  1  vee  staff  220  Nov 4 10:00  01_add.sh
│└┬┘└┬┘└┬┘
│ │  │  └── others: r-- (read only)
│ │  └───── group:  r-x (read, execute)
│ └──────── owner:  rwx (read, write, execute)
└────────── type: - = file, d = directory, l = link
```

| Letter | Number | Meaning |
|:--:|:--:|:--|
| r | 4 | read |
| w | 2 | write |
| x | 1 | execute |

Add the numbers for each group: `rwx` = 4+2+1 = **7**, `r-x` = 4+1 = **5**, `r--` = **4**.

```bash
chmod +x file      # add execute for everyone
chmod 755 file     # rwx r-x r-x
chmod 644 file     # rw- r-- r--
chmod u+w file     # u=user(owner), g=group, o=others, a=all
chown user file    # change the owner
```

## B9. Processes

A **process** is a program that is running.

| Command | What it does |
|:--|:--|
| `ps` | List your processes |
| `ps -ef` / `ps aux` | List all processes |
| `top` / `htop` | Live view of processes and CPU usage |
| `kill PID` | Ask a process to stop |
| `kill -9 PID` | Force stop |
| `command &` | Run in the background |
| `jobs`, `fg`, `bg` | Manage background jobs |
| <kbd>Ctrl</kbd>+<kbd>C</kbd> | Stop the running program |
| <kbd>Ctrl</kbd>+<kbd>Z</kbd> | Pause it (resume with `fg`) |

## B10. Useful information commands

| Command | Output |
|:--|:--|
| `cal` | Calendar of this month (`cal 7 2026` = July 2026, `cal 2026` = whole year) |
| `date` | Current date and time |
| `whoami` | Your username |
| `who` | Who is logged in |
| `uname -a` | System and kernel information |
| `echo $SHELL` | Your current shell |
| `man ls` | Manual (help page) for `ls` (`q` to quit) |
| `history` | Commands you typed before |
| `clear` | Clear the screen |
| `df -h` | Free disk space |
| `du -sh folder` | Size of a folder |
| `find . -name "*.sh"` | Find files by name |
| `sort`, `uniq`, `cut` | Sort lines, remove duplicate lines, cut columns |
| `tar -cvf a.tar folder` | Make an archive (`-xvf` to extract) |

## B11. `xclock` and `oclock`

- These are small **graphical** clock programs from the `x11-apps` package.
- `xclock` shows an analog clock in a square window. `oclock` shows a round clock.
- They need the **X Window System (X11)**, the system that draws windows on Linux. The `DISPLAY` variable tells programs which screen to draw on.
- Install them with `sudo apt install x11-apps`.

---

# Part C: CPU scheduling theory (for programs 15 and 16)

## C1. Basic words

| Term | Meaning |
|:--|:--|
| **Program** | A file on disk (passive). |
| **Process** | A program that is running (active). It has its own memory, registers and state. |
| **PCB** (Process Control Block) | The record the OS keeps for each process: PID, state, registers, priority, memory information. |
| **CPU scheduling** | Deciding **which ready process gets the CPU next**. |
| **Scheduler** | The part of the OS that makes that decision. |
| **Dispatcher** | The part that actually hands the CPU to the chosen process. |
| **Context switch** | Saving the state of one process and loading another. |

### Process states

```
  New ──▶ Ready ──▶ Running ──▶ Terminated
            ▲  ◀──────┘ │
            │ (time up)  │ (waits for I/O)
            └── Waiting ◀┘
```

## C2. Times used in scheduling (learn the formulas)

| Short | Name | Meaning |
|:--|:--|:--|
| **AT** | Arrival Time | When the process enters the ready queue |
| **BT** | Burst Time | How much CPU time it needs |
| **CT** | Completion Time | When it finishes |
| **TAT** | Turnaround Time | Total time from arrival to finish |
| **WT** | Waiting Time | Time spent waiting in the ready queue |
| **RT** | Response Time | Time from arrival until it first gets the CPU |

```
TAT = CT − AT
WT  = TAT − BT
```

> [!IMPORTANT]
> In our programs **all processes arrive at time 0** (AT = 0). So TAT = CT, and
> **WT of a process = the sum of the burst times of all processes that ran before it.**
> That is exactly the line `wt[i] = wt[i-1] + bt[i-1]`.

## C3. Scheduling goals

- **Maximise:** CPU utilisation, throughput (processes finished per unit time).
- **Minimise:** waiting time, turnaround time, response time.

## C4. Preemptive vs non-preemptive

| Non-preemptive | Preemptive |
|:--|:--|
| Once a process gets the CPU, it keeps it until it finishes (or waits for I/O). | The OS can **take the CPU away** in the middle (for example, a higher-priority process arrives or the time slice ends). |
| Simple, low overhead | More responsive, but more context switches |
| FCFS, non-preemptive SJF, non-preemptive Priority | Round Robin, SRTF, preemptive Priority |

Both our C programs are **non-preemptive**.

## C5. Common algorithms (know at least one line each)

| Algorithm | Rule | Good | Bad |
|:--|:--|:--|:--|
| **FCFS** (First Come First Serve) | Run in order of arrival (a queue) | Simplest, fair in order | **Convoy effect**: short jobs wait behind a long one |
| **SJF** (Shortest Job First) | Smallest burst time first | **Lowest average waiting time** (optimal) | Need to know burst time in advance; long jobs can starve |
| **SRTF** | Preemptive SJF: shortest *remaining* time first | Even lower waiting time | Many context switches |
| **Priority** | Highest priority first | Important jobs finish first | **Starvation** of low-priority jobs (fix: **aging**) |
| **Round Robin (RR)** | Each process gets a fixed **time quantum** in turn | Fair, good for time-sharing | Too small a quantum means too many context switches |

- **Convoy effect:** many small processes stuck waiting behind one big process (FCFS).
- **Starvation:** a process waits forever because others always go first.
- **Aging:** slowly increasing the priority of a process the longer it waits, so it eventually runs.

## C6. Gantt chart

A Gantt chart is a timeline that shows which process runs when. Draw it in the viva when you explain the output.

```
FCFS example (BT: P1=5, P2=3, P3=8)

| P1    | P2  | P3        |
0       5     8           16
```

---

# Part D: Every program explained

Each program has:
**🎯 Aim** · **💡 Idea** · **🔑 Key lines** · **✍️ Dry run** · **❓ Viva questions**

---

## 1. Add two numbers — [`01_add.sh`](01_add.sh)

**🎯 Aim:** Read two numbers and print their sum.

**💡 Idea:** `read` the two values, then add them with `$(( ))`.

**🔑 Key lines**
```bash
read a
read b
sum=$((a + b))
echo "Sum of $a and $b = $sum"
```

**✍️ Dry run:** a=12, b=8 → sum = 20

**❓ Viva questions**
- *What does `read` do?* It waits for keyboard input and stores it in a variable.
- *What does `$(( ))` do?* It does integer arithmetic and gives back the result.
- *What if I write `sum=$a+$b`?* You get the text `12+8`, not 20, because the shell treats it as a string.
- *Can it add 2.5 and 3.1?* No, `$(( ))` is integer only. Use `echo "2.5 + 3.1" | bc`.
- *Other ways to add?* `expr $a + $b` (spaces are required), `let sum=a+b`, or `echo "$a + $b" | bc`.

---

## 2. Simple interest — [`02_simple_interest.sh`](02_simple_interest.sh)

**🎯 Aim:** Find simple interest and total amount.

**💡 Idea:** Formula **SI = P × R × T / 100**, **Total = P + SI**. Division can give decimals, so use `bc`.

**🔑 Key lines**
```bash
si=$(echo "scale=2; $p * $r * $t / 100" | bc)
total=$(echo "scale=2; $p + $si" | bc)
```

**✍️ Dry run:** P=5000, R=8, T=3 → SI = 5000×8×3/100 = **1200.00**, Total = **6200.00**

**❓ Viva questions**
- *Why `bc`?* Bash arithmetic is integer only. `bc` handles decimals.
- *What is `scale=2`?* It keeps 2 digits after the decimal point.
- *What is `|`?* A pipe. It sends the output of `echo` as input to `bc`.
- *What is `$( )`?* Command substitution. It runs a command and stores its output.
- *Compound interest?* `A = P(1 + R/100)^T`, and `CI = A − P`. In bc: `echo "scale=2; $p*(1+$r/100)^$t" | bc`.

---

## 3. Odd or even — [`03_odd_even.sh`](03_odd_even.sh)

**🎯 Aim:** Check whether a number is odd or even.

**💡 Idea:** If the remainder after dividing by 2 is 0, the number is even. Otherwise it is odd.

**🔑 Key lines**
```bash
if (( n % 2 == 0 ))
then
    echo "$n is an Even number"
else
    echo "$n is an Odd number"
fi
```

**✍️ Dry run:** 7 % 2 = 1 → **Odd**

**❓ Viva questions**
- *What is `%`?* The modulus operator. It gives the remainder.
- *What closes an `if` block?* `fi`.
- *Same test in old style?* `if [ $((n % 2)) -eq 0 ]`.
- *Is 0 even?* Yes, 0 % 2 = 0.

---

## 4. Factorial — [`04_factorial.sh`](04_factorial.sh)

**🎯 Aim:** Print n! = 1 × 2 × 3 × … × n.

**💡 Idea:** Start with `fact=1` and multiply by i = 1, 2, …, n using a `while` loop.

**🔑 Key lines**
```bash
fact=1
i=1
while (( i <= n ))
do
    fact=$((fact * i))
    i=$((i + 1))
done
```

**✍️ Dry run (n = 5)**

| i | fact |
|:--:|:--:|
| 1 | 1 |
| 2 | 2 |
| 3 | 6 |
| 4 | 24 |
| 5 | **120** |

**❓ Viva questions**
- *Why start `fact` at 1, not 0?* Anything multiplied by 0 is 0.
- *What is 0!?* 1. The loop does not run, so `fact` stays 1. ✅
- *Largest factorial bash can hold?* 20! (bash uses 64-bit integers). 21! overflows and gives a wrong answer.
- *Difference from program 22?* Program 22 does the same thing inside a **function** and uses a `for` loop.

---

## 5. Reverse a number — [`05_reverse.sh`](05_reverse.sh)

**🎯 Aim:** Print the digits in reverse order (12345 → 54321).

**💡 Idea:** Repeat three steps:
1. `% 10` takes the **last digit**.
2. `rev * 10 + digit` puts the digit at the end of `rev`.
3. `/ 10` removes the last digit from `num`.

**🔑 Key lines**
```bash
while (( num > 0 ))
do
    digit=$((num % 10))
    rev=$((rev * 10 + digit))
    num=$((num / 10))
done
```

**✍️ Dry run (n = 123)**

| num | digit | rev |
|:--:|:--:|:--:|
| 123 | 3 | 3 |
| 12 | 2 | 32 |
| 1 | 1 | **321** |
| 0 | stop | |

**❓ Viva questions**
- *Why copy n into num?* To keep the original n for printing. The loop destroys num.
- *Reverse of 120?* 21, because the leading zero is lost.
- *How to check a palindrome?* Reverse it and check `if (( rev == n ))`. Example: 121.
- *Shortcut?* `echo 12345 | rev` (the `rev` command reverses text).

---

## 6. Sum of digits — [`06_sum_of_digits.sh`](06_sum_of_digits.sh)

**🎯 Aim:** Add all the digits of a number (4567 → 4+5+6+7 = 22).

**💡 Idea:** The same loop as program 5, but **add** each digit instead of building the reverse.

**🔑 Key line:** `sum=$((sum + num % 10))` and then `num=$((num / 10))`

**✍️ Dry run (4567):** 7 → 7, 6 → 13, 5 → 18, 4 → **22**

**❓ Viva questions**
- *How is this different from program 11?* Program 11 works only for 3 digits and takes each digit out with fixed formulas. This one uses a loop, so it works for **any** number of digits.
- *How to count the digits?* Add 1 to a counter each time round the loop instead of adding the digit.

---

## 7. Prime number — [`07_prime.sh`](07_prime.sh)

**🎯 Aim:** Check whether n is prime (divisible only by 1 and itself).

**💡 Idea:**
- Numbers below 2 are **not prime**.
- Try dividing by i = 2, 3, 4, … while **i × i ≤ n**. If any i divides n exactly, n is not prime.
- `prime=1` is a **flag**. It changes to 0 if a divisor is found.

**🔑 Key lines**
```bash
while (( i * i <= n ))
do
    if (( n % i == 0 ))
    then
        prime=0
        break
    fi
    i=$((i + 1))
done
```

**✍️ Dry run (n = 29):** i = 2, 3, 4, 5 → none divide 29. At i = 6, 36 > 29, so the loop stops → **Prime**

**❓ Viva questions**
- *Why only check up to √n?* If n = a × b, one of a or b must be ≤ √n. So if no divisor exists up to √n, none exists at all. This makes the program much faster.
- *What does `break` do?* It leaves the loop early. One divisor is enough to say "not prime".
- *Is 1 prime?* No. Is 2 prime? Yes, the only even prime.
- *What is a flag variable?* A variable used as a yes/no marker (here, `prime`).

---

## 8. Fibonacci series — [`08_fibonacci.sh`](08_fibonacci.sh)

**🎯 Aim:** Print the first n Fibonacci numbers: 0 1 1 2 3 5 8 …

**💡 Idea:** Each term is the sum of the previous two. Keep two variables `a` and `b`, print `a`, then shift both forward.

**🔑 Key lines**
```bash
a=0; b=1
for (( i = 1; i <= n; i++ ))
do
    echo -n "$a "
    c=$((a + b))
    a=$b
    b=$c
done
```

**✍️ Dry run (n = 5)**

| i | print a | c | new a | new b |
|:--:|:--:|:--:|:--:|:--:|
| 1 | 0 | 1 | 1 | 1 |
| 2 | 1 | 2 | 1 | 2 |
| 3 | 1 | 3 | 2 | 3 |
| 4 | 2 | 5 | 3 | 5 |
| 5 | 3 | 8 | 5 | 8 |

Output: `0 1 1 2 3`

**❓ Viva questions**
- *Why `echo -n`?* To print all terms on one line (no newline after each).
- *Why the empty `echo` at the end?* To move to a new line after the series.
- *What is the formula?* F(n) = F(n−1) + F(n−2), with F(0) = 0 and F(1) = 1.

---

## 9. Area of a circle — [`09_area_of_circle.sh`](09_area_of_circle.sh)

**🎯 Aim:** Area = π × r²

**🔑 Key line:** `area=$(echo "scale=2; 3.14 * $r * $r" | bc)`

**✍️ Dry run:** r = 7 → 3.14 × 49 = **153.86**

**❓ Viva questions**
- *Why `bc`?* π = 3.14 is a decimal, and bash cannot do decimal maths.
- *A more accurate π?* `bc -l` gives maths functions. π = `4*a(1)` (a = arctan).

---

## 10. GCD (Euclid's algorithm) — [`10_gcd.sh`](10_gcd.sh)

**🎯 Aim:** Find the greatest common divisor (the largest number that divides both).

**💡 Idea (Euclid):** GCD(x, y) = GCD(y, x % y). Repeat until y becomes 0. Then x is the answer.

**🔑 Key lines**
```bash
while (( y != 0 ))
do
    r=$((x % y))
    x=$y
    y=$r
done
```

**✍️ Dry run (48, 18)**

| x | y | r = x % y |
|:--:|:--:|:--:|
| 48 | 18 | 12 |
| 18 | 12 | 6 |
| 12 | 6 | 0 |
| **6** | 0 | stop |

**❓ Viva questions**
- *Other name for GCD?* HCF (Highest Common Factor).
- *How to find the LCM?* LCM = (a × b) / GCD → 48 × 18 / 6 = **144**.
- *Why is Euclid's method good?* It is very fast, much faster than trying every number.

---

## 11. Sum of digits of a 3-digit number — [`11_sum_of_3_digits.sh`](11_sum_of_3_digits.sh)

**🎯 Aim:** For a 3-digit number, add its digits.

**💡 Idea:** Take out each digit directly, with no loop:

| Digit | Formula | For 456 |
|:--|:--|:--:|
| Hundreds | `n / 100` | 4 |
| Tens | `n / 10 % 10` | 45 % 10 = 5 |
| Units | `n % 10` | 6 |

**🔑 Key lines**
```bash
if (( n < 100 || n > 999 ))
then
    echo "Please enter a 3 digit number"
    exit 1
fi
```
This checks the input first (**input validation**). `exit 1` stops the script with an error status.

**❓ Viva questions**
- *What does `||` mean?* OR: true if either side is true.
- *Why `exit 1` and not `exit 0`?* 1 means "ended with an error". 0 means success.

---

## 12. Sum of odd and even numbers from 1 to 50 — [`12_sum_odd_even.sh`](12_sum_odd_even.sh)

**🎯 Aim:** Add all odd numbers and all even numbers from 1 to 50 separately.

**💡 Idea:** Loop from 1 to 50. If i % 2 == 0, add it to `even`, otherwise add it to `odd`.

**Output:** Odd = **625**, Even = **650**

**❓ Viva questions**
- *Check with a formula:* the sum of the first k odd numbers is k² = 25² = 625. The sum of the first k even numbers is k(k+1) = 25 × 26 = 650. ✅
- *Does it take input?* No. The range 1 to 50 is fixed in the code.
- *Faster loop for only even numbers?* `for (( i = 2; i <= 50; i += 2 ))`.

---

## 13. Multiplication table — [`13_multiplication_table.sh`](13_multiplication_table.sh)

**🎯 Aim:** Print n × 1 up to n × 10.

**🔑 Key line**
```bash
for (( i = 1; i <= 10; i++ ))
do
    echo "$n x $i = $((n * i))"
done
```

**❓ Viva questions**
- *Why `x` and not `*` in the echo?* `*` without quotes can be expanded by the shell into file names (globbing). Using `x` avoids confusion.
- *Can `$(( ))` be used inside echo?* Yes, it is calculated before printing.

---

## 14. Circumference of a circle — [`14_circumference_of_circle.sh`](14_circumference_of_circle.sh)

**🎯 Aim:** Circumference = 2πr

**🔑 Key line:** `circumference=$(echo "scale=2; 2 * 3.14 * $r" | bc)`

**✍️ Dry run:** r = 7 → 2 × 3.14 × 7 = **43.96**

**❓ Viva question:** *Difference from program 9?* Area = πr² (space inside). Circumference = 2πr (length of the boundary).

---

## 15. FCFS CPU scheduling (C) — [`15_fcfs.c`](15_fcfs.c)

**🎯 Aim:** Implement First Come First Serve scheduling and find the average waiting time and turnaround time.

**💡 Idea:** Processes run in the order they were entered. All arrive at time 0. A process waits for everyone before it.

**🔑 Key lines**
```c
wt[0] = 0;                          // first process does not wait
for (i = 1; i < n; i++)
    wt[i] = wt[i - 1] + bt[i - 1];  // wait = previous wait + previous burst

for (i = 0; i < n; i++)
    tat[i] = wt[i] + bt[i];         // turnaround = waiting + burst
```

**✍️ Dry run (BT: 5, 3, 8)**

```
Gantt:  | P1    | P2  | P3        |
        0       5     8           16
```

| Process | BT | WT | TAT |
|:--:|:--:|:--:|:--:|
| P1 | 5 | 0 | 5 |
| P2 | 3 | 5 | 8 |
| P3 | 8 | 8 | 16 |
| | | **avg 13/3 = 4.33** | **avg 29/3 = 9.67** |

**❓ Viva questions**
- *Is FCFS preemptive?* No, it is **non-preemptive**.
- *What is the convoy effect?* Short processes stuck behind a long one. If P3 (8) came first, P1 and P2 would both wait 8+ units.
- *Is it better if the shortest job goes first?* Yes. That is **SJF**. Order P2, P1, P3 gives WT = 0, 3, 8 → average **3.67** (better than 4.33).
- *Why are `total_wt` and `total_tat` `float`?* The average can have decimals. `%.2f` prints 2 decimal places.
- *Why `bt[20]`?* A fixed array size. It supports at most 20 processes.
- *Why `&` in `scanf("%d", &n)`?* `scanf` needs the **address** of the variable so it can store the value there.
- *How to compile and run?* `gcc 15_fcfs.c -o 15_fcfs` and then `./15_fcfs`.
- *What if processes had different arrival times?* Then WT = start time − AT. A process may also find the CPU idle until it arrives. Our program assumes AT = 0 for all.

---

## 16. Priority scheduling (C, non-preemptive) — [`16_priority_scheduling.c`](16_priority_scheduling.c)

**🎯 Aim:** Run processes in order of priority (**a lower number means a higher priority**) and find the average WT and TAT.

**💡 Idea:**
1. Read the burst time and priority for each process. Remember the process number in `p[]`.
2. **Sort** by priority, swapping `pr`, `bt` and `p` together so they stay matched.
3. Then calculate exactly like FCFS on the sorted order.

**🔑 Key lines**
```c
if (pr[j] < pr[i])        // j has a higher priority → move it forward
{
    temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
    temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
    temp = p[i];  p[i] = p[j];   p[j] = temp;
}
```

**✍️ Dry run**

| Input | BT | Priority |
|:--:|:--:|:--:|
| P1 | 10 | 3 |
| P2 | 1 | 1 |
| P3 | 2 | 4 |
| P4 | 5 | 2 |

Sorted order: **P2 (1) → P4 (2) → P1 (3) → P3 (4)**

```
Gantt:  |P2| P4    | P1          | P3 |
        0  1       6             16   18
```

| Process | Priority | BT | WT | TAT |
|:--:|:--:|:--:|:--:|:--:|
| P2 | 1 | 1 | 0 | 1 |
| P4 | 2 | 5 | 1 | 6 |
| P1 | 3 | 10 | 6 | 16 |
| P3 | 4 | 2 | 16 | 18 |
| | | | **avg 23/4 = 5.75** | **avg 41/4 = 10.25** |

**❓ Viva questions**
- *Why swap `bt` and `p` together with `pr`?* Otherwise a process's burst time and name would get separated from its priority.
- *What is `p[]` for?* To remember the original process number (P1, P2, …) after sorting.
- *What is starvation here?* A low-priority process can wait forever if higher-priority ones keep arriving.
- *How to fix starvation?* **Aging**: gradually raise the priority of waiting processes.
- *Preemptive priority?* If a higher-priority process arrives, it interrupts the running one. Our program is non-preemptive.
- *What if two processes have the same priority?* Usually they are broken by FCFS order.
- *Which sort is used?* A simple selection-style sort: compare position i with every later j and swap if j has a higher priority.
- *How does it become SJF?* Sort by `bt` instead of `pr`. SJF is a special case of priority scheduling where priority = burst time.

---

## 17. Leap year — [`17_leap_year.sh`](17_leap_year.sh)

**🎯 Aim:** Check whether a year is a leap year.

**💡 Rule:** A leap year is **divisible by 4 but not by 100**, **or divisible by 400**.

**🔑 Key line**
```bash
if (( (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 ))
```

**✍️ Test values**

| Year | ÷4 | ÷100 | ÷400 | Leap? |
|:--:|:--:|:--:|:--:|:--:|
| 2024 | ✅ | ❌ | ❌ | ✅ |
| 1900 | ✅ | ✅ | ❌ | ❌ |
| 2000 | ✅ | ✅ | ✅ | ✅ |
| 2023 | ❌ | | | ❌ |

**❓ Viva question:** *Why is 1900 not a leap year?* It is divisible by 100 but not by 400.

---

## 18. Menu with infinite loop and `case` — [`18_menu_case.sh`](18_menu_case.sh)

**🎯 Aim:** Show a menu again and again: 1 = multiply, 2 = subtract, 3 = exit.

**💡 Idea:** `while true` repeats forever. `case` picks the action. Option 3 runs `exit 0`, which ends the script and therefore the loop.

**🔑 Key lines**
```bash
while true
do
    ...
    read choice
    case $choice in
        1) read a b; echo "$a x $b = $((a * b))" ;;
        2) read a b; echo "$a - $b = $((a - b))" ;;
        3) echo "Exiting..."; exit 0 ;;
        *) echo "Invalid choice" ;;
    esac
done
```

**❓ Viva questions**
- *What is an infinite loop?* A loop whose condition is always true (`while true` or `while :`).
- *How do you get out?* `exit` (ends the script) or `break` (ends only the loop). <kbd>Ctrl</kbd>+<kbd>C</kbd> also works.
- *What does `*)` do?* It is the default case and catches any other input.
- *What does `;;` do?* It ends that case option.
- *What closes `case`?* `esac`.

---

## 19. Swap without a third variable — [`19_swap.sh`](19_swap.sh)

**🎯 Aim:** Swap a and b without using a temporary variable.

**🔑 Key lines**
```bash
a=$((a + b))
b=$((a - b))
a=$((a - b))
```

**✍️ Dry run (a = 10, b = 20)**

| Step | a | b |
|:--|:--:|:--:|
| start | 10 | 20 |
| a = a + b | 30 | 20 |
| b = a − b | 30 | **10** |
| a = a − b | **20** | 10 |

**❓ Viva questions**
- *Another way?* XOR: `a=$((a ^ b)); b=$((a ^ b)); a=$((a ^ b))`. Or multiply and divide (fails if one value is 0).
- *Problem with the add method?* For very large numbers, `a + b` can overflow.
- *With a third variable?* `t=$a; a=$b; b=$t`.

---

## 20. Grade from marks — [`20_grade.sh`](20_grade.sh)

**🎯 Aim:** Read the marks of 4 subjects, find the total and percentage, and give a grade.

**💡 Idea:** Percentage = total / 4 (each subject is out of 100). Then an **if–elif ladder** picks the grade.

| Percentage | Grade |
|:--:|:--:|
| ≥ 90 | A+ |
| ≥ 80 | A |
| ≥ 70 | B |
| ≥ 60 | C |
| ≥ 50 | D |
| < 50 | F |

**✍️ Dry run:** 85 + 90 + 78 + 92 = 345 → 345 / 4 = 86 → **A**

**❓ Viva questions**
- *Why check from the highest grade down?* With 95, the test `>= 80` is also true. Checking `>= 90` first gives the correct grade.
- *345 / 4 = 86.25, so why does it print 86?* Bash integer division drops the decimal part.
- *What does `read m1 m2 m3 m4` do?* It reads 4 values typed on one line.

---

## 21. Power without built-in functions — [`21_power.sh`](21_power.sh)

**🎯 Aim:** Calculate base^exp using only a loop.

**💡 Idea:** Multiply `result` by `base`, `exp` times.

**🔑 Key lines**
```bash
result=1
for (( i = 1; i <= exp; i++ ))
do
    result=$((result * base))
done
```

**✍️ Dry run:** 2^5 → 2, 4, 8, 16, **32**

**❓ Viva questions**
- *What is the built-in way?* `$((2 ** 10))`. We avoid it because the question says "without predefined functions".
- *What about exp = 0?* The loop does not run, so result = 1. ✅ (Anything to the power 0 is 1.)
- *Negative exponent?* Not handled. It would need decimals (`bc`).

---

## 22. Factorial using a function — [`22_factorial_function.sh`](22_factorial_function.sh)

**🎯 Aim:** Write a shell **function** that finds the factorial.

**🔑 Key lines**
```bash
factorial()
{
    local n=$1
    local fact=1
    for (( i = 2; i <= n; i++ ))
    do
        fact=$((fact * i))
    done
    echo $fact
}

echo "Factorial of $n = $(factorial $n)"
```

**❓ Viva questions**
- *What is a function?* A named block of code you can call again and again. It avoids repeating code.
- *What is `$1`?* The first argument passed to the function.
- *What is `local`?* It keeps the variable inside the function, so it does not change a variable with the same name outside.
- *Why `echo` instead of `return`?* `return` gives only an exit status between 0 and 255. 6! = 720 is too big. So we print the answer and capture it with `$( )`.
- *Must a function be defined before it is called?* Yes, the shell reads the file from top to bottom.
- *Why does the loop start at 2?* Multiplying by 1 changes nothing.
- *Recursive version?*
  ```bash
  fact() { if (( $1 <= 1 )); then echo 1; else echo $(( $1 * $(fact $(( $1 - 1 ))) )); fi; }
  ```

---

## 23. Full name from title and name — [`23_full_name.sh`](23_full_name.sh)

**🎯 Aim:** Read a title (Mr/Ms/Dr) and a name, then print them together.

**🔑 Key line:** `full_name="$title. $name"`

**✍️ Dry run:** Mr + John Smith → **Mr. John Smith**

**❓ Viva questions**
- *How do you join strings in shell?* Write them next to each other: `"$a$b"` or `"$a $b"`. There is no `+` operator for strings.
- *Why do the quotes matter?* They keep the spaces as part of the string.
- *How does `read name` take "John Smith" with the space?* `read` with one variable stores the whole line in it.
- *Length of a string?* `${#full_name}`.

---

## 24. Star pyramid — [`24_pyramid.sh`](24_pyramid.sh)

**🎯 Aim:** Print a centred pyramid of stars.

**💡 Idea:** For row i (1 to n):
- print **n − i spaces**
- then **2i − 1 stars**

**✍️ Dry run (n = 5)**

| Row i | Spaces (n−i) | Stars (2i−1) | Output |
|:--:|:--:|:--:|:--|
| 1 | 4 | 1 | `    *` |
| 2 | 3 | 3 | `   ***` |
| 3 | 2 | 5 | `  *****` |
| 4 | 1 | 7 | ` *******` |
| 5 | 0 | 9 | `*********` |

**❓ Viva questions**
- *Why 3 loops?* The outer loop handles rows. The first inner loop prints spaces. The second inner loop prints stars.
- *Why `echo -n`?* To stay on the same line. The plain `echo` at the end moves to the next row.
- *Upside-down pyramid?* Run the outer loop backwards: `for (( i = n; i >= 1; i-- ))`.

---

## 25. Number pattern — [`25_number_pattern.sh`](25_number_pattern.sh)

**🎯 Aim:** For n = 3 print:
```
1
1 2
1 2 3
```

**💡 Idea:** Row i prints the numbers 1 to i. The inner loop runs `j = 1 … i`.

**❓ Viva questions**
- *How do you print `1 / 2 2 / 3 3 3` instead?* Print `$i` instead of `$j`.
- *How do you print the right-angle star triangle?* Print `*` instead of `$j`.

---

## 26. Array input and display — [`26_array_input.sh`](26_array_input.sh)

**🎯 Aim:** Read n elements into an array and display them.

**🔑 Key lines**
```bash
for (( i = 0; i < n; i++ ))
do
    read arr[i]
done

for (( i = 0; i < n; i++ ))
do
    echo "arr[$i] = ${arr[i]}"
done
```

**❓ Viva questions**
- *What is an array?* A variable that stores many values, each reached by an index.
- *Where does the index start?* 0.
- *Why braces in `${arr[i]}`?* Without them, `$arr[i]` would print the first element followed by the text `[i]`.
- *Print all elements at once?* `echo ${arr[@]}` or `${arr[*]}`.
- *Number of elements?* `${#arr[@]}`.
- *Declare an array directly?* `arr=(10 20 30)`.

---

## 27. Largest element in an array — [`27_largest_in_array.sh`](27_largest_in_array.sh)

**🎯 Aim:** Find the largest value in an array.

**💡 Idea:** Assume the first element is the largest (`max`). Compare each remaining element. If it is bigger, it becomes the new `max`.

**🔑 Key lines**
```bash
max=${arr[0]}
for (( i = 1; i < n; i++ ))
do
    if (( arr[i] > max ))
    then
        max=${arr[i]}
    fi
done
```

**✍️ Dry run (12 45 7 89 23):** max = 12 → 45 → 45 → 89 → 89 → **89**

**❓ Viva questions**
- *Why start max at `arr[0]` instead of 0?* If all numbers are negative, starting at 0 would give the wrong answer.
- *Smallest element?* Change `>` to `<`.
- *Why does the loop start at 1?* `arr[0]` is already in `max`.
- *How many comparisons?* n − 1. The time complexity is **O(n)**.

---

## 28. Pascal's triangle — [`28_pascal_triangle.sh`](28_pascal_triangle.sh)

**🎯 Aim:** Print n rows of Pascal's triangle.

```
           1
         1   1
       1   2   1
     1   3   3   1
   1   4   6   4   1
```

**💡 Idea:**
- Every value is a **combination** C(i, j) = "i choose j".
- Each row starts with 1, and the next value comes from the previous one:
  **next = current × (i − j) / (j + 1)**
- Leading spaces (2 per step) centre the row. `printf "%4d"` prints each number in a 4-character-wide box so the columns line up.

**🔑 Key lines**
```bash
c=1
for (( j = 0; j <= i; j++ ))
do
    printf "%4d" $c
    c=$((c * (i - j) / (j + 1)))
done
```

**✍️ Dry run (row i = 4)**

| j | print c | next c = c × (4 − j) / (j + 1) |
|:--:|:--:|:--|
| 0 | 1 | 1 × 4 / 1 = 4 |
| 1 | 4 | 4 × 3 / 2 = 6 |
| 2 | 6 | 6 × 2 / 3 = 4 |
| 3 | 4 | 4 × 1 / 4 = 1 |
| 4 | 1 | |

Row: `1 4 6 4 1` ✅

**❓ Viva questions**
- *What is Pascal's triangle?* Each number is the sum of the two numbers above it. The edges are 1.
- *What does row i represent?* The coefficients of (a + b)^i. Row 2 → 1 2 1 → a² + 2ab + b².
- *Why multiply first and then divide?* The product is always exactly divisible, so integer division gives the correct value with no remainder.
- *What does `%4d` mean?* Print an integer right-aligned in a field 4 characters wide.

---

## 29. Largest of three numbers — [`29_largest_of_three.sh`](29_largest_of_three.sh)

**🎯 Aim:** Find the largest of a, b and c.

**🔑 Key lines**
```bash
if (( a >= b && a >= c ))
then
    largest=$a
elif (( b >= a && b >= c ))
then
    largest=$b
else
    largest=$c
fi
```

**✍️ Dry run:** 15 42 27 → a is not largest → b ≥ a and b ≥ c ✅ → **42**

**❓ Viva questions**
- *Why `>=` instead of `>`?* So that equal values (for example 5 5 3) still give an answer.
- *What does `&&` mean?* AND: both conditions must be true.
- *Old-style version?* `if [ $a -ge $b ] && [ $a -ge $c ]`.

---

## 30. Linux commands — [`30_linux_commands.sh`](30_linux_commands.sh)

**🎯 Aim:** Show `mkdir`, `cd`, `ls`, `cat`, `>`, `>>`, `grep`, `sed`, `cal`, `xclock`, `oclock`.

**💡 What happens, step by step**

| Step | Command | What it shows |
|:--:|:--|:--|
| 1 | `work=$(mktemp -d)` | Creates a temporary folder (in `/tmp`) so your real files are safe |
| 2 | `mkdir "$work/demo"` | Makes a folder |
| 3 | `cd "$work/demo"` | Enters it |
| 4 | `echo "apple" > fruits.txt` | `>` creates the file and writes the first line |
| 5 | `echo "banana" >> fruits.txt` (and 2 more) | `>>` adds lines to the end |
| 6 | `ls` | Shows `fruits.txt` |
| 7 | `cat fruits.txt` | Prints the 4 lines |
| 8 | `grep "an" fruits.txt` | Lines containing "an" → banana, mango |
| 9 | `sed 's/apple/grape/' fruits.txt` | Prints the file with apple replaced by grape (the file itself is unchanged) |
| 10 | `cal 7 2026` | Calendar for July 2026 |
| 11 | `command -v $clock > /dev/null 2>&1 && [ -n "$DISPLAY" ]` | Checks that the clock program is installed **and** a screen (X11) is available |
| 12 | `$clock` | Opens xclock or oclock |
| 13 | `cd /` then `rm -rf "$work"` | Leaves and deletes the temporary folder (cleanup) |

**❓ Viva questions**
- *Difference between `>` and `>>`?* `>` overwrites the file. `>>` appends to the end.
- *What does `command -v xclock` do?* It prints the path of the program if it exists. It is used to check whether the program is installed.
- *What does `> /dev/null 2>&1` do?* It hides both normal output and errors.
- *What does `[ -n "$DISPLAY" ]` check?* That the `DISPLAY` variable is not empty, which means a graphical screen is available.
- *Why `cd /` before `rm -rf`?* You should not delete the folder you are standing in.
- *After running the script, is your terminal inside `demo`?* No. A script runs in a **separate child process**. Its `cd` does not affect your terminal. (To change your terminal's folder, use `source script.sh`.)
- *What is `mktemp -d`?* It makes a new, uniquely named, empty temporary directory and prints its path.

---

# Part E: Rapid-fire viva questions

<details>
<summary><b>Click to open: 40 quick questions with answers</b></summary>

| # | Question | Answer |
|:--:|:--|:--|
| 1 | What is an OS? | Software that manages the hardware and provides services to programs. |
| 2 | What is a kernel? | The core of the OS that directly manages the CPU, memory, devices and files. |
| 3 | What is a shell? | A command interpreter between the user and the kernel. |
| 4 | Name some shells. | sh, bash, zsh, ksh, csh |
| 5 | What is a shell script? | A file of shell commands executed in order. |
| 6 | What is a shebang? | `#!` on the first line, telling which interpreter runs the script. |
| 7 | How do you make a script executable? | `chmod +x file.sh` |
| 8 | Why `./` before the script name? | The current folder is not in `PATH`. |
| 9 | How do you read input? | `read var` |
| 10 | `echo` vs `printf`? | `echo` prints simply. `printf` formats (like C) and does not add a newline by itself. |
| 11 | How do you do arithmetic? | `$(( ))`, `expr`, `let`, or `bc` for decimals. |
| 12 | Why use `bc`? | Bash arithmetic is integer only. |
| 13 | What is `scale` in bc? | The number of digits after the decimal point. |
| 14 | What is a pipe? | `\|` sends one command's output into the next command's input. |
| 15 | What is command substitution? | `$(command)` puts the output of a command into a variable or string. |
| 16 | How does `if` end? | `fi` |
| 17 | How does `case` end? | `esac` |
| 18 | What ends a case option? | `;;` |
| 19 | Loops in shell? | `for`, `while`, `until` |
| 20 | `break` vs `continue`? | `break` leaves the loop. `continue` skips to the next round. |
| 21 | What is `$?`? | Exit status of the last command (0 = success). |
| 22 | What is `$#`? | Number of arguments. |
| 23 | What is `$0`? | Name of the script. |
| 24 | What is `$$`? | PID of the current shell. |
| 25 | `-eq`, `-gt`, `-lt` mean? | Equal, greater than, less than (inside `[ ]`). |
| 26 | `>` vs `>>`? | Overwrite vs append. |
| 27 | What is `/dev/null`? | A file that throws away everything written to it. |
| 28 | `grep -v`? | Show lines that do NOT match. |
| 29 | `grep -i`? | Ignore case. |
| 30 | `sed 's/a/b/g'`? | Replace every `a` with `b` on each line. |
| 31 | What does `chmod 755` give? | Owner rwx, group r-x, others r-x. |
| 32 | `rm` vs `rmdir`? | `rmdir` removes only empty folders. `rm -r` removes folders with contents. |
| 33 | `ps` shows? | Running processes. |
| 34 | Process vs program? | A program is a file on disk. A process is a running program. |
| 35 | What is CPU scheduling? | Choosing which ready process gets the CPU. |
| 36 | TAT formula? | TAT = CT − AT = WT + BT |
| 37 | WT formula? | WT = TAT − BT |
| 38 | Disadvantage of FCFS? | Convoy effect: high average waiting time. |
| 39 | Disadvantage of priority scheduling? | Starvation. Fixed by aging. |
| 40 | Which algorithm gives the minimum average WT? | SJF (Shortest Job First). |

</details>

---

# Part F: One-page cheat sheet

```bash
#!/bin/bash                      # must be line 1
read n                           # input
read a b                         # two inputs on one line
echo "text $var"                 # output
echo -n "no newline"
x=$((a + b))                     # integer maths
y=$(echo "scale=2; 22/7" | bc)   # decimal maths

if (( n % 2 == 0 )); then ...; elif (( ... )); then ...; else ...; fi
while (( i <= n )); do ...; done
for (( i = 1; i <= n; i++ )); do ...; done
case $ch in 1) ... ;; 2) ... ;; *) ... ;; esac

f() { local x=$1; echo $((x * 2)); }   # function
r=$(f 5)                               # call it → r = 10

arr[i]=5;  ${arr[i]};  ${arr[@]};  ${#arr[@]}   # arrays
exit 0     # success      exit 1    # error
```

**Number tricks used in many programs**

| Want | Code |
|:--|:--|
| Last digit | `n % 10` |
| Remove last digit | `n / 10` |
| Build reverse | `rev = rev * 10 + digit` |
| Even check | `n % 2 == 0` |
| Divides exactly | `n % i == 0` |

**Scheduling in 3 lines**

```
WT[0] = 0,   WT[i] = WT[i-1] + BT[i-1]     (all arrive at 0)
TAT[i] = WT[i] + BT[i]
Average = total / n
```

**Commands from program 30:** `mkdir` make dir · `cd` change dir · `ls` list · `cat` show file · `>` write · `>>` append · `grep` search · `sed` replace · `cal` calendar · `xclock`/`oclock` graphical clocks

---

<div align="center">

**All the best for the viva! 🍀**

</div>
