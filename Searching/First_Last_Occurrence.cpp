#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;
    int answer = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            answer = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return answer;
}


int lastOccurrence(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;
    int answer = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            answer = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return answer;
}


int main() {

    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = 7;

    int target;

    cout << "Enter target element: ";
    cin >> target;

    int first = firstOccurrence(arr, n, target);
    int last = lastOccurrence(arr, n, target);

    if (first == -1) {
        cout << "\nElement not found." << endl;
    }
    else {
        cout << "\nFirst Occurrence: " << first << endl;
        cout << "Last Occurrence: " << last << endl;
    }

    return 0;
}
