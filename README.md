# BigInt
Arbitrary-Precision Integer Library in C++
## Overview
BigInt is a custom C++ library that supports arbitrary-precision integers. Unlike standard integer types in C++, this library allows you to work with very large integers beyond the limits of `int`, `long`, or `long long`. BigInt provides basic arithmetic, comparison, and other utility functions to perform calculations with extremely large numbers, making it ideal for applications requiring high-precision calculations, cryptography, or working with large datasets.

## Features
- Arbitrary-precision integers: No upper limit on the size of integers, constrained only by available memory.
- Basic Arithmetic Operations: Addition, subtraction, multiplication, and division.
- Comparison Operations: Equality, less than, greater than, etc.
- I/O Support: Easily read and write BigInt values using streams.
- Additional Utilities: Includes utility functions like factorial, power, and gcd (optional).

## Installation
Clone the repository to your local machine:
```sh
git clone https://github.com/yourusername/BigInt.git
cd BigInt
```
Include `BigInt.h` and `BigInt.cpp` in your project files or compile them directly with your code.

## Usage
### Initialization
To use BigInt in your project, include the header file:

```cpp
#include "BigInt.h"
```
You can create a BigInt in several ways:

```cpp
BigInt a = 123456789;            // Initialize with an int
BigInt b("9876543210123456789");  // Initialize with a string
BigInt c = BigInt::fromString("12345678901234567890"); // Another way to initialize from string
```
### Basic Operations
BigInt supports various arithmetic operations:

```cpp
BigInt sum = a + b;            // Addition
BigInt diff = a - b;           // Subtraction
BigInt prod = a * b;           // Multiplication
BigInt quot = b / a;           // Division
BigInt mod = b % a;            // Modulus
BigInt power = a.pow(10);      // Exponentiation (optional)
BigInt factorial = a.factorial(); // Factorial (optional)
```

### Comparison Operations
BigInt can be compared using standard comparison operators:

```cpp
if (a == b) { /*...*/ }
if (a < b) { /*...*/ }
if (a > b) { /*...*/ }
```

### I/O Operations
BigInt values can be read from or written to streams:

```cpp
std::cout << "BigInt a: " << a << std::endl;
std::cin >> b;
```
### Error Handling
BigInt includes basic error handling for invalid operations (like division by zero), but ensure proper exception handling in cases where input validation is required.

## Contributing
Feel free to fork the repository and make your contributions. Ensure any pull requests include tests for new features.

## License
This project is licensed under the MIT License. See the LICENSE file for details.
