#include<iostream>
using namespace std;
int sum_printSubarray(int arr[], int left, int right)
{
    int sum = 0;

    for(int i=left; i<=right; i++)
    {
        sum += arr[i];
        printf("%d ", arr[i]);
    }
    printf("; Summation: %d; Indices: (%d, %d)\n", sum, left, right);

    return sum;
}
int main()
{
    int n = 5;
    int arr[n] = {-3, 5, 6, -8, 7};

    int maximum_sum = - INT_MAX;

    int left_index;
    int right_index;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            // printf("%d %d\n", i, j);
            int result = sum_printSubarray(arr, i, j);

            if(result>maximum_sum)
            {
                maximum_sum = result;
                left_index = i;
                right_index = j;
            }
        }
    }


    printf("\n\nMaximum Sum: %d; Indices: (%d, %d)\n", maximum_sum, left_index, right_index);

    return 0;
}
