# 🧮 Command-Line Calculator (CLC)

This is a flexible command-line calculator written in C, created as part of a university programming assignment. It supports binary operations (like addition, power, and modulo), unary operations (like square root, log, exponential), and variable definitions for use in advanced calculations.

---

## ✨ Features

- 📌 **Binary operations**: `+`, `-`, `*`, `/`, `%`, `P` (power), `X` (max), `I` (min)
- 📌 **Unary operations**: `S` (square root), `L` (log), `E` (exponential), `C` (ceiling), `F` (floor)
- 📌 **Advanced mode**: Use variables (`a` to `e`) to store and reuse values
- 📌 **Input validation** for invalid operators or unsafe operations (e.g., dividing by zero)
- 📌 Clear UI prompts and error messages
- 📌 Written entirely in C without external libraries

---

## 💻 How to Compile and Run

You can run this program using a terminal with GCC or in **Visual Studio Code** with the C/C++ extension.

### Requirements

- GCC compiler
- (Optional) Visual Studio Code + C/C++ extension

### Steps

1. **Clone or download** the project:
   ```bash
   git clone https://github.com/suragaafar/CommandLineC-Calculator
   cd CommandLineC-Calculator
   ```

2. **Compile the program:**
   ```bash
   gcc 110167826.c -o calculator
   ```

3. **Run the program:**
   ```bash
   ./calculator
   ```

---

🧠 What I Learned
- Writing structured and modular C programs
- Implementing multiple operation types using conditionals
- Simulating variable storage with arrays
- Validating user input and handling edge cases
- Creating intuitive CLI interfaces
