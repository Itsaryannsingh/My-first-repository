#include <iostream>
using namespace std;

int searchRotatedArray(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // Target found
        if (arr[mid] == target) {
            return mid;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {

            // Check if target lies in left sorted half
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Right half is sorted
        else {

            // Check if target lies in right sorted half
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}


int main() {

    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    int target;

    cout << "Enter target element: ";
    cin >> target;

    int result = searchRotatedArray(arr, n, target);

    if (result == -1) {
        cout << "\nElement not found." << endl;
    }
    else {
        cout << "\nElement found at index: " << result << endl;
    }

    return 0;
}
