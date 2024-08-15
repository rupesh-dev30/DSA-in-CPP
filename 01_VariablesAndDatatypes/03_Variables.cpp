#include <iostream>
using namespace std;

int main() {
    // Initializing various data types
    int myInt = 42;
    float myFloat = 3.14f;
    double myDouble = 2.71828;
    char myChar = 'A';
    bool myBool = true;
    long myLong = 1234567890;
    short myShort = 32767;
    unsigned int myUnsignedInt = 40000;
    long long myLongLong = 9223372036854775807;
    unsigned long long myUnsignedLongLong = 18446744073709551615ULL;
    
    // Output the values
    cout << "int: " << myInt << endl;
    cout << "float: " << myFloat << endl;
    cout << "double: " << myDouble << endl;
    cout << "char: " << myChar << endl;
    cout << "bool: " << (myBool ? "true" : "false") << endl;
    cout << "long: " << myLong << endl;
    cout << "short: " << myShort << endl;
    cout << "unsigned int: " << myUnsignedInt << endl;
    cout << "long long: " << myLongLong << endl;
    cout << "unsigned long long: " << myUnsignedLongLong << endl;

    return 0;
}
