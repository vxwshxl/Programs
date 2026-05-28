# Microprocessor Viva Questions (8085 & 8086)

## Introduction to Microprocessors

### 1. What is a microprocessor?

A microprocessor is a programmable electronic device that processes data and performs arithmetic and logical operations.

### 2. What is the difference between 8085 and 8086?

| 8085                    | 8086                   |
| ----------------------- | ---------------------- |
| 8-bit microprocessor    | 16-bit microprocessor  |
| 8-bit data bus          | 16-bit data bus        |
| 16-bit address bus      | 20-bit address bus     |
| Can access 64 KB memory | Can access 1 MB memory |
| Slower                  | Faster                 |

### 3. Why is 8086 faster than 8085?

8086 uses a 16-bit architecture and pipelining with BIU and EU, making it faster.

### 4. What is a register?

A register is a small memory location inside the microprocessor used for temporary storage.

### 5. What is the accumulator?

Accumulator is a special register used for arithmetic and logical operations.

---

# Memory and Addressing

### 6. What is memory addressing?

Memory addressing is the process of accessing data stored in memory locations.

### 7. What is the address range of 8085?

8085 has a 16-bit address bus and can access 64 KB memory.

### 8. What is the address range of 8086?

8086 has a 20-bit address bus and can access 1 MB memory.

### 9. What is a memory location?

A memory location is a unique address where data is stored.

### 10. Why do programs use addresses like 2500H and 2600H?

These addresses are used to store input and output data.

---

# 8085 Instructions Viva

## LDA and STA

### 11. What is LDA?

LDA loads data from memory into accumulator.

Example:

```asm
LDA 2500H
```

### 12. What is STA?

STA stores accumulator data into memory.

Example:

```asm
STA 2502H
```

### 13. Difference between LDA and STA?

* LDA → Memory to accumulator
* STA → Accumulator to memory

---

## MOV and MVI

### 14. What is MOV instruction?

MOV transfers data between registers.

Example:

```asm
MOV B,A
```

### 15. What is MVI?

MVI loads immediate data into a register.

Example:

```asm
MVI A,00H
```

### 16. Difference between MOV and MVI?

* MOV copies data
* MVI loads fixed data

---

## Arithmetic Instructions

### 17. What does ADD do?

ADD adds source operand to accumulator.

### 18. What does SUB do?

SUB subtracts source operand from accumulator.

### 19. What is DAD?

DAD performs 16-bit addition with HL pair.

### 20. What is SBB?

SBB subtracts data including borrow.

### 21. What is the role of carry flag?

Carry flag indicates carry or borrow during arithmetic.

---

## Increment and Decrement

### 22. What is INR?

INR increments data by 1.

### 23. What is DCR?

DCR decrements data by 1.

### 24. What is INX?

INX increments a register pair.

---

## Compare and Jump

### 25. What is CMP?

CMP compares accumulator with another operand.

### 26. Does CMP store result?

No. It only affects flags.

### 27. What is JNZ?

Jump if Zero flag is not set.

### 28. What is JC?

Jump if Carry flag is set.

### 29. What is JNC?

Jump if Carry flag is not set.

### 30. What is JMP?

Unconditional jump.

### 31. Why are jump instructions used?

To control program flow and loops.

---

## Register Pair Instructions

### 32. What is LHLD?

Loads HL pair directly from memory.

### 33. What is SHLD?

Stores HL pair into memory.

### 34. What is XCHG?

Exchanges HL and DE register pairs.

---

## Halt

### 35. What is HLT?

HLT stops execution.

Why used?
To terminate program.

---

# 8086 Instructions Viva

### 36. What is MOV in 8086?

Transfers data between memory and registers.

### 37. What is ADD?

Performs addition.

### 38. What is SUB?

Performs subtraction.

### 39. What is MUL?

Performs multiplication.

Example:

```asm
MUL AL
```

### 40. Where is MUL result stored?

Usually in AX register.

### 41. What is INC?

Increments value by 1.

### 42. What is DEC?

Decrements value by 1.

### 43. What is LOOP instruction?

Repeats execution until CX becomes zero.

### 44. What is CMP in 8086?

Compares two operands and updates flags.

---

# Program-Based Viva Questions

## Addition Program

### 45. Why is register B used in 8085 addition?

To temporarily store first number.

### 46. Where is result stored in 8-bit addition?

At memory location 2502H.

### 47. Why is accumulator important in addition?

Because arithmetic occurs through accumulator.

---

## Subtraction Program

### 48. Why is SUB used?

To subtract one operand from another.

### 49. What happens if borrow occurs?

Carry flag becomes set.

---

## 16-bit Addition

### 50. Why is DAD used?

Because DAD performs 16-bit addition.

### 51. Why is XCHG used?

To exchange data between HL and DE pairs.

---

## Multiplication Program

### 52. How is multiplication performed in 8085?

Using repeated addition.

### 53. Why is loop required?

To repeat addition multiple times.

### 54. Which register works as counter?

Register C.

---

## Division Program

### 55. How is division performed in 8085?

Using repeated subtraction.

### 56. Which register stores quotient?

Register D.

### 57. Why is JC used in division?

To stop when borrow occurs.

---

## Biggest and Smallest Number Programs

### 58. Why is CMP used?

To compare numbers.

### 59. How is biggest number identified?

By replacing accumulator with larger value.

### 60. How is smallest number identified?

By replacing accumulator with smaller value.

### 61. Where is result stored?

Usually at 2600H.

---

## Factorial Program

### 62. What is factorial?

Product of all positive integers up to a number.

Example:
5! = 5 × 4 × 3 × 2 × 1 = 120

### 63. Which instruction performs factorial multiplication?

MUL

---

## Square Program

### 64. How is square calculated?

By multiplying a number by itself.

### 65. Where is square result stored?

AX register.

---

# Frequently Asked Viva Questions

### 66. Why are flags important?

Flags indicate arithmetic and logical conditions.

### 67. What is a loop?

A repeated execution block.

### 68. What is immediate addressing?

Data is directly included in instruction.

### 69. What is direct addressing?

Instruction directly specifies memory address.

### 70. Why are registers faster than memory?

Because registers are inside CPU.

### 71. Why is assembly language used?

For low-level hardware control.

### 72. What are mnemonics?

Short instruction names like MOV, ADD, SUB.

### 73. What is machine code?

Binary representation of instructions.

### 74. Why do we study 8085 and 8086?

To understand microprocessor fundamentals.

### 75. Which is better: 8085 or 8086?

8086 is more powerful due to 16-bit processing and larger memory support.

---

# Quick Viva Tips

* Know every instruction meaning.
* Remember memory locations used.
* Understand why loops are used.
* Be able to explain program flow.
* Practice tracing programs step-by-step.
* Understand flags and jump conditions.

These questions cover most viva topics related to the provided 8085 and 8086 programs.