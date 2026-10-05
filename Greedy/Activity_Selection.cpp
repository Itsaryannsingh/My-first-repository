#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity
{
    int start;
    int end;
};

bool compare(Activity a, Activity b)
{
    return a.end < b.end;
}

int main()
{
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter start and end time:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> activities[i].start
            >> activities[i].end;
    }

    // Sort activities by finishing time
    sort(activities.begin(), activities.end(), compare);

    cout << "\nSelected activities:\n";

    int count = 0;
    int lastEnd = -1;

    for (int i = 0; i < n; i++)
    {
        if (activities[i].start >= lastEnd)
        {
            cout << "("
                 << activities[i].start
                 << ", "
                 << activities[i].end
                 << ") ";

            lastEnd = activities[i].end;
            count++;
        }
    }

    cout << "\n\nMaximum activities = "
         << count << endl;

    return 0;
}
