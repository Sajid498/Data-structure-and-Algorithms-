#include<iostream>
using namespace std;
int sum(int arr[],int l,int r)
{
    int sum=0;
    for(int i=l;i<=r;i++)
    {
        sum=sum+arr[i];
        //printf("%d",arr[i]);
    }
     //printf("; Summation: %d; Indices: (%d, %d)\n", sum, left, right);
    return sum;
}
int main()
{
    int n=5;
    int arr[n]={5,8,-6,-8,2};
    int li;
    int ri;
    int maximum=-INT_MAX;

    for(int i=0;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int result=sum(arr,i,j);
            if(result>maximum)
            {
                maximum=result;
                li=i;
                ri=j;
            }
        }
    }
    printf("Maximum sum sub array:%d    %d %d",maximum,li,ri);
    return 0;
}
