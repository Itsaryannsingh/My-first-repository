#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs)
{
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;

    for (Job job : jobs)
    {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<char> schedule(maxDeadline + 1, '-');
    vector<bool> slot(maxDeadline + 1, false);

    int totalProfit = 0;

    for (Job job : jobs)
    {
        for (int time = job.deadline; time >= 1; time--)
        {
            if (!slot[time])
            {
                slot[time] = true;
                schedule[time] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "\nJob Schedule: ";

    for (int i = 1; i <= maxDeadline; i++)
    {
        if (schedule[i] != '-')
            cout << schedule[i] << " ";
    }

    cout << "\nMaximum Profit = "
         << totalProfit << endl;
}

int main()
{
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter Job ID, Deadline and Profit:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;
    }

    jobSequencing(jobs);

    return 0;
}
