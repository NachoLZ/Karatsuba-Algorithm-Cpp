# Karatsuba Multiplication Algorithm

This C++ program implements the Karatsuba algorithm for multiplying large numbers. It is designed to be more efficient than the standard long multiplication algorithm for numbers with many digits. This implementation operates on binary strings.

This project was created for a university homework assignment in an "Algorithms and Complexity" course.

## How it Works

The Karatsuba algorithm is a divide-and-conquer algorithm. It breaks down the numbers to be multiplied into smaller parts and performs multiplications on these smaller parts. It reduces the number of single-digit multiplications required, which leads to a better time complexity.

The main logic is in the `multiply` function in `main.cpp`.

## How to Compile and Run

This project uses CMake to build.

1.  **Prerequisites:** Make sure you have a C++ compiler (like G++) and CMake installed.
2.  **Configure and Build:**
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```
3.  **Prepare Input:**
    Create a file named `input.txt` in the same directory as the executable. The file should contain pairs of binary numbers to be multiplied, separated by spaces, with each pair on a new line.

    Example `input.txt`:
    ```
    2 10 11
    4 1010 1101
    ```
    *(Note: The first number on each line in the original `input.txt` seems to represent the number of bits, but the current code doesn't use it.)*

4.  **Run:**
    Execute the program from within the build directory:
    ```bash
    ./Karatsuba
    ```
    The program will read the numbers from `input.txt`, compute the product for each pair, and print the binary result to the console, followed by the total execution time.

## Code Structure

*   `main.cpp`: Contains the main program logic, including the Karatsuba multiplication implementation (`multiply`), binary string addition (`addBitStrings`), and file I/O.
*   `CMakeLists.txt`: The build configuration file for CMake.
*   `input.txt`: The input file where pairs of binary numbers are read from.
