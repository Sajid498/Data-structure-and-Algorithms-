//dijkstra
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x7F7F7F7F;
struct Pair
{
    int v;
    int cost_u_v;
};
struct NodeDistance
{
    int node;
    int distance;
};
struct CompareByDistance
{
    bool operator()(NodeDistance left, NodeDistance right)
    {
        return left.distance > right.distance;
    }
};

void path_print(int parent[], int destination)
{
    if(parent[destination] == destination)
    {
        cout << destination << " ";
        return;
    }
    else
    {
        path_print(parent, parent[destination]);
        cout << destination << " ";
    }
}

void dijkstra(vector< Pair > adjacencyList[], int source, int V)
{
    priority_queue< NodeDistance, vector< NodeDistance>, CompareByDistance > PQ;

    int d[V];
    int parent[V];
    int found_optimal_path[V] = {0};

    for(int i = 0; i < V; i++)
    {
        d[i] = INF;
        parent[i] = i;
    }
    d[source] = 0;

    PQ.push({source, d[source]});
    parent[source] = source;

    while(!PQ.empty())
    {
        NodeDistance nodeDistance = PQ.top();
        PQ.pop();

        int node = nodeDistance.node;
        found_optimal_path[node] = 1;

        for(Pair p : adjacencyList[node])
        {
            if(d[node] + p.cost_u_v < d[p.v])
            {
                d[p.v] = d[node] + p.cost_u_v;
                PQ.push({p.v, d[p.v]});

                parent[p.v] = node;
            }
        }
    }

    cout << "Distance: ";
    for(int i = 0; i < V; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    cout << "Parent: ";
    for(int i = 0; i < V; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;

    cout << "Shortest Paths: \n";
    for(int i = 0; i < V; i++)
    {
        cout << source << " to " << i << " : ";
        path_print(parent, i);
        cout << endl;
    }
}
int main()
{
    int V = 4;
    vector< Pair > adjacencyList[V];

    adjacencyList[0] = {{1, 2}, {2, 5}};
    adjacencyList[1] = {{2, 2}, {3, 10}};
    adjacencyList[2] = {{3, 6}};
    adjacencyList[3] = {{2, 8}};

    int source = 0;
    dijkstra(adjacencyList, source, V);

    return 0;
}
