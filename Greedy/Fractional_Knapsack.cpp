#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int value;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double fractionalKnapsack(
    vector<Item>& items,
    int capacity)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (int i = 0; i < items.size(); i++)
    {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity)
        {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            double fraction =
                (double)capacity / items[i].weight;

            totalValue += items[i].value * fraction;

            capacity = 0;
        }
    }

    return totalValue;
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter weight and value of each item:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight
            >> items[i].value;

        items[i].ratio =
            (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    double result =
        fractionalKnapsack(items, capacity);

    cout << "\nMaximum value = "
         << result << endl;

    return 0;
}
