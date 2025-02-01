#include<bits/stdc++.h>
#define MAX 100
#define NOT_SET -1
using namespace std;

const int INF = 0x7f7f7f7f;

int cache[MAX+1];

int parent[MAX+1];

int coin_change(int amount, int coins[], int n)
{
    if(cache[amount]!=NOT_SET) return cache[amount];

    int result = INF;
    for(int i=0; i<n; i++)
    {
        if(coins[i]<=amount) /// check kortesi nite parbo kina
        {

            /// nite parbo
            int remaining_amount = amount - coins[i];
            int friend_ = coin_change(remaining_amount, coins, n);
            int total_coins = 1 + friend_;

            if(total_coins<result)
            {
                result = total_coins;
                parent[amount] = coins[i];
            }
        }
    }

    cache[amount] = result;
    return result;
}


int main()
{
    int n = 2;
    int amount = 17;
    int coins[n] = {6, 2};

    memset(cache, NOT_SET, sizeof(cache));
    cache[0] = 0;

    int result = coin_change(amount, coins, n);

    cout << result << endl;


    for(int i=0; i<=amount; i++)
        cout << cache[i] << " ";
    cout << endl;


    for(int i=0; i<=amount; i++)
        cout << parent[i] << " ";
    cout << endl;
    return 0;
}
