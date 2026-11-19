/*
===================================================================================================
Project Title   : Number System Conversion Using C++
Project Tagline : "A comprehensive C++ application for seamless conversion between Binary, Decimal,
                   Octal, and Hexadecimal number systems."
Technologies    : C++ (Standard C++, Turbo C++, Dev C++, CodeBlocks, Visual Studio Code)
Concepts Used   : Functions, Loops, Conditional Statements, Strings, Arrays, Number System Algorithms
===================================================================================================
Description:
The Number System Conversion Using C++ project is designed to perform conversions between
different number systems commonly used in mathematics and computer science. This application
provides a simple, user-friendly interface where users can enter a number in one number system
and convert it into another.

Supports all 12 major number system conversions:
  1.  Decimal     to Binary
  2.  Decimal     to Octal
  3.  Decimal     to Hexadecimal
  4.  Binary      to Decimal
  5.  Binary      to Octal
  6.  Binary      to Hexadecimal
  7.  Octal       to Decimal
  8.  Octal       to Binary
  9.  Octal       to Hexadecimal
  10. Hexadecimal to Decimal
  11. Hexadecimal to Binary
  12. Hexadecimal to Octal
  + Master Conversion: Convert any number to ALL systems simultaneously!
===================================================================================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

// ===============================================================================================
// CONSTANTS AND LOOKUP ARRAYS
// ===============================================================================================
// Array of Hexadecimal characters for base-16 conversions
const char HEX_CHARS[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

// 3-Bit Binary Table for Octal Digits 0 through 7
const string OCTAL_TO_BIN_MAP[8] = {
    "000", "001", "010", "011",
    "100", "101", "110", "111"
};

// 4-Bit Binary Table for Hexadecimal Digits 0 through F
const string HEX_TO_BIN_MAP[16] = {
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"
};

// ===============================================================================================
// HELPER AND STRING UTILITY FUNCTIONS
// ===============================================================================================

// Converts any lowercase letters in a string to uppercase
string toUpperString(string str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = (char)toupper(str[i]);
    }
    return str;
}

// Removes leading and trailing whitespace from an input string
string trimString(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

// Strips unnecessary leading zeros from a number string, keeping a single '0' if all zero
string removeLeadingZeros(string str) {
    size_t firstNonZero = str.find_first_not_of('0');
    if (firstNonZero == string::npos) {
        return "0";
    }
    return str.substr(firstNonZero);
}

// Pauses the console and waits for the user to press Enter
void pauseConsole() {
    cout << "\nPress Enter to continue...";
    cin.ignore(10000, '\n');
    cin.get();
}

// Displays decorative header line
void printDivider(char ch = '=', int length = 72) {
    for (int i = 0; i < length; ++i) cout << ch;
    cout << "\n";
}

// ===============================================================================================
// INPUT VALIDATION FUNCTIONS (Error Checking for Invalid Inputs)
// ===============================================================================================

// Validates whether the given string is a valid Binary number (contains only '0' and '1')
bool isValidBinary(const string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    return true;
}

// Validates whether the given string is a valid Octal number (contains only digits '0' to '7')
bool isValidOctal(const string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '7') {
            return false;
        }
    }
    return true;
}

// Validates whether the given string is a valid Decimal integer (contains only digits '0' to '9')
bool isValidDecimal(const string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Validates whether the given string is a valid Hexadecimal number ('0'-'9', 'A'-'F', 'a'-'f')
bool isValidHexadecimal(const string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); ++i) {
        char c = (char)toupper(str[i]);
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            return false;
        }
    }
    return true;
}

// Safely converts a decimal string to an unsigned long long integer
bool parseDecimalString(const string& str, unsigned long long& outValue) {
    if (!isValidDecimal(str)) return false;
    try {
        stringstream ss(str);
        unsigned long long val;
        ss >> val;
        if (ss.fail()) return false;
        outValue = val;
        return true;
    } catch (...) {
        return false;
    }
}

// ===============================================================================================
// CORE CONVERSION ALGORITHMS
// ===============================================================================================

// -----------------------------------------------------------------------------------------------
// 1. Decimal to Binary (Successive Division by 2)
// -----------------------------------------------------------------------------------------------
string decimalToBinary(unsigned long long decimal, bool showSteps = false) {
    if (decimal == 0) {
        if (showSteps) {
            cout << "\n[Step-by-Step Derivation]:\n";
            cout << "  0 divided by 2 = 0 with Remainder: 0\n";
            cout << "  Result = 0\n";
        }
        return "0";
    }

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: Successive Division by 2]\n";
        cout << "------------------------------------------------------------\n";
        cout << left << setw(10) << "Step" 
             << setw(20) << "Current Number" 
             << setw(15) << "Quotient (/ 2)" 
             << setw(15) << "Remainder (% 2)" << "\n";
        cout << "------------------------------------------------------------\n";
    }

    string binary = "";
    unsigned long long current = decimal;
    int step = 1;

    while (current > 0) {
        unsigned long long rem = current % 2;
        unsigned long long quotient = current / 2;

        if (showSteps) {
            cout << left << setw(10) << step
                 << setw(20) << current
                 << setw(15) << quotient
                 << setw(15) << rem << "\n";
        }

        binary += (rem == 0 ? '0' : '1');
        current = quotient;
        step++;
    }

    // Reverse to read remainders from bottom to top (LSB to MSB reversed)
    reverse(binary.begin(), binary.end());

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Reading remainders from bottom to top: " << binary << "\n";
    }

    return binary;
}

// -----------------------------------------------------------------------------------------------
// 2. Decimal to Octal (Successive Division by 8)
// -----------------------------------------------------------------------------------------------
string decimalToOctal(unsigned long long decimal, bool showSteps = false) {
    if (decimal == 0) {
        if (showSteps) cout << "\n[Step-by-Step Derivation]: 0 in Octal is 0\n";
        return "0";
    }

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: Successive Division by 8]\n";
        cout << "------------------------------------------------------------\n";
        cout << left << setw(10) << "Step" 
             << setw(20) << "Current Number" 
             << setw(15) << "Quotient (/ 8)" 
             << setw(15) << "Remainder (% 8)" << "\n";
        cout << "------------------------------------------------------------\n";
    }

    string octal = "";
    unsigned long long current = decimal;
    int step = 1;

    while (current > 0) {
        unsigned long long rem = current % 8;
        unsigned long long quotient = current / 8;

        if (showSteps) {
            cout << left << setw(10) << step
                 << setw(20) << current
                 << setw(15) << quotient
                 << setw(15) << rem << "\n";
        }

        octal += to_string(rem);
        current = quotient;
        step++;
    }

    reverse(octal.begin(), octal.end());

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Reading remainders from bottom to top: " << octal << "\n";
    }

    return octal;
}

// -----------------------------------------------------------------------------------------------
// 3. Decimal to Hexadecimal (Successive Division by 16)
// -----------------------------------------------------------------------------------------------
string decimalToHexadecimal(unsigned long long decimal, bool showSteps = false) {
    if (decimal == 0) {
        if (showSteps) cout << "\n[Step-by-Step Derivation]: 0 in Hexadecimal is 0\n";
        return "0";
    }

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: Successive Division by 16]\n";
        cout << "------------------------------------------------------------\n";
        cout << left << setw(10) << "Step" 
             << setw(20) << "Current Number" 
             << setw(15) << "Quotient (/ 16)" 
             << setw(15) << "Remainder" 
             << setw(10) << "Hex Digit" << "\n";
        cout << "------------------------------------------------------------\n";
    }

    string hex = "";
    unsigned long long current = decimal;
    int step = 1;

    while (current > 0) {
        unsigned long long rem = current % 16;
        unsigned long long quotient = current / 16;
        char hexDigit = HEX_CHARS[rem];

        if (showSteps) {
            cout << left << setw(10) << step
                 << setw(20) << current
                 << setw(15) << quotient
                 << setw(15) << rem
                 << setw(10) << hexDigit << "\n";
        }

        hex += hexDigit;
        current = quotient;
        step++;
    }

    reverse(hex.begin(), hex.end());

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Reading remainders from bottom to top: " << hex << "\n";
    }

    return hex;
}

// -----------------------------------------------------------------------------------------------
// 4. Binary to Decimal (Positional Notation: Sum of d_i * 2^i)
// -----------------------------------------------------------------------------------------------
unsigned long long binaryToDecimal(const string& binary, bool showSteps = false) {
    string bin = removeLeadingZeros(binary);
    unsigned long long decimal = 0;
    size_t len = bin.length();

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: Positional Expansion]\n";
        cout << "Formula: Value = Sum(digit * 2^position)\n";
        cout << "------------------------------------------------------------\n";
    }

    for (size_t i = 0; i < len; ++i) {
        int bit = bin[i] - '0';
        size_t power = len - 1 - i;
        unsigned long long termValue = (unsigned long long)bit << power; // bit * 2^power
        decimal += termValue;

        if (showSteps) {
            cout << "  Bit [" << bit << "] * 2^" << setw(2) << left << power 
                 << " = " << setw(15) << right << termValue 
                 << "  | Running Total: " << decimal << "\n";
        }
    }

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Decimal Result: " << decimal << "\n";
    }

    return decimal;
}

// -----------------------------------------------------------------------------------------------
// 5. Binary to Octal (Direct 3-Bit Grouping from Right to Left)
// -----------------------------------------------------------------------------------------------
string binaryToOctal(const string& binary, bool showSteps = false) {
    string bin = removeLeadingZeros(binary);
    if (bin == "0") return "0";

    // Pad with leading zeros so length is a multiple of 3
    int padLength = (3 - (int)(bin.length() % 3)) % 3;
    string padded = string(padLength, '0') + bin;

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: 3-Bit Grouping Algorithm]\n";
        cout << "Original Binary : " << bin << "\n";
        if (padLength > 0) {
            cout << "Padded Binary   : " << padded << " (" << padLength << " leading zero(s) added)\n";
        }
        cout << "------------------------------------------------------------\n";
        cout << left << setw(15) << "3-Bit Group" 
             << setw(25) << "Calculation (4*b2 + 2*b1 + 1*b0)" 
             << setw(15) << "Octal Digit" << "\n";
        cout << "------------------------------------------------------------\n";
    }

    string octal = "";
    for (size_t i = 0; i < padded.length(); i += 3) {
        string group = padded.substr(i, 3);
        int octDigit = (group[0] - '0') * 4 + (group[1] - '0') * 2 + (group[2] - '0') * 1;
        octal += to_string(octDigit);

        if (showSteps) {
            string calc = to_string(group[0] - '0') + "*4 + " + 
                          to_string(group[1] - '0') + "*2 + " + 
                          to_string(group[2] - '0') + "*1";
            cout << left << setw(15) << group 
                 << setw(25) << calc 
                 << setw(15) << octDigit << "\n";
        }
    }

    string result = removeLeadingZeros(octal);

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Octal Result: " << result << "\n";
    }

    return result;
}

// -----------------------------------------------------------------------------------------------
// 6. Binary to Hexadecimal (Direct 4-Bit Grouping from Right to Left)
// -----------------------------------------------------------------------------------------------
string binaryToHexadecimal(const string& binary, bool showSteps = false) {
    string bin = removeLeadingZeros(binary);
    if (bin == "0") return "0";

    int padLength = (4 - (int)(bin.length() % 4)) % 4;
    string padded = string(padLength, '0') + bin;

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: 4-Bit Grouping Algorithm]\n";
        cout << "Original Binary : " << bin << "\n";
        if (padLength > 0) {
            cout << "Padded Binary   : " << padded << " (" << padLength << " leading zero(s) added)\n";
        }
        cout << "------------------------------------------------------------\n";
        cout << left << setw(15) << "4-Bit Group" 
             << setw(25) << "Decimal Value" 
             << setw(15) << "Hex Digit" << "\n";
        cout << "------------------------------------------------------------\n";
    }

    string hex = "";
    for (size_t i = 0; i < padded.length(); i += 4) {
        string group = padded.substr(i, 4);
        int val = (group[0] - '0') * 8 + (group[1] - '0') * 4 + 
                  (group[2] - '0') * 2 + (group[3] - '0') * 1;
        char hexDigit = HEX_CHARS[val];
        hex += hexDigit;

        if (showSteps) {
            cout << left << setw(15) << group 
                 << setw(25) << val 
                 << setw(15) << hexDigit << "\n";
        }
    }

    string result = removeLeadingZeros(hex);

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Hexadecimal Result: " << result << "\n";
    }

    return result;
}

// -----------------------------------------------------------------------------------------------
// 7. Octal to Decimal (Positional Expansion: Sum of d_i * 8^i)
// -----------------------------------------------------------------------------------------------
unsigned long long octalToDecimal(const string& octal, bool showSteps = false) {
    string oct = removeLeadingZeros(octal);
    unsigned long long decimal = 0;
    size_t len = oct.length();

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: Positional Expansion]\n";
        cout << "Formula: Value = Sum(digit * 8^position)\n";
        cout << "------------------------------------------------------------\n";
    }

    unsigned long long basePower = 1;
    for (int i = (int)len - 1; i >= 0; --i) {
        int digit = oct[i] - '0';
        unsigned long long termValue = (unsigned long long)digit * basePower;
        decimal += termValue;

        if (showSteps) {
            int pos = (int)len - 1 - i;
            cout << "  Digit [" << digit << "] * 8^" << setw(2) << left << pos 
                 << " (" << setw(10) << left << basePower << ") = " 
                 << setw(15) << right << termValue 
                 << "  | Running Total: " << decimal << "\n";
        }

        if (i > 0) basePower *= 8;
    }

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Decimal Result: " << decimal << "\n";
    }

    return decimal;
}

// -----------------------------------------------------------------------------------------------
// 8. Octal to Binary (Convert each octal digit to 3-bit binary group)
// -----------------------------------------------------------------------------------------------
string octalToBinary(const string& octal, bool showSteps = false) {
    string oct = removeLeadingZeros(octal);
    if (oct == "0") return "0";

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: 3-Bit Expansion]\n";
        cout << "Each octal digit maps to its exact 3-bit binary representation.\n";
        cout << "------------------------------------------------------------\n";
        cout << left << setw(15) << "Octal Digit" 
             << setw(20) << "3-Bit Binary" << "\n";
        cout << "------------------------------------------------------------\n";
    }

    string binary = "";
    for (size_t i = 0; i < oct.length(); ++i) {
        int digit = oct[i] - '0';
        string binGroup = OCTAL_TO_BIN_MAP[digit];
        binary += binGroup;

        if (showSteps) {
            cout << left << setw(15) << digit 
                 << setw(20) << binGroup << "\n";
        }
    }

    string result = removeLeadingZeros(binary);

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Concatenated Binary   : " << binary << "\n";
        cout << "After Removing Leading: " << result << "\n";
    }

    return result;
}

// -----------------------------------------------------------------------------------------------
// 9. Octal to Hexadecimal (Octal -> 3-Bit Binary -> 4-Bit Hexadecimal)
// -----------------------------------------------------------------------------------------------
string octalToHexadecimal(const string& octal, bool showSteps = false) {
    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: Two-Stage Conversion]\n";
        cout << "Stage 1: Convert Octal to Intermediate Binary (3 bits per digit)\n";
        cout << "Stage 2: Convert Binary to Hexadecimal (4-bit nibble grouping)\n";
        cout << "------------------------------------------------------------\n";
    }

    string binary = octalToBinary(octal, showSteps);
    string hex = binaryToHexadecimal(binary, showSteps);

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Final Hexadecimal Result: " << hex << "\n";
    }

    return hex;
}

// -----------------------------------------------------------------------------------------------
// 10. Hexadecimal to Decimal (Positional Expansion: Sum of d_i * 16^i)
// -----------------------------------------------------------------------------------------------
unsigned long long hexadecimalToDecimal(const string& hex, bool showSteps = false) {
    string h = toUpperString(removeLeadingZeros(hex));
    unsigned long long decimal = 0;
    size_t len = h.length();

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: Positional Expansion]\n";
        cout << "Formula: Value = Sum(digit * 16^position)\n";
        cout << "------------------------------------------------------------\n";
    }

    unsigned long long basePower = 1;
    for (int i = (int)len - 1; i >= 0; --i) {
        char c = h[i];
        int val;
        if (c >= '0' && c <= '9') val = c - '0';
        else val = c - 'A' + 10;

        unsigned long long termValue = (unsigned long long)val * basePower;
        decimal += termValue;

        if (showSteps) {
            int pos = (int)len - 1 - i;
            cout << "  Digit ['" << c << "' (" << setw(2) << val << ")] * 16^" 
                 << setw(2) << left << pos << " (" << setw(12) << left << basePower << ") = " 
                 << setw(15) << right << termValue 
                 << "  | Running Total: " << decimal << "\n";
        }

        if (i > 0) basePower *= 16;
    }

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Decimal Result: " << decimal << "\n";
    }

    return decimal;
}

// -----------------------------------------------------------------------------------------------
// 11. Hexadecimal to Binary (Convert each hex digit to 4-bit binary group)
// -----------------------------------------------------------------------------------------------
string hexadecimalToBinary(const string& hex, bool showSteps = false) {
    string h = toUpperString(removeLeadingZeros(hex));
    if (h == "0") return "0";

    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: 4-Bit Expansion]\n";
        cout << "Each hex digit maps to its exact 4-bit binary representation.\n";
        cout << "------------------------------------------------------------\n";
        cout << left << setw(15) << "Hex Digit" 
             << setw(20) << "4-Bit Binary" << "\n";
        cout << "------------------------------------------------------------\n";
    }

    string binary = "";
    for (size_t i = 0; i < h.length(); ++i) {
        char c = h[i];
        int val = (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 10);
        string binGroup = HEX_TO_BIN_MAP[val];
        binary += binGroup;

        if (showSteps) {
            cout << left << setw(15) << c 
                 << setw(20) << binGroup << "\n";
        }
    }

    string result = removeLeadingZeros(binary);

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Concatenated Binary   : " << binary << "\n";
        cout << "After Removing Leading: " << result << "\n";
    }

    return result;
}

// -----------------------------------------------------------------------------------------------
// 12. Hexadecimal to Octal (Hexadecimal -> 4-Bit Binary -> 3-Bit Octal)
// -----------------------------------------------------------------------------------------------
string hexadecimalToOctal(const string& hex, bool showSteps = false) {
    if (showSteps) {
        cout << "\n[Step-by-Step Derivation: Two-Stage Conversion]\n";
        cout << "Stage 1: Convert Hexadecimal to Intermediate Binary (4 bits per digit)\n";
        cout << "Stage 2: Convert Binary to Octal (3-bit grouping)\n";
        cout << "------------------------------------------------------------\n";
    }

    string binary = hexadecimalToBinary(hex, showSteps);
    string octal = binaryToOctal(binary, showSteps);

    if (showSteps) {
        cout << "------------------------------------------------------------\n";
        cout << "Final Octal Result: " << octal << "\n";
    }

    return octal;
}

// ===============================================================================================
// MASTER ALL-IN-ONE CONVERTER (Converts an input to ALL four systems at once)
// ===============================================================================================
void convertAll(const string& inputStr, int fromSystem) {
    string cleanInput = trimString(inputStr);
    string bin = "", oct = "", dec = "", hex = "";

    try {
        if (fromSystem == 1) { // Decimal
            unsigned long long d;
            if (!parseDecimalString(cleanInput, d)) {
                cout << "\n[ERROR]: Invalid decimal number entered! Digits 0-9 only.\n";
                return;
            }
            dec = to_string(d);
            bin = decimalToBinary(d);
            oct = decimalToOctal(d);
            hex = decimalToHexadecimal(d);
        } else if (fromSystem == 2) { // Binary
            if (!isValidBinary(cleanInput)) {
                cout << "\n[ERROR]: Invalid binary number entered! Digits 0 and 1 only.\n";
                return;
            }
            bin = removeLeadingZeros(cleanInput);
            dec = to_string(binaryToDecimal(bin));
            oct = binaryToOctal(bin);
            hex = binaryToHexadecimal(bin);
        } else if (fromSystem == 3) { // Octal
            if (!isValidOctal(cleanInput)) {
                cout << "\n[ERROR]: Invalid octal number entered! Digits 0 to 7 only.\n";
                return;
            }
            oct = removeLeadingZeros(cleanInput);
            dec = to_string(octalToDecimal(oct));
            bin = octalToBinary(oct);
            hex = octalToHexadecimal(oct);
        } else if (fromSystem == 4) { // Hexadecimal
            if (!isValidHexadecimal(cleanInput)) {
                cout << "\n[ERROR]: Invalid hexadecimal number entered! (0-9, A-F only)\n";
                return;
            }
            hex = toUpperString(removeLeadingZeros(cleanInput));
            dec = to_string(hexadecimalToDecimal(hex));
            bin = hexadecimalToBinary(hex);
            oct = hexadecimalToOctal(hex);
        }

        printDivider('=');
        cout << "              ALL-IN-ONE NUMBER SYSTEM CONVERSION MATRIX\n";
        printDivider('=');
        cout << left << setw(20) << "Input Number"     << ": " << cleanInput << "\n";
        cout << left << setw(20) << "Source System"     << ": ";
        if (fromSystem == 1) cout << "Decimal (Base 10)\n";
        else if (fromSystem == 2) cout << "Binary (Base 2)\n";
        else if (fromSystem == 3) cout << "Octal (Base 8)\n";
        else if (fromSystem == 4) cout << "Hexadecimal (Base 16)\n";
        printDivider('-');
        cout << left << setw(20) << "Binary (Base 2)"      << ": " << bin << "\n";
        cout << left << setw(20) << "Octal (Base 8)"       << ": " << oct << "\n";
        cout << left << setw(20) << "Decimal (Base 10)"    << ": " << dec << "\n";
        cout << left << setw(20) << "Hexadecimal (Base 16)"<< ": " << hex << "\n";
        printDivider('=');

    } catch (const exception& e) {
        cout << "\n[ERROR]: Conversion failed. " << e.what() << "\n";
    }
}

// ===============================================================================================
// INTERACTIVE USER INTERFACE AND MENU DISPATCHER
// ===============================================================================================

// Prompts the user whether they want to see step-by-step mathematical steps
bool askStepByStep() {
    char ch;
    cout << "Would you like to view step-by-step calculation? (Y/N): ";
    cin >> ch;
    return (ch == 'Y' || ch == 'y');
}

// Displays the formatted main title banner
void displayBanner() {
    printDivider('*');
    cout << "          NUMBER SYSTEM CONVERSION USING C++\n";
    cout << "   \"A comprehensive C++ application for seamless conversion between\n";
    cout << "        Binary, Decimal, Octal, and Hexadecimal number systems.\"\n";
    printDivider('*');
}

// Displays the main interactive menu
void displayMenu() {
    cout << "\n======================== MAIN MENU ========================\n";
    cout << " [1]  Decimal     to Binary\n";
    cout << " [2]  Decimal     to Octal\n";
    cout << " [3]  Decimal     to Hexadecimal\n";
    cout << " ----------------------------------------------------------\n";
    cout << " [4]  Binary      to Decimal\n";
    cout << " [5]  Binary      to Octal\n";
    cout << " [6]  Binary      to Hexadecimal\n";
    cout << " ----------------------------------------------------------\n";
    cout << " [7]  Octal       to Decimal\n";
    cout << " [8]  Octal       to Binary\n";
    cout << " [9]  Octal       to Hexadecimal\n";
    cout << " ----------------------------------------------------------\n";
    cout << " [10] Hexadecimal to Decimal\n";
    cout << " [11] Hexadecimal to Binary\n";
    cout << " [12] Hexadecimal to Octal\n";
    cout << " ----------------------------------------------------------\n";
    cout << " [13] ALL-IN-ONE Master Conversion (Any Base -> All Bases)\n";
    cout << " [14] View Conversion Summary Matrix Table\n";
    cout << " [0]  Exit Application\n";
    cout << "===========================================================\n";
    cout << "Enter your choice (0-14): ";
}

// Displays the conversion matrix overview
void displayConversionMatrix() {
    printDivider('=');
    cout << "                   NUMBER SYSTEM CONVERSION MATRIX\n";
    printDivider('=');
    cout << left << setw(18) << "From Base" 
         << setw(18) << "To Binary (2)" 
         << setw(18) << "To Octal (8)" 
         << setw(18) << "To Decimal (10)" 
         << setw(18) << "To Hexadecimal (16)" << "\n";
    printDivider('-');
    cout << left << setw(18) << "Binary (2)" 
         << setw(18) << "[Identical]" 
         << setw(18) << "3-Bit Grouping" 
         << setw(18) << "Sum(d * 2^i)" 
         << setw(18) << "4-Bit Grouping" << "\n";

    cout << left << setw(18) << "Octal (8)" 
         << setw(18) << "3-Bit Expansion" 
         << setw(18) << "[Identical]" 
         << setw(18) << "Sum(d * 8^i)" 
         << setw(18) << "Oct -> Bin -> Hex" << "\n";

    cout << left << setw(18) << "Decimal (10)" 
         << setw(18) << "Divide by 2" 
         << setw(18) << "Divide by 8" 
         << setw(18) << "[Identical]" 
         << setw(18) << "Divide by 16" << "\n";

    cout << left << setw(18) << "Hexadecimal (16)" 
         << setw(18) << "4-Bit Expansion" 
         << setw(18) << "Hex -> Bin -> Oct" 
         << setw(18) << "Sum(d * 16^i)" 
         << setw(18) << "[Identical]" << "\n";
    printDivider('=');
}

// ===============================================================================================
// MAIN APPLICATION LOOP
// ===============================================================================================
int main() {
    displayBanner();

    int choice = -1;
    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "\n[ERROR]: Invalid menu input! Please enter a number between 0 and 14.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 0) {
            cout << "\n===========================================================\n";
            cout << " Thank you for using Number System Conversion Using C++!\n";
            cout << " Program created for learning, problem-solving & accuracy.\n";
            cout << "===========================================================\n\n";
            break;
        }

        switch (choice) {
            // -------------------------------------------------------------
            // DECIMAL CONVERSIONS
            // -------------------------------------------------------------
            case 1: { // Decimal to Binary
                cout << "\n--- [Decimal to Binary Conversion] ---\n";
                cout << "Enter a positive Decimal number: ";
                string decStr;
                cin >> decStr;
                unsigned long long dec;
                if (!parseDecimalString(decStr, dec)) {
                    cout << "[ERROR]: Invalid decimal input! Must contain digits 0-9 only.\n";
                } else {
                    bool steps = askStepByStep();
                    string result = decimalToBinary(dec, steps);
                    printDivider('-');
                    cout << "Result: (" << dec << ")_10 = (" << result << ")_2\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            case 2: { // Decimal to Octal
                cout << "\n--- [Decimal to Octal Conversion] ---\n";
                cout << "Enter a positive Decimal number: ";
                string decStr;
                cin >> decStr;
                unsigned long long dec;
                if (!parseDecimalString(decStr, dec)) {
                    cout << "[ERROR]: Invalid decimal input! Must contain digits 0-9 only.\n";
                } else {
                    bool steps = askStepByStep();
                    string result = decimalToOctal(dec, steps);
                    printDivider('-');
                    cout << "Result: (" << dec << ")_10 = (" << result << ")_8\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            case 3: { // Decimal to Hexadecimal
                cout << "\n--- [Decimal to Hexadecimal Conversion] ---\n";
                cout << "Enter a positive Decimal number: ";
                string decStr;
                cin >> decStr;
                unsigned long long dec;
                if (!parseDecimalString(decStr, dec)) {
                    cout << "[ERROR]: Invalid decimal input! Must contain digits 0-9 only.\n";
                } else {
                    bool steps = askStepByStep();
                    string result = decimalToHexadecimal(dec, steps);
                    printDivider('-');
                    cout << "Result: (" << dec << ")_10 = (" << result << ")_16\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            // -------------------------------------------------------------
            // BINARY CONVERSIONS
            // -------------------------------------------------------------
            case 4: { // Binary to Decimal
                cout << "\n--- [Binary to Decimal Conversion] ---\n";
                cout << "Enter a Binary number (0s and 1s): ";
                string binStr;
                cin >> binStr;
                binStr = trimString(binStr);
                if (!isValidBinary(binStr)) {
                    cout << "[ERROR]: Invalid binary input! Must contain 0 and 1 only.\n";
                } else {
                    bool steps = askStepByStep();
                    unsigned long long result = binaryToDecimal(binStr, steps);
                    printDivider('-');
                    cout << "Result: (" << binStr << ")_2 = (" << result << ")_10\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            case 5: { // Binary to Octal
                cout << "\n--- [Binary to Octal Conversion] ---\n";
                cout << "Enter a Binary number (0s and 1s): ";
                string binStr;
                cin >> binStr;
                binStr = trimString(binStr);
                if (!isValidBinary(binStr)) {
                    cout << "[ERROR]: Invalid binary input! Must contain 0 and 1 only.\n";
                } else {
                    bool steps = askStepByStep();
                    string result = binaryToOctal(binStr, steps);
                    printDivider('-');
                    cout << "Result: (" << binStr << ")_2 = (" << result << ")_8\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            case 6: { // Binary to Hexadecimal
                cout << "\n--- [Binary to Hexadecimal Conversion] ---\n";
                cout << "Enter a Binary number (0s and 1s): ";
                string binStr;
                cin >> binStr;
                binStr = trimString(binStr);
                if (!isValidBinary(binStr)) {
                    cout << "[ERROR]: Invalid binary input! Must contain 0 and 1 only.\n";
                } else {
                    bool steps = askStepByStep();
                    string result = binaryToHexadecimal(binStr, steps);
                    printDivider('-');
                    cout << "Result: (" << binStr << ")_2 = (" << result << ")_16\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            // -------------------------------------------------------------
            // OCTAL CONVERSIONS
            // -------------------------------------------------------------
            case 7: { // Octal to Decimal
                cout << "\n--- [Octal to Decimal Conversion] ---\n";
                cout << "Enter an Octal number (digits 0-7): ";
                string octStr;
                cin >> octStr;
                octStr = trimString(octStr);
                if (!isValidOctal(octStr)) {
                    cout << "[ERROR]: Invalid octal input! Must contain digits 0 to 7 only.\n";
                } else {
                    bool steps = askStepByStep();
                    unsigned long long result = octalToDecimal(octStr, steps);
                    printDivider('-');
                    cout << "Result: (" << octStr << ")_8 = (" << result << ")_10\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            case 8: { // Octal to Binary
                cout << "\n--- [Octal to Binary Conversion] ---\n";
                cout << "Enter an Octal number (digits 0-7): ";
                string octStr;
                cin >> octStr;
                octStr = trimString(octStr);
                if (!isValidOctal(octStr)) {
                    cout << "[ERROR]: Invalid octal input! Must contain digits 0 to 7 only.\n";
                } else {
                    bool steps = askStepByStep();
                    string result = octalToBinary(octStr, steps);
                    printDivider('-');
                    cout << "Result: (" << octStr << ")_8 = (" << result << ")_2\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            case 9: { // Octal to Hexadecimal
                cout << "\n--- [Octal to Hexadecimal Conversion] ---\n";
                cout << "Enter an Octal number (digits 0-7): ";
                string octStr;
                cin >> octStr;
                octStr = trimString(octStr);
                if (!isValidOctal(octStr)) {
                    cout << "[ERROR]: Invalid octal input! Must contain digits 0 to 7 only.\n";
                } else {
                    bool steps = askStepByStep();
                    string result = octalToHexadecimal(octStr, steps);
                    printDivider('-');
                    cout << "Result: (" << octStr << ")_8 = (" << result << ")_16\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            // -------------------------------------------------------------
            // HEXADECIMAL CONVERSIONS
            // -------------------------------------------------------------
            case 10: { // Hexadecimal to Decimal
                cout << "\n--- [Hexadecimal to Decimal Conversion] ---\n";
                cout << "Enter a Hexadecimal number (0-9, A-F): ";
                string hexStr;
                cin >> hexStr;
                hexStr = trimString(hexStr);
                if (!isValidHexadecimal(hexStr)) {
                    cout << "[ERROR]: Invalid hexadecimal input! (Digits 0-9, A-F only)\n";
                } else {
                    bool steps = askStepByStep();
                    unsigned long long result = hexadecimalToDecimal(hexStr, steps);
                    printDivider('-');
                    cout << "Result: (" << toUpperString(hexStr) << ")_16 = (" << result << ")_10\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            case 11: { // Hexadecimal to Binary
                cout << "\n--- [Hexadecimal to Binary Conversion] ---\n";
                cout << "Enter a Hexadecimal number (0-9, A-F): ";
                string hexStr;
                cin >> hexStr;
                hexStr = trimString(hexStr);
                if (!isValidHexadecimal(hexStr)) {
                    cout << "[ERROR]: Invalid hexadecimal input! (Digits 0-9, A-F only)\n";
                } else {
                    bool steps = askStepByStep();
                    string result = hexadecimalToBinary(hexStr, steps);
                    printDivider('-');
                    cout << "Result: (" << toUpperString(hexStr) << ")_16 = (" << result << ")_2\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            case 12: { // Hexadecimal to Octal
                cout << "\n--- [Hexadecimal to Octal Conversion] ---\n";
                cout << "Enter a Hexadecimal number (0-9, A-F): ";
                string hexStr;
                cin >> hexStr;
                hexStr = trimString(hexStr);
                if (!isValidHexadecimal(hexStr)) {
                    cout << "[ERROR]: Invalid hexadecimal input! (Digits 0-9, A-F only)\n";
                } else {
                    bool steps = askStepByStep();
                    string result = hexadecimalToOctal(hexStr, steps);
                    printDivider('-');
                    cout << "Result: (" << toUpperString(hexStr) << ")_16 = (" << result << ")_8\n";
                    printDivider('-');
                }
                pauseConsole();
                break;
            }

            // -------------------------------------------------------------
            // ALL-IN-ONE MASTER CONVERSION
            // -------------------------------------------------------------
            case 13: {
                cout << "\n--- [ALL-IN-ONE Master Conversion] ---\n";
                cout << "Select your Input Number System:\n";
                cout << "  1. Decimal\n";
                cout << "  2. Binary\n";
                cout << "  3. Octal\n";
                cout << "  4. Hexadecimal\n";
                cout << "Enter system choice (1-4): ";
                int sysChoice;
                if (!(cin >> sysChoice) || sysChoice < 1 || sysChoice > 4) {
                    cout << "[ERROR]: Invalid system selection!\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                } else {
                    cout << "Enter number to convert: ";
                    string numInput;
                    cin >> numInput;
                    convertAll(numInput, sysChoice);
                }
                pauseConsole();
                break;
            }

            // -------------------------------------------------------------
            // VIEW CONVERSION MATRIX
            // -------------------------------------------------------------
            case 14: {
                displayConversionMatrix();
                pauseConsole();
                break;
            }

            default:
                cout << "\n[ERROR]: Unknown option! Please select a valid choice (0-14).\n";
                pauseConsole();
                break;
        }
    }

    return 0;
}
