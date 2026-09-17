```cpp
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Display the stack
void display(int stack[], int top)
{
    if (top == -1)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "\nStack (Top to Bottom):\n";

    for (int i = top; i >= 0; i--)
    {
        cout << "| " << stack[i] << " |\n";
    }

    cout << "-------\n";
}

// Push an element
int push(int stack[], int top, int value)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "Stack Overflow! Stack is full.\n";
        return top;
    }

    top++;
    stack[top] = value;

    cout << value << " pushed into the stack.\n";

    return top;
}

// Pop an element
int pop(int stack[], int top)
{
    if (top == -1)
    {
        cout << "Stack Underflow! Stack is empty.\n";
        return top;
    }

    cout << stack[top] << " removed from the stack.\n";

    top--;

    return top;
}

// Peek the top element
void peek(int stack[], int top)
{
    if (top == -1)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top element: " << stack[top] << endl;
}

// Search an element
void searchElement(int stack[], int top, int value)
{
    if (top == -1)
    {
        cout << "Stack is empty.\n";
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        if (stack[i] == value)
        {
            cout << value << " found in the stack.\n";
            return;
        }
    }

    cout << value << " not found in the stack.\n";
}

int main()
{
    int stack[MAX_SIZE];
    int top = -1;

    int choice;
    int value;

    cout << "====================================\n";
    cout << "      STACK MANAGEMENT SYSTEM\n";
    cout << "====================================\n";

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Search\n";
        cout << "5. Display\n";
        cout << "6. Check Empty\n";
        cout << "7. Check Full\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;

                top = push(stack, top, value);
                break;

            case 2:
                top = pop(stack, top);
                break;

            case 3:
                peek(stack, top);
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;

                searchElement(stack, top, value);
                break;

            case 5:
                display(stack, top);
                break;

            case 6:
                if (top == -1)
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;

            case 7:
                if (top == MAX_SIZE - 1)
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                break;

            case 8:
                cout << "Program exited successfully.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
```
