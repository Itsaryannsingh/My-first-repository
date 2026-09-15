#include <iostream>
using namespace std;

int findPeakElement(int arr[], int n) {

    int low = 0;
    int high = n - 1;

    while (low < high) {

        int mid = low + (high - low) / 2;

        // We are moving towards a higher element
        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        }

        // Peak is at mid or on the left side
        else {
            high = mid;
        }
    }

    return low;
}

int main() {

    int arr[] = {1, 3, 5, 7, 6, 4, 2};
    int n = 7;

    int peakIndex = findPeakElement(arr, n);

    cout << "Peak Element: " << arr[peakIndex] << endl;
    cout << "Peak Index: " << peakIndex << endl;

    return 0;
}
