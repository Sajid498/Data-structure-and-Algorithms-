#include<iostream>
using namespace std;
int Count(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        n=n/10;
        return 1+Count(n);
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<Count(n)<<endl;
    return 0;
}
