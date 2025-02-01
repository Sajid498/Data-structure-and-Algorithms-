//knapsack
#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int item_number;
    double weight;
    double value;
    double value_weight_ratio;
};
typedef struct Item Item;

bool compare(Item &left, Item &right)
{
    if(left.value_weight_ratio>right.value_weight_ratio)
        return true;
    else return false;
}


double fractional_knapsack(Item items[], int n, int capacity)
{
    /// step 1: Find the value-weight ratio for each item

    for(int i=0; i<n; i++)
    {
        items[i].value_weight_ratio = items[i].value/items[i].weight;
    }

    /// step 2: Sort the items based on value-weight ratio (descending order)
    sort(items, items+n, compare);

    /// step 3: Start picking the items based on the sequence of step 2 until you have the capacity

    double profit = 0;

    cout << "Picked Items: ";
    for(int i=0; i<n; i++)
    {
        if(capacity>=items[i].weight)
        {
            capacity -= items[i].weight;
            profit += items[i].value;



            cout << items[i].item_number << " ";
        }
        else
        {
            profit += (capacity * items[i].value_weight_ratio);

            capacity = 0;

            cout << items[i].item_number << "(F) ";
        }


        if(capacity==0)
            break;
    }
    cout << endl;
    return profit;
}

int main()
{

    int n = 6;
    Item items[n] = {
        {1, 10, 60, 0},
        {2, 20, 100, 0},
        {3, 30, 120, 0},
        {4, 40, 80, 0},
        {5, 50, 90, 0},
        {6, 60, 150, 0}
    };
    int capacity = 50;


    double result = fractional_knapsack(items, n, capacity);
    cout << "Total Profit: " << result << endl;

    return 0;
}
