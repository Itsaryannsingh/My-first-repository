#include <iostream>
using namespace std;

// 1. Factorial using Recursion
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

// 2. Fibonacci using Recursion
int fibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. Sum of first N natural numbers
int sumNatural(int n)
{
    if (n == 0)
        return 0;

    return n + sumNatural(n - 1);
}

// 4. Power of a number
int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;

    return base * power(base, exponent - 1);
}

// 5. Reverse a number
int reverseNumber(int n, int reversed = 0)
{
    if (n == 0)
        return reversed;

    int digit = n % 10;

    return reverseNumber(n / 10, reversed * 10 + digit);
}

// 6. GCD using Recursion
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== RECURSION PROBLEMS =====\n";
        cout << "1. Factorial\n";
        cout << "2. Fibonacci\n";
        cout << "3. Sum of N Natural Numbers\n";
        cout << "4. Power of a Number\n";
        cout << "5. Reverse a Number\n";
        cout << "6. GCD\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Enter number: ";
            cin >> n;

            cout << "Factorial = " << factorial(n) << endl;
            break;
        }

        case 2:
        {
            int n;
            cout << "Enter position: ";
            cin >> n;

            cout << "Fibonacci = " << fibonacci(n) << endl;
            break;
        }

        case 3:
        {
            int n;
            cout << "Enter N: ";
            cin >> n;

            cout << "Sum = " << sumNatural(n) << endl;
            break;
        }

        case 4:
        {
            int base, exponent;

            cout << "Enter base: ";
            cin >> base;

            cout << "Enter exponent: ";
            cin >> exponent;

            cout << "Result = " << power(base, exponent) << endl;
            break;
        }

        case 5:
        {
            int n;
            cout << "Enter number: ";
            cin >> n;

            cout << "Reversed Number = "
                 << reverseNumber(n) << endl;

            break;
        }

        case 6:
        {
            int a, b;

            cout << "Enter two numbers: ";
            cin >> a >> b;

            cout << "GCD = " << gcd(a, b) << endl;
            break;
        }

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
