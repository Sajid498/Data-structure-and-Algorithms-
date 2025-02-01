#include<iostream>
using namespace std;
int s(int n)
{
   if(n==0)
   {
       return 0;
   }
   else
   {
       int last=n%10;
       n=n/10;
       return last+s(n);
   }
}
int main()
{
    int n;
    cin>>n;
    cout<<s(n)<<endl;
    return 0;
}
