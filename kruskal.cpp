#include<bits/stdc++.h>
using namespace std;
struct DSU
{
    int V;
    vector< int > parent;
    vector< int > rank_;

    DSU(int vertices)
    {
        V = vertices;
        parent.resize(V);
        rank_.resize(V);

        for(int i=0; i<V; i++)
            set_(i);
    }

    void set_(int x)
    {
        parent[x] = x;
        rank_[x] = 0;
    }
    int find_(int x)
    {
        if(parent[x] == x) return x;
        else return parent[x] = find_(parent[x]);
    }
    bool union_(int u, int v)
    {
        int repU = find_(u);
        int repV = find_(v);
        if(repU!=repV)
        {
            if(rank_[repU]>rank_[repV])
                parent[repV] = repU;
            else if(rank_[repV]>rank_[repU])
                parent[repU] = repV;
            else
            {
                parent[repV] = repU;
                rank_[repU]+=1;
            }
            return true;
        }
        else
            return false;
    }
};
struct Edge
{
    int u,v,w;
};
bool compare(Edge &left,Edge &right)
{
    if(left.w<=right.w)
    {
        return true;
    }
    else return false;
}

int main()
{
    int E = 7;
    int V = 5;

    Edge edges[7] = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 3},
        {2, 4, 5},
        {3, 4, 7},
    };
    DSU *dsu=new DSU(V);
    sort(edges,edges+E,compare);
int cost;
    for(int i=0;i<E;i++)
    {
        Edge edge=edges[i];
        bool result=dsu->union_(edge.u,edge.v);
        if(result==true)
        {
            cost+=edge.w;
        }
    }
    cout<<cost<<endl;
    return 0;
}
