#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

bool isEmpty(int front, int rear)
{
    return front == -1 || front > rear;
}

bool isFull(int rear)
{
    return rear == MAX_SIZE - 1;
}

void enqueue(int queue[], int& front, int& rear, int value)
{
    if (isFull(rear))
    {
        cout << "Queue Overflow! Queue is full.\n";
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = value;

    cout << value << " added to the queue.\n";
}

void dequeue(int queue[], int& front, int& rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }

    cout << queue[front] << " removed from the queue.\n";

    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void showFront(int queue[], int front, int rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Front element: " << queue[front] << endl;
}

void showRear(int queue[], int front, int rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Rear element: " << queue[rear] << endl;
}

void searchElement(int queue[], int front, int rear, int value)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue is empty.\n";
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        if (queue[i] == value)
        {
            cout << value << " found at position "
                 << (i - front + 1) << ".\n";
            return;
        }
    }

    cout << value << " not found in the queue.\n";
}

void display(int queue[], int front, int rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "\nQueue (Front to Rear):\n";

    for (int i = front; i <= rear; i++)
    {
        cout << "| " << queue[i] << " |";
    }

    cout << "\n";
}

int main()
{
    int queue[MAX_SIZE];

    int front = -1;
    int rear = -1;

    int choice;
    int value;

    cout << "=====================================\n";
    cout << "       QUEUE MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Show Front\n";
        cout << "4. Show Rear\n";
        cout << "5. Search\n";
        cout << "6. Display Queue\n";
        cout << "7. Check Empty\n";
        cout << "8. Check Full\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(queue, front, rear, value);
                break;

            case 2:
                dequeue(queue, front, rear);
                break;

            case 3:
                showFront(queue, front, rear);
                break;

            case 4:
                showRear(queue, front, rear);
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                searchElement(queue, front, rear, value);
                break;

            case 6:
                display(queue, front, rear);
                break;

            case 7:
                if (isEmpty(front, rear))
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;

            case 8:
                if (isFull(rear))
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;

            case 9:
                cout << "Program exited successfully.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
