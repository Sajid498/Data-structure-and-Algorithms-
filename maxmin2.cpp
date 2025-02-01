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
        return result;
    }
    if(i+1==j)
    {
        if(arr[i]<arr[j])
        {
            result.min=arr[i];
            result.max=arr[j];
        }
        else{
            result.min=arr[j];
            result.max=arr[i];
        }
        return result;
    }
    int mid=(i+j)/2;
    right=Find(arr,i,mid);
    left=Find(arr,mid+1,j);

    result.min=min(right.min,left.min);
    result.max=max(right.max,left.max);
    return result;
}
int main()
{
    int arr[]={1,3,5,6,-5,6,9,-12,15};
    int n=sizeof(arr)/sizeof(arr[0]);
   MinMax result=Find(arr,0,n-1);
    cout<<"MIN: "<<result.min<<endl;
    cout<<"MAX: "<<result.max<<endl;
    return 0;
}
