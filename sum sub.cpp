#include<iostream>
using namespace std;
int sum(int arr[],int left,int right)
{
    int sum=0;
    for(int i=left; i<=right; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int n=10;
    int arr[10]= {1,5,-2,6,-8,7,-6,-3,8,10};
    int maximum=-INT_MAX;
    int lefti;
    int righti;
    for(int i=0; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            int result=sum(arr,i,j);
            if(result>maximum)
            {
                maximum=result;
                int lefti=i;
                int righti=j;
            }

        }


    }
    printf("Maximum:%d;INDEX:[%d,%d]",maximum,lefti,righti);
    return 0;
}
