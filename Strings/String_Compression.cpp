#include <iostream>
#include <string>
using namespace std;

int main() {

    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    if (str.empty()) {
        cout << "String is empty." << endl;
        return 0;
    }

    cout << "\nCompressed String: ";

    int count = 1;

    for (int i = 0; i < str.length(); i++) {

        if (i + 1 < str.length() && str[i] == str[i + 1]) {
            count++;
        }
        else {
            cout << str[i] << count;
            count = 1;
        }
    }

    cout << endl;

    return 0;
}
