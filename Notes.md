# The Life Cycle of a C Program: From Text to Process

This document details the internal journey of a C program. It explains how high-level C code is transformed into machine instructions that a CPU can execute. This process is collectively known as the **Build Process**, handled by the **Toolchain**.

## Overview: The GCC Toolchain

When you run a command like `gcc file.c`, you are not running a single program. You are triggering a pipeline of four distinct tools:
1.  **Preprocessor** (`cpp`)
2.  **Compiler** (`cc1`)
3.  **Assembler** (`as`)
4.  **Linker** (`ld`)

Once the file is built, the **Loader** (part of the OS) takes over to run it.

---

## Phase 1: Preprocessing (The Text Editor)

The preprocessor is a text substitution tool. It prepares the code for the compiler. It does not understand C syntax; it only understands lines starting with `#`.

* **Input:** Source Code (`.c`) and Header Files (`.h`).
* **Process:**
    1.  **Removal of Comments:** All `//` and `/* ... */` comments are stripped out.
    2.  **File Inclusion:** Directives like `#include <stdio.h>` are replaced by the *entire content* of that header file.
    3.  **Macro Expansion:** All defined macros (e.g., `#define MAX 100`) are replaced with their actual values throughout the code.
    4.  **Conditional Compilation:** Logic like `#ifdef` and `#ifndef` determines which parts of the code are kept and which are discarded.
* **Output:** **Translation Unit**. This is "Pure C" code.
* **File Extension:** `.i` (Intermediate file).

> **Note:** The `.i` file is usually huge because it contains the code of every header file you included.

---

## Phase 2: Compilation (The Translator)

This is the core of the process. The compiler analyzes the syntax and semantics of the pure C code and translates it into assembly language.

* **Input:** Translation Unit (`.i`).
* **Process:**
    1.  **Syntax Analysis:** Checks for grammar errors (missing semicolons, mismatched braces).
    2.  **Semantic Analysis:** Checks for logic errors (type mismatches, variables used before declaration).
    3.  **Optimization:** The compiler may rearrange code to make it faster or smaller (e.g., removing variables that are never used).
    4.  **Code Generation:** Translates the high-level logic (loops, if-statements) into processor-specific mnemonics (instructions).
* **Output:** **Assembly Code**. This is human-readable low-level code.
* **File Extension:** `.s` (Assembly file).

---

## Phase 3: Assembly (The Encoder)

The CPU cannot read text instructions like `MOV` or `ADD`. The Assembler translates these mnemonics into binary machine code.

* **Input:** Assembly Code (`.s`).
* **Process:**
    1.  **Translation:** Converts assembly instructions into binary opcodes (0s and 1s).
    2.  **Symbol Table Creation:** It creates a list of symbols (function names, global variables) defined in this file.
    3.  **Placeholder Creation:** If the code calls a function defined in *another* file, the assembler doesn't know the address yet. It leaves a "hole" (a relocation entry) in the binary code to be filled later.
* **Output:** **Relocatable Object File**.
* **File Extension:** `.o` (Unix/Linux) or `.obj` (Windows).

> **Why "Relocatable"?** Because the code doesn't have fixed memory addresses yet. It can be moved (relocated) to different parts of memory during the linking phase.

---

## Phase 4: Linking (The Connector)

A large C program consists of multiple object files and system libraries. The Linker combines them into a single file.

* **Input:** Multiple Object Files (`.o`) and Static/Dynamic Libraries (`.a`, `.lib`).
* **Process:**
    1.  **Symbol Resolution:** It looks at the "holes" left by the assembler. If `File_A.o` calls a function inside `File_B.o`, the linker connects them. If it can't find the definition, you get an `undefined reference` error.
    2.  **Address Binding:** It merges the code segments (text) and data segments from all object files and assigns relative memory addresses to them.
    3.  **Library Linking:** It pulls in code for standard functions like `printf` or `malloc` from the C Standard Library.
* **Output:** **Executable Binary**.
* **File Extension:** `.exe` (Windows) or `a.out` (Linux).

---

## Phase 5: The Loader (Runtime Execution)

This phase happens when you actually run the program. The **Loader** is a program inside the Operating System (kernel).

* **Trigger:** User types `./program` or double-clicks the executable.
* **Process:**
    1.  **Validation:** The OS checks permissions and validates the file format (e.g., ELF on Linux, PE on Windows).
    2.  **Memory Allocation:** The Loader requests RAM from the OS and creates a new **Process**. It maps the virtual memory space into segments:
        * **Text Segment:** Stores the read-only machine code.
        * **Data Segment:** Stores global and static variables.
        * **Heap:** Reserved for dynamic memory allocation (`malloc`).
        * **Stack:** Reserved for function calls and local variables.
    3.  **Dynamic Linking (Optional):** If the program uses `.dll` (Windows) or `.so` (Linux) files, the loader finds these shared libraries and loads them into memory.
    4.  **Entry:** The CPU instruction pointer is set to the address of `_start` (a low-level entry point), which eventually calls your `main()` function.

---

## Summary of File Types

| Stage | Input Ext | Tool | Output Ext | Format |
| :--- | :--- | :--- | :--- | :--- |
| **Preprocessing** | `.c`, `.h` | Preprocessor | `.i` | Modified Source Text |
| **Compilation** | `.i` | Compiler | `.s` | Assembly Text |
| **Assembly** | `.s` | Assembler | `.o` / `.obj` | Binary (with holes) |
| **Linking** | `.o`, `.lib` | Linker | `.exe` / `a.out` | Complete Binary |