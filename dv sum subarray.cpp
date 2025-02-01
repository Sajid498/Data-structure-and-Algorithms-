#include<iostream>
using namespace std;
struct Result
{
    int summation;
    int left_index;
    int right_index;
};
typedef struct Result Result;

Result crossing_sum(int arr[], int low, int mid, int high)
{
    /// left sum
    int sum = 0;
    int Lsum = - INT_MAX;
    int left_idx;

    for(int i=mid; i>=low; i--)
    {
        sum += arr[i];
        if(sum>Lsum)
        {
            Lsum = sum;
            left_idx = i;
        }
    }


    /// right sum
    sum = 0;
    int Rsum = - INT_MAX;
    int right_idx;

    for(int i=mid+1; i<=high; i++)
    {
        sum += arr[i];
        if(sum>Rsum)
        {
            Rsum = sum;
            right_idx = i;
        }
    }

    return {Lsum+Rsum, left_idx, right_idx};
}

Result maximum_sum_subarray(int arr[], int low, int high)
{
    if(low==high)
    {
        return {arr[low], low, low};
    }
    else
    {
        int mid = (low+high)/2;
        Result left_answer = maximum_sum_subarray(arr, low, mid);
        Result right_answer = maximum_sum_subarray(arr, mid+1, high);
        Result crossing_answer = crossing_sum(arr, low, mid, high);

        if(left_answer.summation>=right_answer.summation && left_answer.summation>=crossing_answer.summation)
        {
            return left_answer;
        }
        else if(right_answer.summation>=left_answer.summation && right_answer.summation>=crossing_answer.summation)
        {
            return right_answer;
        }
        else
        {
            return crossing_answer;
        }
    }
}
int main()
{
    int n = 8;
    int arr[n] = {-2, -5, 6, -2, -3, 1, 5, -6};

    Result maximum_subarray_sum = maximum_sum_subarray(arr, 0, n-1);


    printf("Summation: %d; Indices: (%d, %d)\n", maximum_subarray_sum.summation, maximum_subarray_sum.left_index, maximum_subarray_sum.right_index);


    for(int i=maximum_subarray_sum.left_index; i<=maximum_subarray_sum.right_index; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}
