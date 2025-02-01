#include<iostream>
using namespace std;
struct MinMax
{
    int min;
    int max;
};
MinMax Find(int arr[],int i,int j)
{
    MinMax result,l,r;
    if(i==j)
    {
        result.min=result.max=arr[i];
    }
   if(j==i+1)
    {
       if(arr[i]>arr[j])
       {
           result.min=arr[j];
           result.max=arr[i];
       }
       else
       {
           result.max=arr[j];
           result.min=arr[i];
       }
       return result;
    }
    int mid=(i+j)/2;
   l= Find(arr,i,mid);
    r= Find(arr,mid+1,j);

    result.min=(l.min,r.min);
    result.max=(l.max,r.max);
    return result;
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
