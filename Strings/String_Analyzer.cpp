#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str;

    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int uppercase = 0;
    int lowercase = 0;

    cout << "Enter a string: ";
    getline(cin, str);

    for (char ch : str) {

        if (isdigit(ch)) {
            digits++;
        }
        else if (isspace(ch)) {
            spaces++;
        }
        else if (isalpha(ch)) {

            if (isupper(ch)) {
                uppercase++;
            }
            else if (islower(ch)) {
                lowercase++;
            }

            char lower = tolower(ch);

            if (lower == 'a' || lower == 'e' ||
                lower == 'i' || lower == 'o' ||
                lower == 'u') {
                vowels++;
            }
            else {
                consonants++;
            }
        }
    }

    cout << "\n----- String Analysis -----" << endl;
    cout << "Total Characters : " << str.length() << endl;
    cout << "Vowels            : " << vowels << endl;
    cout << "Consonants        : " << consonants << endl;
    cout << "Digits            : " << digits << endl;
    cout << "Spaces            : " << spaces << endl;
    cout << "Uppercase         : " << uppercase << endl;
    cout << "Lowercase         : " << lowercase << endl;

    return 0;
}
