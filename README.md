# Number System Conversion Using C++

[![C++](https://img.shields.io/badge/Language-C%2B%2B11%20%2F%20C%2B%2B14-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Tests](https://img.shields.io/badge/Tests-20%2F20%20Passing-brightgreen.svg)](tests/test_suite.py)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)](#how-to-compile-and-run)
[![Report](https://img.shields.io/badge/Report-7--Page%20PDF-orange.svg)](docs/Number_System_Conversion_Project_Report.pdf)

> **Project Tagline:**  
> *"A comprehensive C++ application for seamless conversion between Binary, Decimal, Octal, and Hexadecimal number systems."*

---

## Project Overview

The **Number System Conversion Using C++** project is designed to perform conversions between different number systems commonly used in mathematics and computer science. This application provides a simple, user-friendly, and interactive interface where users can enter a number in one number system and convert it into another.

The program is developed using standard **C++** and utilizes functions, loops, conditional statements, arrays, and string manipulation techniques to perform accurate conversions. The project helps students and programmers understand the mathematical relationship between different number systems and enhances their programming, data representation, and problem-solving skills.

---

## Objectives

- **To understand various number systems:** Grasp the theoretical foundations of Binary (Base 2), Octal (Base 8), Decimal (Base 10), and Hexadecimal (Base 16).
- **To implement conversion algorithms using C++:** Write clean, modular, and optimized conversion algorithms from scratch.
- **To provide a fast and accurate conversion tool:** Guarantee precision for both small and large numbers while eliminating overflow issues.
- **To improve knowledge of data representation in computers:** Learn how digital hardware processes, groups, and expands bits and bytes.

---

## Key Features

- ✅ **User-Friendly Menu-Driven Interface:** Clean console UI with clear options, prompts, and formatted tabular outputs.
- ✅ **Supports All Number System Conversions:** Complete coverage of all 12 pairwise conversions plus an All-in-One master conversion.
- ✅ **Step-by-Step Educational Derivations:** Displays the exact mathematical steps (successive division, polynomial expansions, and bit-grouping tables).
- ✅ **Handles Large Numbers Efficiently:** Leverages 64-bit integer arithmetic (`unsigned long long`) and direct string-based grouping algorithms for arbitrarily large bit patterns.
- ✅ **Error Checking for Invalid Inputs:** Strict validation checks ensure users cannot enter non-binary digits for binary, numbers $\ge 8$ for octal, non-digits for decimal, or non-hex characters for hexadecimal.
- ✅ **Fast and Accurate Results:** Optimized lookup tables and direct bitwise grouping provide instant, exact calculations.
- ✅ **Modular Programming Using Functions:** Highly maintainable code with separated validation, conversion, and presentation modules.

---

## Conversion Matrix

| From System \ To System | To Binary (Base 2) | To Octal (Base 8) | To Decimal (Base 10) | To Hexadecimal (Base 16) |
| :--- | :--- | :--- | :--- | :--- |
| **Binary (Base 2)** | *Identical* | 3-Bit Grouping ($O(N)$) | Positional: $\sum b_i \times 2^i$ | 4-Bit Grouping ($O(N)$) |
| **Octal (Base 8)** | 3-Bit Bit Expansion | *Identical* | Positional: $\sum o_i \times 8^i$ | Octal $\to$ Binary $\to$ Hex |
| **Decimal (Base 10)** | Repeated Division by 2 | Repeated Division by 8 | *Identical* | Repeated Division by 16 |
| **Hexadecimal (Base 16)** | 4-Bit Bit Expansion | Hex $\to$ Binary $\to$ Octal | Positional: $\sum h_i \times 16^i$ | *Identical* |

---

## Supported Conversions (12 Core Conversions)

1. **Decimal to Binary**: Repeated division by 2; remainders collected in reverse order.
2. **Decimal to Octal**: Repeated division by 8; remainders collected in reverse order.
3. **Decimal to Hexadecimal**: Repeated division by 16; remainders mapped to hex digits (`0-9`, `A-F`).
4. **Binary to Decimal**: Positional weighted sum ($\sum d_i \times 2^i$).
5. **Binary to Octal**: Direct 3-bit clustering from right to left using lookup tables.
6. **Binary to Hexadecimal**: Direct 4-bit nibble clustering from right to left.
7. **Octal to Decimal**: Positional weighted sum ($\sum d_i \times 8^i$).
8. **Octal to Binary**: Each octal digit expands directly to 3 binary bits (`000` to `111`).
9. **Octal to Hexadecimal**: Two-phase conversion via intermediate 3-bit to 4-bit binary grouping.
10. **Hexadecimal to Decimal**: Positional weighted sum ($\sum d_i \times 16^i$).
11. **Hexadecimal to Binary**: Each hex digit expands directly to 4 binary bits (`0000` to `1111`).
12. **Hexadecimal to Octal**: Two-phase conversion via intermediate 4-bit to 3-bit binary grouping.
13. **Master All-in-One Conversion**: Enter any number in any format and instantly view its equivalent in Binary, Octal, Decimal, and Hexadecimal.

---

## Technologies and Concepts Used

### Technologies Used
- **Programming Language:** C++ (Standard C++, compatible with C++98 / C++03 / C++11 / C++14 / C++17 / C++20)
- **Supported Compilers & IDEs:**
  - **Dev C++** (Orwell / Embarcadero Dev-C++)
  - **Code::Blocks** (MinGW GCC)
  - **Visual Studio Code** (with C/C++ extension and MinGW/MSVC/Clang)
  - **Turbo C++** (DOSBox / Borland C++)
  - **Command-line GCC / Clang / MSVC**

### Core Concepts Demonstrated
1. **Functions & Modularity:** Dedicated conversion functions, input validators, string helpers, and UI display functions.
2. **Loops (`while`, `for`):** Iterating through digits, successive division loops, polynomial accumulations, and grouping algorithms.
3. **Conditional Statements (`if-else`, `switch-case`):** Menu routing, character-to-value branching, validation boundaries, and edge-case handling.
4. **Strings (`std::string`):** Dynamic character arrays, substring grouping, prefix padding, reversing, trimming, and case transformations.
5. **Arrays:**
   - Lookup array for Hexadecimal symbols: `HEX_CHARS[16] = {'0'...'F'}`
   - 3-bit binary table for Octal digits: `OCTAL_TO_BIN_MAP[8]`
   - 4-bit binary table for Hexadecimal digits: `HEX_TO_BIN_MAP[16]`
6. **Number System Algorithms:**
   - Successive division by target base (extracting remainders via modulo).
   - Positional polynomial expansion ($Value = \sum digit \times base^{position}$).
   - Direct power-of-2 bit cluster grouping ($2^3 = 8$, $2^4 = 16$).

---

## Project Structure

```
NumberC++/
├── docs/
│   ├── Number_System_Conversion_Project_Report.pdf  # 7-page academic submission report
│   ├── generate_report_pdf.py                       # Python script to regenerate PDF
│   └── project-report.md                            # Complete markdown report
├── include/                                         # Modular suite C++ headers
│   ├── BaseArithmetic.hpp
│   ├── BaseConverter.hpp
│   ├── BigIntConverter.hpp
│   ├── FractionalConverter.hpp
│   ├── IEEE754Converter.hpp
│   ├── Menu.hpp
│   ├── SignedRepresentation.hpp
│   ├── SpecialCodes.hpp
│   ├── StepExplainer.hpp
│   ├── TestSuite.hpp
│   └── Utils.hpp
├── src/                                             # Modular suite C++ source implementations
│   ├── BaseArithmetic.cpp
│   ├── BaseConverter.cpp
│   ├── BigIntConverter.cpp
│   ├── FractionalConverter.cpp
│   ├── IEEE754Converter.cpp
│   ├── Menu.cpp
│   ├── SignedRepresentation.cpp
│   ├── SpecialCodes.cpp
│   ├── StepExplainer.cpp
│   ├── TestSuite.cpp
│   ├── Utils.cpp
│   └── main.cpp
├── tests/
│   ├── sample_batch.txt                             # Batch conversion test cases
│   └── test_suite.py                                # Automated verification suite (20 tests)
├── .gitignore                                       # Git ignore rules for binaries & build artifacts
├── build.bat                                        # Windows MinGW build script
├── CMakeLists.txt                                   # Cross-platform CMake build configuration
├── LICENSE                                          # Open source MIT license
├── Makefile                                         # Standard GNU Makefile (Linux/macOS/MinGW)
├── NumberSystemConverter.cpp                        # Standalone single-file version (Dev-C++, CodeBlocks, Turbo C++)
├── README.md                                        # Repository documentation
├── run.bat                                          # Windows one-click launcher
└── run.ps1                                          # PowerShell launcher
```

---

## How to Compile and Run

### 1. Using Dev C++
1. Open **Dev C++**.
2. Click **File $\to$ Open** and select `NumberSystemConverter.cpp`.
3. Press **F11** (Compile & Run) or click **Execute $\to$ Compile & Run**.
4. The console window will launch immediately with the menu.

### 2. Using Code::Blocks
1. Open **Code::Blocks**.
2. Click **File $\to$ Open** and choose `NumberSystemConverter.cpp`.
3. Press **F9** (Build and Run) or click the yellow gear with green play button.
4. Interact with the application in the popup console window.

### 3. Using Visual Studio Code
1. Open the folder in VS Code (`File -> Open Folder... -> NumberC++`).
2. Open `NumberSystemConverter.cpp`.
3. Press `Ctrl + Shift + B` or open the integrated terminal (`Ctrl + ~`) and type:
   ```bash
   g++ -std=c++11 -O2 NumberSystemConverter.cpp -o NumberSystemConverter.exe
   ./NumberSystemConverter.exe
   ```
4. Alternatively, simply run `.\run.bat` or `.\run.ps1`.

### 4. Using Turbo C++
1. Copy `NumberSystemConverter.cpp` into your Turbo C++ `SOURCE` / `BIN` directory (e.g. `C:\TurboC++\Disk\TurboC3\BIN`).
2. Open Turbo C++ and press `F3` to load `NumberSystemConverter.cpp`.
3. Press `Alt + F9` to compile.
4. Press `Ctrl + F9` to run.

### 5. Using the Command Line (MinGW / GCC / Clang / MSVC)
- **Windows (Command Prompt / PowerShell):**
  ```cmd
  build.bat
  run.bat
  ```
- **Direct GCC Command:**
  ```bash
  g++ -std=c++11 -O2 -Wall NumberSystemConverter.cpp -o NumberSystemConverter.exe
  ./NumberSystemConverter.exe
  ```
- **Linux / macOS:**
  ```bash
  make
  ./NumberSystemConverter
  ```

---

## Detailed Algorithm Walkthrough

### 1. Decimal to Binary / Octal / Hexadecimal
- **Method:** Successive Division Algorithm.
- **Algorithm:**
  1. Let $N$ be the input decimal number and $B$ be the target base ($2, 8, \text{or } 16$).
  2. While $N > 0$:
     - Compute remainder $R = N \pmod B$.
     - Look up character representation for $R$ (e.g., $10 \to 'A'$ for hex).
     - Append digit to result string.
     - Update $N = \lfloor N / B \rfloor$.
  3. Reverse the accumulated string so that the first remainder becomes the Least Significant Digit (LSD) and the last becomes the Most Significant Digit (MSD).

### 2. Binary / Octal / Hexadecimal to Decimal
- **Method:** Positional Notation (Polynomial Expansion).
- **Formula:**
  $$\text{Decimal Value} = \sum_{i=0}^{k-1} d_i \times B^i$$
  where $d_i$ is the value of the digit at index $i$ from right-to-left, and $B$ is the source base.
- **Algorithm:**
  1. Initialize `decimal = 0` and `multiplier = 1`.
  2. Iterate through the string from right to left (index $k-1$ down to $0$).
  3. Convert character $c$ to integer value $d$.
  4. Accumulate: `decimal += d * multiplier`.
  5. Update: `multiplier *= B`.

### 3. Binary to Octal & Hexadecimal (Direct Grouping)
- **Why Grouping Works:**
  - $2^3 = 8$: Each octal digit represents exactly 3 binary bits.
  - $2^4 = 16$: Each hexadecimal digit represents exactly 4 binary bits.
- **Algorithm:**
  1. Pad the binary string with leading zeros so its length is a multiple of 3 (for octal) or 4 (for hex).
  2. Traverse the padded string in chunks of 3 or 4 bits.
  3. Look up the corresponding octal or hex symbol in $O(1)$ time.
  4. Concatenate and strip unnecessary leading zeros.

---

## Sample Execution & Test Runs

### Example 1: Decimal to Binary (with Steps)
```
--- [Decimal to Binary Conversion] ---
Enter a positive Decimal number: 45
Would you like to view step-by-step calculation? (Y/N): Y

[Step-by-Step Derivation: Successive Division by 2]
------------------------------------------------------------
Step      Current Number      Quotient (/ 2) Remainder (% 2)
------------------------------------------------------------
1         45                  22             1              
2         22                  11             0              
3         11                  5              1              
4         5                   2              1              
5         2                   1              0              
6         1                   0              1              
------------------------------------------------------------
Reading remainders from bottom to top: 101101
------------------------------------------------------------
Result: (45)_10 = (101101)_2
------------------------------------------------------------
```

### Example 2: Binary to Hexadecimal (4-Bit Grouping)
```
--- [Binary to Hexadecimal Conversion] ---
Enter a Binary number (0s and 1s): 110111101010
Would you like to view step-by-step calculation? (Y/N): Y

[Step-by-Step Derivation: 4-Bit Grouping Algorithm]
Original Binary : 110111101010
------------------------------------------------------------
4-Bit Group    Decimal Value            Hex Digit      
------------------------------------------------------------
1101           13                       D              
1110           14                       E              
1010           10                       A              
------------------------------------------------------------
Hexadecimal Result: DEA
------------------------------------------------------------
Result: (110111101010)_2 = (DEA)_16
------------------------------------------------------------
```

### Example 3: ALL-IN-ONE Master Conversion
```
--- [ALL-IN-ONE Master Conversion] ---
Select your Input Number System:
  1. Decimal
  2. Binary
  3. Octal
  4. Hexadecimal
Enter system choice (1-4): 4
Enter number to convert: 1A3F

========================================================================
              ALL-IN-ONE NUMBER SYSTEM CONVERSION MATRIX
========================================================================
Input Number        : 1A3F
Source System       : Hexadecimal (Base 16)
------------------------------------------------------------------------
Binary (Base 2)     : 1101000111111
Octal (Base 8)      : 15077
Decimal (Base 10)   : 6719
Hexadecimal (Base 16): 1A3F
========================================================================
```

---

## Expected Outcome

The application successfully converts numbers among Binary, Decimal, Octal, and Hexadecimal systems while providing accurate results and helping users understand how different number systems are represented and converted in computer systems.

---

## Conclusion

This project demonstrates the practical implementation of number system conversion techniques using C++. It serves as an educational tool for students and beginners to learn number systems, programming concepts, and computational logic effectively.
