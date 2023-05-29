#include <iostream>
#include <stack>
using namespace std;

string convertToBinary(int decimal) {
    if (decimal == 0) {
        return "0";
    }

    stack<int> binaryDigits;
    while (decimal > 0) {
        binaryDigits.push(decimal % 2);
        decimal /= 2;
    }

    string binary = "";
    while (!binaryDigits.empty()) {
        binary += to_string(binaryDigits.top());
        binaryDigits.pop();
    }

    return binary;
}

int main() {
    int decimal;
    cin >> decimal;

    string binary = convertToBinary(decimal);

    cout  << binary << endl;

    return 0;
}
