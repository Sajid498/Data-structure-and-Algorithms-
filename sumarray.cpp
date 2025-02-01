#include<iostream>
using namespace std;
struct Result
{
    int summation;
    int leftindex;
    int rightindex;
};
Result crossing_sum(int arr[],int low,int mid,int high)
{
    int sum=0;
    int lsum=-INT_MAX;
    int lindex;
    for(int i=mid;i<=low;i--)
    {
        sum+=arr[i];
        if(sum>lsum)
        {
            lsum=sum;
            lindex=i;
        }
    }
    sum=0;
    int rsum=-INT_MAX;
    int rindex;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=arr[i];
        if(sum>lsum)
        {
            rsum=sum;
            rindex=i;
        }
    }
    return {lsum+rsum,lindex,rindex};
}
Result maxsum(int arr[],int low,int high)
{
    if(low==high)
    {
        return{arr[low],low,low};
    }
    else
    {
        int mid=(low+high)/2;
        Result left=maxsum(arr,low,mid);
        Result right=maxsum(arr,mid+1,high);
        Result cross=crossing_sum(arr,low,mid,high);

        if(left.summation>right.summation&&left.summation>cross.summation)
        {
            return left;
        }
        if (left.summation<right.summation&&right.summation>cross.summation)
        {
            return right;
        }
        else
        {
            return cross;
        }
    }
}
typedef struct Result Result;
int main()
{
    int n = 8;
    int arr[n] = {-2, -5, 6, -2, -3, 1, 5, -6};

    Result maximum_subarray_sum = maxsum(arr, 0, n-1);


    printf("Summation: %d; Indices: (%d, %d)\n", maximum_subarray_sum.summation, maximum_subarray_sum.leftindex, maximum_subarray_sum.rightindex);


    for(int i=maximum_subarray_sum.leftindex; i<=maximum_subarray_sum.rightindex; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
