#include<iostream>
using namespace std;

struct MinMax
{
    int min;
    int max;
};
MinMax Find(int arr[],int i,int j)
{
    MinMax result,low,high;
    if(i==j)
    {
        result.min=result.max=arr[i];
    }
    if(i+1==j)
    {
        if(arr[i]>arr[j])
        {
            result.min=arr[j];
            result.max=arr[i];
        }
        else
        {
            result.min=arr[i];
            result.max=arr[j];
        }

    }
    int mid=(i+j)/2;
    int l=Find(arr,i,mid);
    int r=Find(arr,mid+1,high);

    result.min=min(l.min,r.min);
    result.max=max(l.max,r.max);
}
int main()
{
    int arr[] = {10,2,5,9,-8,45,129,-312};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax result = Find(arr, 0, n - 1);

    cout << "Minimum: " << result.min << endl;
    cout << "Maximum: " << result.max << endl;
    return 0;
}
