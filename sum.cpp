#include<iostream>
using namespace std;
int f(int i,int n)
{
    if(i>n)
    {
        return 0;
    }
    else
    {
        int sum=f(i+1,n);
        return i+sum;
    }
}
int main()
{
    int n;
    cin>>n;
    int result=f(1,n);
    cout<<"Result="<<result<<endl;
    return 0;
}
