#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>

using namespace std;

// Перевод из десятичной в двоичную систему счисления
string DecToBin(int digit) {
    if (digit == 0) return 0;
    return bitset<32>(digit).to_string();
}


string DecToBinWithoutLibs(int digit) {
    if (digit == 0) return 0;

    string bin = "";

    while (digit > 0) {;
        bin.push_back('0' + (digit % 2));
        digit /= 2;
    }
    reverse(bin.begin(), bin.end());

    return bin;
}

int BinToDec(string& binary) {
    int decimal = 0;
    for (char ch : binary) {
        decimal *= 2;
        if (ch == '1') {
            decimal += 1;
        }
    }
    return decimal;
}

string DecToHexWithoutLibs(int digit) {
    if (digit == 0) return 0;

    string hex = "";

    while (digit > 0) {
        int remainder = digit % 16;
        char hexChar;

        if (remainder < 10) {
            hexChar = '0' + remainder;
        }
        else {
            hexChar = 'A' + (remainder - 10);
        }
        hex.push_back(hexChar);

        digit /= 16;

    }

    reverse(hex.begin(), hex.end());
    return hex;
}

int HexToDecWithoutLibs(string & hex) {

    int decimal = 0;



    for (char ch : hex) {
        decimal *= 16;
        if (ch >= '0' && ch <='9') {
            decimal += (ch - '0');
        }
        else if (ch >= 'A' && ch <= 'F') {
            decimal += (ch - 'A' + 10);
        }
        else if (ch >= 'a' && ch <= 'f') {
            decimal += (ch - 'a' + 10);
        }
    }

    return decimal;
}

int main()
{
    string binary = DecToBinWithoutLibs(454);
    string binary1 = DecToBin(454);

    cout << binary << " " << binary1 << endl;


    string hex = DecToHexWithoutLibs(455);

    cout << hex << endl;

    int dec = BinToDec(binary);
    cout << dec << endl;

    int hexD = HexToDecWithoutLibs(hex);
    cout << dec << endl;

    char r = 'Р';

    unsigned char buff[]{ 185,95,231 };
    int temperature = (int)buff[0];

    int temp = (buff[1] & 120) >> 4;
    temperature <<= 4;
    temperature |= temp;

    cout << temperature << endl;

    int humidity = (int)buff[2];
    temp = (buff[1] & 15) << 8;
    humidity |= temp;

    unsigned short port = (short)buff[0];
    port <<= 8;
    port |= (short)buff[1];
    
    cout << port << endl;


}
