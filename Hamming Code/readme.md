# Hamming Code Implementation in C++

C++ implementation of Hamming codes. The implementation can handle different (n, k) Hamming code configurations, where `n` is the total number of bits and `k` is the number of data bits.

## Overview

The Hamming code encodes `k` bits of data into `n` bits by adding parity bits. This implementation calculates the number of required parity bits dynamically and can be adapted to different Hamming configurations.

## Files

- `main.cpp`: Contains the implementation of dynamic Hamming code encoding and decoding.

## Key Functions

### `calculateParityBits`

Calculates the number of parity bits required for a given total number of bits.

**Parameters:**
- `totalBits`: Total number of bits (including data and parity bits).

**Returns:** Number of parity bits.

### `calculateParityBit`

Calculates the parity bit for a given set of positions in the code.

**Parameters:**
- `bits`: Vector containing the code bits.
- `positions`: Vector of positions covered by the parity bit.

**Returns:** The calculated parity bit.

### `encodeHamming`

Encodes data bits into a Hamming code.

**Parameters:**
- `data`: Vector of bits to be encoded.
- `totalBits`: Total number of bits in the encoded code (data + parity bits).

**Returns:** Vector of encoded bits.

### `decodeHamming`

Decodes a Hamming code, detects and corrects any single-bit errors.

**Parameters:**
- `code`: Vector of bits to be decoded.
- `totalBits`: Total number of bits in the code (data + parity bits).

**Returns:** Vector of decoded data bits.

## Usage

1. **Compile the code:**
```bash
   g++ -o hamming main.cpp
```