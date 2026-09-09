#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    int index;
    char target;

    // Input strings
    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    // 1. Access
    cout << "\nEnter index to access: ";
    cin >> index;

    if (index >= 0 && index < str1.length()) {
        cout << "Character at index " << index << ": "
             << str1[index] << endl;
    } else {
        cout << "Invalid index." << endl;
    }

    // 2. Search
    cout << "\nEnter character to search: ";
    cin >> target;

    bool found = false;

    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == target) {
            cout << "Character found at index: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Character not found." << endl;
    }

    // 3. Modify
    if (str1.length() > 0) {
        str1[0] = 'Y';
        cout << "\nAfter modifying first character: "
             << str1 << endl;
    }

    // 4. Compare
    if (str1 == str2) {
        cout << "Both strings are equal." << endl;
    } else {
        cout << "Both strings are different." << endl;
    }

    return 0;
}
