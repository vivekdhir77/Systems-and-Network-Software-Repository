#include <iostream>
#include <vector>
#include <string>

using namespace std;


string xorOperation(string a, string b) {
    string result = "";
    for (int i = 1; i < b.length(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}


string division(string dividend, string divisor) {
    int n = divisor.length();
    string temp = dividend.substr(0, n);
    
    while (n < dividend.length()) {
        if (temp[0] == '1') {
            temp = xorOperation(temp, divisor) + dividend[n];
        } else {
            temp = xorOperation(temp, string(n, '0')) + dividend[n];
        }
        n++;
    }
    
    if (temp[0] == '1') {
        temp = xorOperation(temp, divisor);
    } else {
        temp = xorOperation(temp, string(n, '0'));
    }
    
    return temp;
}

string calculateCRC(string data, string divisor) {
    int dataBits = data.length();
    int divisorBits = divisor.length();
    
    string appendedData = data + string(divisorBits - 1, '0');
    
    string remainder = division(appendedData, divisor);
    
    return remainder;
}

int main() {
    int dataBits, divisorBits;
    string data, divisor;
    
    cout << "Enter the number of bits in input data: ";
    cin >> dataBits;
    cout << "Enter the number of bits in the polynomial generator (divisor): ";
    cin >> divisorBits;
    cout << "Enter the data: ";
    cin >> data;
    cout << "Enter the divisor: ";
    cin >> divisor;
    
    string crc = calculateCRC(data, divisor);
    cout << "CRC value: " << crc << endl;
    
    string transmittedData = data + crc;
    cout << "Transmitted data: " << transmittedData << endl;
    
    string receivedData;
    cout << "Enter the received data: ";
    cin >> receivedData;
    
    string checkRemainder = division(receivedData, divisor);
    bool errorDetected = false;
    
    for (char bit : checkRemainder) {
        if (bit == '1') {
            errorDetected = true;
            break;
        }
    }
    
    if (errorDetected) {
        cout << "Errors detected" << endl;
    } else {
        cout << "No errors detected" << endl;
    }

    return 0;
}
