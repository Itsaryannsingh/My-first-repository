#include <iostream>
#include <string>
using namespace std;

int main() {

    string str;
    int frequency[256] = {0};

    cout << "Enter a string: ";
    getline(cin, str);

    // Count frequency of each character
    for (char ch : str) {
        frequency[(unsigned char)ch]++;
    }

    cout << "\n----- Character Frequency -----" << endl;

    // Display characters and their frequency
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            cout << "'" << (char)i << "' -> "
                 << frequency[i] << endl;
        }
    }

    return 0;
}
