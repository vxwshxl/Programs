# Microprocessor Instruction Reference (8085 & 8086)

## Overview
This document contains the meanings and purposes of commonly used instructions in 8085 and 8086 microprocessors.

---

# 8085 Instructions

## 1. LDA – Load Accumulator Direct
**Meaning:** Loads data from a specified memory location into the accumulator.

### Syntax
```asm
LDA address
```

### Example
```asm
LDA 2500H
```

### Operation
A ← Memory[2500H]

---

## 2. STA – Store Accumulator Direct

**Meaning:** Stores accumulator data into a specified memory location.

### Syntax
```asm
STA address
```

### Example
```asm
STA 2502H
```

### Operation
Memory[2502H] ← A

---

## 3. MOV – Move Data

**Meaning:** Copies data from source register to destination register.

### Syntax
```asm
MOV destination, source
```

### Example
```asm
MOV B,A
```

### Operation
B ← A

---

## 4. MVI – Move Immediate Data

**Meaning:** Loads immediate data into a register.

### Syntax
```asm
MVI register,data
```

### Example
```asm
MVI A,00H
```

### Operation
A ← 00H

---

## 5. LXI – Load Register Pair Immediate

**Meaning:** Loads 16-bit data into a register pair.

### Syntax
```asm
LXI rp,data16
```

### Example
```asm
LXI H,2500H
```

### Operation
HL ← 2500H

---

## 6. LHLD – Load H and L Direct

**Meaning:** Loads HL register pair directly from memory.

### Syntax
```asm
LHLD address
```

### Example
```asm
LHLD 2500H
```

### Operation
L ← Memory[address]  
H ← Memory[address+1]

---

## 7. SHLD – Store H and L Direct

**Meaning:** Stores HL register pair into memory.

### Syntax
```asm
SHLD address
```

### Example
```asm
SHLD 2504H
```

### Operation
Memory[address] ← L  
Memory[address+1] ← H

---

## 8. XCHG – Exchange Registers

**Meaning:** Exchanges contents of HL and DE register pairs.

### Syntax
```asm
XCHG
```

### Example
```asm
XCHG
```

### Operation
HL ↔ DE

---

## 9. ADD – Addition

**Meaning:** Adds register or memory data to accumulator.

### Syntax
```asm
ADD source
```

### Example
```asm
ADD B
```

### Operation
A ← A + B

---

## 10. SUB – Subtraction

**Meaning:** Subtracts register or memory data from accumulator.

### Syntax
```asm
SUB source
```

### Example
```asm
SUB B
```

### Operation
A ← A − B

---

## 11. INR – Increment

**Meaning:** Increases register or memory value by 1.

### Syntax
```asm
INR register
```

### Example
```asm
INR D
```

### Operation
D ← D + 1

---

## 12. DCR – Decrement

**Meaning:** Decreases register or memory value by 1.

### Syntax
```asm
DCR register
```

### Example
```asm
DCR C
```

### Operation
C ← C − 1

---

## 13. INX – Increment Register Pair

**Meaning:** Increments a register pair by 1.

### Syntax
```asm
INX rp
```

### Example
```asm
INX H
```

### Operation
HL ← HL + 1

---

## 14. CMP – Compare

**Meaning:** Compares register or memory data with accumulator.

### Syntax
```asm
CMP source
```

### Example
```asm
CMP M
```

### Operation
Compares without storing result.

---

## 15. DAD – Double Add

**Meaning:** Adds register pair to HL pair.

### Syntax
```asm
DAD rp
```

### Example
```asm
DAD D
```

### Operation
HL ← HL + DE

---

## 16. SBB – Subtract with Borrow

**Meaning:** Subtracts data and borrow from accumulator.

### Syntax
```asm
SBB source
```

### Example
```asm
SBB D
```

### Operation
A ← A − D − Borrow

---

## 17. JC – Jump if Carry

**Meaning:** Jumps if carry flag is set.

### Syntax
```asm
JC address
```

### Example
```asm
JC END
```

---

## 18. JNC – Jump if No Carry

**Meaning:** Jumps if carry flag is not set.

### Syntax
```asm
JNC address
```

### Example
```asm
JNC SKIP
```

---

## 19. JMP – Unconditional Jump

**Meaning:** Transfers control unconditionally.

### Syntax
```asm
JMP address
```

### Example
```asm
JMP LOOP
```

---

## 20. JNZ – Jump if Not Zero

**Meaning:** Jumps if zero flag is not set.

### Syntax
```asm
JNZ address
```

### Example
```asm
JNZ LOOP
```

---

## 21. HLT – Halt

**Meaning:** Stops program execution.

### Syntax
```asm
HLT
```

---

# 8086 Instructions

## 1. MOV – Move

**Meaning:** Transfers data between registers and memory.

### Syntax
```asm
MOV destination, source
```

### Example
```asm
MOV AL,[2500]
```

---

## 2. ADD – Addition

**Meaning:** Adds source to destination.

### Syntax
```asm
ADD destination, source
```

### Example
```asm
ADD AL,BL
```

---

## 3. SUB – Subtraction

**Meaning:** Subtracts source from destination.

### Syntax
```asm
SUB destination, source
```

### Example
```asm
SUB AL,BL
```

---

## 4. MUL – Multiply

**Meaning:** Multiplies accumulator with operand.

### Syntax
```asm
MUL source
```

### Example
```asm
MUL AL
```

---

## 5. DEC – Decrement

**Meaning:** Decreases value by 1.

### Syntax
```asm
DEC operand
```

### Example
```asm
DEC CL
```

---

## 6. INC – Increment

**Meaning:** Increases value by 1.

### Syntax
```asm
INC operand
```

### Example
```asm
INC SI
```

---

## 7. CMP – Compare

**Meaning:** Compares two operands.

### Syntax
```asm
CMP destination, source
```

### Example
```asm
CMP AL,[SI]
```

---

## 8. LOOP – Loop Instruction

**Meaning:** Repeats instructions until CX becomes zero.

### Syntax
```asm
LOOP label
```

### Example
```asm
LOOP BACK
```

---

## 9. JNC – Jump if No Carry

**Meaning:** Jumps when carry flag is not set.

### Syntax
```asm
JNC label
```

---

## 10. JC – Jump if Carry

**Meaning:** Jumps when carry flag is set.

### Syntax
```asm
JC label
```

---

## 11. HLT – Halt

**Meaning:** Stops program execution.

### Syntax
```asm
HLT
```

---

# Summary

These instructions form the foundation of most 8085 and 8086 assembly language programs including arithmetic operations, looping, comparison, data transfer, and decision making.