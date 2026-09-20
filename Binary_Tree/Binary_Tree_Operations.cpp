#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Create Binary Tree
Node* createTree()
{
    int value;

    cout << "Enter value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return nullptr;

    Node* root = new Node(value);

    cout << "Enter left child of " << value << endl;
    root->left = createTree();

    cout << "Enter right child of " << value << endl;
    root->right = createTree();

    return root;
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root)
{
    if (root == nullptr)
        return;

    postorder(root->left);

    postorder(root->right);

    cout << root->data << " ";
}

// Search Element
bool searchElement(Node* root, int key)
{
    if (root == nullptr)
        return false;

    if (root->data == key)
        return true;

    return searchElement(root->left, key) ||
           searchElement(root->right, key);
}

// Count Total Nodes
int countNodes(Node* root)
{
    if (root == nullptr)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

// Find Height
int height(Node* root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// Main Function
int main()
{
    Node* root = nullptr;

    int choice;

    cout << "===== BINARY TREE CREATION =====\n";

    root = createTree();

    do
    {
        cout << "\n===== BINARY TREE OPERATIONS =====\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Search Element\n";
        cout << "5. Count Total Nodes\n";
        cout << "6. Find Height\n";
        cout << "7. Display All Traversals\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 2:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;

        case 4:
        {
            int key;

            cout << "Enter element to search: ";
            cin >> key;

            if (searchElement(root, key))
                cout << key << " found in the tree.\n";
            else
                cout << key << " not found in the tree.\n";

            break;
        }

        case 5:
            cout << "Total Nodes: "
                 << countNodes(root) << endl;
            break;

        case 6:
            cout << "Height of Tree: "
                 << height(root) << endl;
            break;

        case 7:
            cout << "\nInorder: ";
            inorder(root);

            cout << "\nPreorder: ";
            preorder(root);

            cout << "\nPostorder: ";
            postorder(root);

            cout << endl;
            break;

        case 8:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}
