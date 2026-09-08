#include <bits/stdc++.h>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int target = 30;

    int linearResult = linearSearch(arr, n, target);
    int binaryResult = binarySearch(arr, n, target);

    cout << "Linear Search: ";
    if (linearResult != -1)
        cout << "Element found at index " << linearResult << endl;
    else
        cout << "Element not found" << endl;

    cout << "Binary Search: ";
    if (binaryResult != -1)
        cout << "Element found at index " << binaryResult << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
