//fibo
#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if(n<=1)
    {
        return n;
    }
    int prev1=1;
    int prev2=0;
    int current;
    for(int i=2;i<=n;i++)
    {
        current=prev1+prev2;
        prev2=prev1;
        prev1=current;
    }
    return current;
}
int main()
{
    int n;
    cin>>n;
    int result=fib(n);
    cout<<result;
}
