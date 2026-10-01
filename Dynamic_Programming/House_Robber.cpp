#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& money)
{
    int n = money.size();

    if (n == 0)
        return 0;

    if (n == 1)
        return money[0];

    vector<int> dp(n);

    dp[0] = money[0];

    dp[1] = max(money[0], money[1]);

    for (int i = 2; i < n; i++)
    {
        int robCurrent = money[i] + dp[i - 2];

        int skipCurrent = dp[i - 1];

        dp[i] = max(robCurrent, skipCurrent);
    }

    return dp[n - 1];
}

int main()
{
    int n;

    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> money(n);

    cout << "Enter money in each house:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> money[i];
    }

    int result = rob(money);

    cout << "\nMaximum money that can be robbed = "
         << result << endl;

    return 0;
}
