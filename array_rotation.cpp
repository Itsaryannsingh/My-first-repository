#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int rotations = 2;

    for (int r = 0; r < rotations; r++) {

        int temp = arr[n - 1];

        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = temp;
    }

    cout << "Array after right rotation: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
