#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LCS(string a, string b)
{
    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string a, b;

    cout << "Enter first string: ";
    cin >> a;

    cout << "Enter second string: ";
    cin >> b;

    int result = LCS(a, b);

    cout << "\nLength of Longest Common Subsequence = "
         << result << endl;

    return 0;
}
