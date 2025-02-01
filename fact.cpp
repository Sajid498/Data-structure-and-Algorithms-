#include<iostream>
using namespace std;

int f(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        int fact=n*f(n-1);
        return fact;
    }
}
int main()
{
    int n;
    cin>>n;
    int result=f(n);
    cout<<result<<endl;
    return 0;
}
