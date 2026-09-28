#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;

        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode* root;

    void displayWords(TrieNode* node, string current)
    {
        if (node->isEndOfWord)
        {
            cout << current << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != nullptr)
            {
                displayWords(
                    node->children[i],
                    current + char('a' + i)
                );
            }
        }
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* current = root;

        for (char ch : word)
        {
            int index = ch - 'a';

            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->isEndOfWord = true;

        cout << "Word inserted successfully.\n";
    }

    bool search(string word)
    {
        TrieNode* current = root;

        for (char ch : word)
        {
            int index = ch - 'a';

            if (current->children[index] == nullptr)
            {
                return false;
            }

            current = current->children[index];
        }

        return current->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode* current = root;

        for (char ch : prefix)
        {
            int index = ch - 'a';

            if (current->children[index] == nullptr)
            {
                return false;
            }

            current = current->children[index];
        }

        return true;
    }

    void display()
    {
        cout << "\n===== WORDS IN TRIE =====\n";
        displayWords(root, "");
    }
};

int main()
{
    Trie trie;

    int choice;

    do
    {
        cout << "\n===== TRIE DICTIONARY =====\n";
        cout << "1. Insert Word\n";
        cout << "2. Search Word\n";
        cout << "3. Search Prefix\n";
        cout << "4. Display Words\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string word;

            cout << "Enter word: ";
            cin >> word;

            trie.insert(word);
            break;
        }

        case 2:
        {
            string word;

            cout << "Enter word to search: ";
            cin >> word;

            if (trie.search(word))
                cout << "Word found!\n";
            else
                cout << "Word not found.\n";

            break;
        }

        case 3:
        {
            string prefix;

            cout << "Enter prefix: ";
            cin >> prefix;

            if (trie.startsWith(prefix))
                cout << "Prefix exists!\n";
            else
                cout << "Prefix not found.\n";

            break;
        }

        case 4:
            trie.display();
            break;

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
