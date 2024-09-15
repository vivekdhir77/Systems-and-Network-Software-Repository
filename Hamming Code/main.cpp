#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int calculateParityBits(int totalBits) { // Function to calculate the number of parity bits needed
    int r = 0;
    while ((1 << r) < (totalBits + 1)) {
        ++r;
    }
    return r;
}


int calculateParityBit(const vector<int>& bits, const vector<int>& positions) {
    int parity = 0;
    for (size_t i = 0; i < positions.size(); ++i) {
        parity ^= bits[positions[i] - 1];
    }
    return parity;
}

vector<int> encodeHamming(const vector<int>& data, int totalBits) {
    int dataBits = data.size();
    int r = calculateParityBits(totalBits);

    if (dataBits != (totalBits - r)) {
        throw invalid_argument("Data size does not match with total bits and parity bits.");
    }

    vector<int> code(totalBits, 0);
    vector<int> parityBitsPos;

    
    for (int i = 1; i <= totalBits; i <<= 1) { // Identify positions for parity bits
        parityBitsPos.push_back(i);
    }

    
    int dataIndex = 0;
    for (int i = 0; i < totalBits; ++i) { // Place data bits into their positions in the code
        bool isParityBit = false;
        for (size_t j = 0; j < parityBitsPos.size(); ++j) {
            if (parityBitsPos[j] == i + 1) {
                isParityBit = true;
                break;
            }
        }
        if (!isParityBit) {
            code[i] = data[dataIndex++];
        }
    }

    // Calculate parity bits
    for (size_t i = 0; i < parityBitsPos.size(); ++i) {
        vector<int> positions;
        for (int j = parityBitsPos[i] - 1; j < totalBits; j += 2 * parityBitsPos[i]) {
            for (int k = j; k < min(j + parityBitsPos[i], totalBits); ++k) {
                positions.push_back(k + 1);
            }
        }
        code[parityBitsPos[i] - 1] = calculateParityBit(code, positions);
    }

    return code;
}

vector<int> decodeHamming(const vector<int>& code, int totalBits) {
    int r = calculateParityBits(totalBits);

    if (code.size() != totalBits) {
        throw invalid_argument("Code size does not match with total bits.");
    }

    vector<int> parityBitsPos;

    // Identify positions for parity bits
    for (int i = 1; i <= totalBits; i <<= 1) {
        parityBitsPos.push_back(i);
    }

    // Calculate parity bits
    int errorPos = 0;
    for (size_t i = 0; i < parityBitsPos.size(); ++i) {
        vector<int> positions;
        for (int j = parityBitsPos[i] - 1; j < totalBits; j += 2 * parityBitsPos[i]) {
            for (int k = j; k < min(j + parityBitsPos[i], totalBits); ++k) {
                positions.push_back(k + 1);
            }
        }
        if (calculateParityBit(code, positions) != code[parityBitsPos[i] - 1]) {
            errorPos += parityBitsPos[i];
        }
    }

    if (errorPos != 0) {
        cout << "Error detected at position: " << errorPos << endl;
        vector<int> correctedCode = code;
        correctedCode[errorPos - 1] ^= 1;
        return correctedCode;
    }


    vector<int> data(totalBits - r);
    int dataIndex = 0;
    for (int i = 0; i < totalBits; ++i) {
        bool isParityBit = false;
        for (size_t j = 0; j < parityBitsPos.size(); ++j) {
            if (parityBitsPos[j] == i + 1) {
                isParityBit = true;
                break;
            }
        }
        if (!isParityBit) {
            data[dataIndex++] = code[i];
        }
    }

    return data;
}

int main() {
    int dataBits = 4;
    int totalBits = 7; 

    vector<int> data(4);
    data[0] = 1;
    data[1] = 0;
    data[2] = 1;
    data[3] = 1;

    vector<int> encoded = encodeHamming(data, totalBits);
    cout << "Encoded: ";
    for (size_t i = 0; i < encoded.size(); ++i) {
        cout << encoded[i] << " ";
    }
    cout << endl;

    encoded[2] ^= 1;

    vector<int> decoded = decodeHamming(encoded, totalBits);
    cout << "Decoded: ";
    for (size_t i = 0; i < decoded.size(); ++i) {
        cout << decoded[i] << " ";
    }
    cout << endl;

    return 0;
}
