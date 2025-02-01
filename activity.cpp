//activity
#include<bits/stdc++.h>
using namespace std;

struct Activity
{
    string activity_name;
    int start_time;
    int finish_time;
};

typedef struct Activity Activity;

bool compare(Activity &left, Activity &right)
{
    if(left.finish_time<=right.finish_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n = 10;
    Activity activities[n] = {
        {"A1", 1, 10},
        {"A2", 2, 4},
        {"A3", 3, 6},
        {"A4", 5, 8},
        {"A5", 7, 9},
        {"A6", 9, 11},
        {"A7", 10, 11},
        {"A8", 11, 13},
        {"A9", 6, 7},
        {"A10", 4, 5},
    };

    /// step 1 : Sort the activities based on Finish Time
    sort(activities, activities+n, compare);

    cout << activities[0].activity_name << " ";
    cout << "   Available: " << activities[0].finish_time << endl;

    int available_time = activities[0].finish_time;
    for(int i=1; i<n; i++)
    {
        if(activities[i].start_time>=available_time)
        {
            cout << activities[i].activity_name << " ";
            cout << "   Available: " << activities[i].finish_time << endl;

            available_time = activities[i].finish_time;
        }
    }

}
