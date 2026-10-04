#include <iostream>
using namespace std;

int findUnique(int arr[], int n)
{
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        result = result ^ arr[i];
    }

    return result;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int uniqueElement = findUnique(arr, n);

    cout << "\nUnique element = "
         << uniqueElement << endl;

    return 0;
}
