#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Display Heap
void displayHeap(int heap[], int size)
{
    if (size == 0)
    {
        cout << "Heap is empty.\n";
        return;
    }

    cout << "Heap: ";

    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }

    cout << endl;
}

// Insert Element
void insertElement(int heap[], int& size, int value)
{
    if (size == MAX_SIZE)
    {
        cout << "Heap is full.\n";
        return;
    }

    int index = size;

    heap[index] = value;
    size++;

    // Move element upward
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap[parent] >= heap[index])
            break;

        swap(heap[parent], heap[index]);

        index = parent;
    }

    cout << value << " inserted successfully.\n";
}

// Get Maximum
void getMaximum(int heap[], int size)
{
    if (size == 0)
    {
        cout << "Heap is empty.\n";
        return;
    }

    cout << "Maximum Element: " << heap[0] << endl;
}

// Delete Maximum Element
void deleteMaximum(int heap[], int& size)
{
    if (size == 0)
    {
        cout << "Heap is empty.\n";
        return;
    }

    int deletedValue = heap[0];

    heap[0] = heap[size - 1];
    size--;

    // Heapify Down
    int index = 0;

    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int largest = index;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == index)
            break;

        swap(heap[index], heap[largest]);

        index = largest;
    }

    cout << "Deleted Maximum Element: "
         << deletedValue << endl;
}

// Heapify
void heapify(int heap[], int size, int index)
{
    int largest = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index)
    {
        swap(heap[index], heap[largest]);

        heapify(heap, size, largest);
    }
}

// Build Max Heap
void buildMaxHeap(int heap[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(heap, size, i);
    }

    cout << "Max Heap built successfully.\n";
}

// Heap Sort
void heapSort(int heap[], int size)
{
    buildMaxHeap(heap, size);

    for (int i = size - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);

        heapify(heap, i, 0);
    }
}

// Main Function
int main()
{
    int heap[MAX_SIZE];
    int size = 0;

    int choice;

    do
    {
        cout << "\n===== MAX HEAP OPERATIONS =====\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Maximum\n";
        cout << "3. Get Maximum\n";
        cout << "4. Display Heap\n";
        cout << "5. Build Max Heap\n";
        cout << "6. Heap Sort\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;

            cout << "Enter value: ";
            cin >> value;

            insertElement(heap, size, value);

            break;
        }

        case 2:
            deleteMaximum(heap, size);
            break;

        case 3:
            getMaximum(heap, size);
            break;

        case 4:
            displayHeap(heap, size);
            break;

        case 5:
            buildMaxHeap(heap, size);
            break;

        case 6:
            heapSort(heap, size);

            cout << "Sorted Array: ";

            for (int i = 0; i < size; i++)
            {
                cout << heap[i] << " ";
            }

            cout << endl;
            break;

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
