#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;

    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Binary representation: ";

    int temp = n;

    if (temp == 0)
    {
        cout << "0";
    }
    else
    {
        int binary[32];
        int index = 0;

        while (temp > 0)
        {
            binary[index] = temp % 2;
            temp /= 2;
            index++;
        }

        for (int i = index - 1; i >= 0; i--)
        {
            cout << binary[i];
        }
    }

    cout << endl;

    cout << "Number of set bits = "
         << countSetBits(n) << endl;

    return 0;
}
