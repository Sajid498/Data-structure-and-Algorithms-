//bellman
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

struct Edge
{
    int u;
    int v;
    int cost;
};

void bellman_Ford(Edge edges[], int E, int V, int source)
{
    int d[V];
    int parent[V];
    for(int i=0; i<V; i++)
    {
        d[i] = INF;
        parent[i] = i;
    }

    d[source] = 0;

    bool found_shortest_path = false;

    for(int i=1; i<=V-1; i++)
    {
        cout << "Iteration " << i << endl;
        bool update_hoyeche = false;
        for(int j=0; j<E; j++)
        {
            Edge edge = edges[j];
            cout << edge.u << " --> " << edge.v << ":\n";
            if(d[edge.u]+edge.cost<d[edge.v])
            {
                cout << d[edge.u] << " + " << edge.cost << " < " << d[edge.v] << " : True" << endl;
                update_hoyeche = true;
                d[edge.v] = d[edge.u]+edge.cost;
                parent[edge.v] = edge.u;
            }
            else
            {
                cout << d[edge.u] << " + " << edge.cost << " < " << d[edge.v] << " : False" << endl;
            }
        }
        cout << endl << endl;
        if(update_hoyeche==false)
        {
            found_shortest_path = true;
            break;
        }
    }

    if(found_shortest_path==false)
    {
        cout << "Iteration " << V << endl;
        bool update_hoyeche = false;
        for(int j=0; j<E; j++)
        {
            Edge edge = edges[j];
            cout << edge.u << " --> " << edge.v << ":\n";

            if(d[edge.u]+edge.cost<d[edge.v])
            {
                cout << d[edge.u] << " + " << edge.cost << " < " << d[edge.v] << " : True" << endl;
                cout << "Negative Cycle Exist!" << endl;
                return;
            }
            else
            {
                cout << d[edge.u] << " + " << edge.cost << " < " << d[edge.v] << " : False" << endl;

            }
        }
    }

    for(int i=0; i<V; i++)
    {
        cout << source << " --> " << i << " : " << d[i] << endl;
    }

}


int main()
{
    int E = 9;
    int V = 6;

    Edge edges[E] =
    {
        {1, 2, 6},
        {1, 3, 4},
        {1, 4, 5},
        {2, 5, -1},
        {3, 2, -2},
        {3, 5, 3},
        {4, 3, -2},
        {5, 6, 3},
        {4, 6, -1}
    };

    bellman_Ford(edges, E, V, 0);



    return 0;
}
