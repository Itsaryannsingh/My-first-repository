#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int marks[n];

    cout << "\nEnter marks of each student:\n";

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    int total = 0;
    int highest = marks[0];
    int lowest = marks[0];
    int pass = 0;
    int fail = 0;

    for (int i = 0; i < n; i++) {
        total += marks[i];

        if (marks[i] > highest)
            highest = marks[i];

        if (marks[i] < lowest)
            lowest = marks[i];

        if (marks[i] >= 40)
            pass++;
        else
            fail++;
    }

    double average = (double) total / n;

    cout << "\n========== STUDENT MARKS ANALYZER ==========\n";
    cout << "Total Marks : " << total << endl;
    cout << "Average     : " << average << endl;
    cout << "Highest     : " << highest << endl;
    cout << "Lowest      : " << lowest << endl;
    cout << "Passed      : " << pass << endl;
    cout << "Failed      : " << fail << endl;
    cout << "============================================\n";

    return 0;
}
