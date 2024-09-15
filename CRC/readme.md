# Cyclic Redundancy Check (CRC) Implementation in C++

This C++ program implements the Cyclic Redundancy Check (CRC) algorithm for error detection. It uses XOR operations to simulate binary division, which is the core mechanism of CRC. The program helps in detecting errors in transmitted data by computing a CRC value and appending it to the data for transmission. On the receiving side, it checks for errors by performing the same division.

## How It Works

1. **Input:**
   - The program takes input data (a binary string) and a divisor (the generator polynomial).
   
2. **CRC Calculation:**
   - The program appends `n-1` zeros to the data where `n` is the length of the divisor.
   - It performs binary division using the divisor and the appended data.
   - The remainder of this division is the CRC value.

3. **Data Transmission:**
   - The CRC value is appended to the original data, forming the transmitted data.
   
4. **Error Detection:**
   - Upon receiving the data, the receiver performs the same division.
   - If the remainder is all zeros, there are no errors in the transmission. Otherwise, errors are detected.

## Program Flow

1. Input the number of bits for the data and divisor.
2. Input the binary data string and divisor.
3. The program calculates and prints the CRC value and the transmitted data.
4. The user then inputs the received data.
5. The program checks for errors by recalculating the remainder using the divisor.

## Usage

### Compilation
To compile the program, use the following command:
```bash
g++ -o crc main.cpp

./crc
```
