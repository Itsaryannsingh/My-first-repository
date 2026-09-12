#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string currentWord = "";
    string longestWord = "";

    for (int i = 0; i <= sentence.length(); i++) {

        if (i == sentence.length() || sentence[i] == ' ') {

            if (currentWord.length() > longestWord.length()) {
                longestWord = currentWord;
            }

            currentWord = "";
        }
        else {
            currentWord += sentence[i];
        }
    }

    if (longestWord.empty()) {
        cout << "\nNo word found." << endl;
    }
    else {
        cout << "\nLongest Word: " << longestWord << endl;
        cout << "Length: " << longestWord.length() << endl;
    }

    return 0;
}
