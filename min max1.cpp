#include<iostream>
using namespace std;
struct MinMax
{
    int min;
    int max;
};
MinMax Find(int arr[],int i,int j)
{
    MinMax result,right,left;
    if(i==j)
    {
        result.min=result.max=arr[i];
    }
    if(j==i+1)
    {
        if(arr[i]<arr[j])
        {
            result.min=arr[i];
            result.max=arr[j];
        }
        else
        {
             result.min=arr[j];
            result.max=arr[i];
        }
        return result;
    }
    int mid=(i+j)/2;
    left=Find(arr,i,mid);
    right=Find(arr,mid+1,j);

    result.min=min(left.min,right.min);
    result.max=max(left.max,right.max);
     return result;
}
int main()
{
     int arr[] = {12, 3, 5, 7, 19, 0, -4, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax result = Find(arr, 0, n - 1);

    cout << "Minimum: " << result.min << endl;
    cout << "Maximum: " << result.max << endl;

    return 0;
}
