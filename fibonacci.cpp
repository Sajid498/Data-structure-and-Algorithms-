#include<bits/stdc++.h>
#define MAX 100
#define NOT_SET -1LL
using namespace std;

long long int cache[MAX+7];

long long int fib(int n)
{
    if(n==0 || n==1) return n;
    if(cache[n]!=NOT_SET) return cache[n];
    else
    {
        long long int left = fib(n-1);
        long long int right = fib(n-2);
        long long int result = left + right;
        cache[n] = result;
        return result;
    }
}


int main()
{
    memset(cache, NOT_SET, sizeof(cache));

    for(int i=0; i<MAX; i++)
    {
        cout << cache[i] << " ";
    }
    cout << endl;


    fib(10);

    cout << endl << endl;
    for(int i=0; i<MAX; i++)
    {
        cout << cache[i] << " ";
    }
    cout << endl;

    fib(100);


    cout << endl << endl;
    for(int i=0; i<MAX; i++)
    {
        cout << cache[i] << " ";
    }
    cout << endl;

    return 0;
}
