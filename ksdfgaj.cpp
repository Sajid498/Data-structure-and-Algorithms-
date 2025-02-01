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
typedef struct Edge Edge;
bool compare(Edge &left,Edge &right)
{
    if(left.w<=right.w)
        return true;
    else return false;
}

int main()
{
    int E=13;
    int V=9;
    Edge edges[13]=
    {
        {1,2,1},
        {1,3,6},
        {1,4,5},
        {2,3,6},
        {3,6,3},
        {3,5,7},
        {4,7,10},
        {4,6,2},
        {5,8,12},
        {6,8,8},
        {7,8,7},
        {7,9,3},
        {8,9,8}
    };
    DSU *dsu=new DSU(9);
    sort(edges,edges+E,compare);
    int cost=0;
    for(int i=0;i<E;i++)
    {
        Edge edge=edges[i];
        bool result=dsu->union_(edge.u,edge.v);
        if(result==true)
        {
            cout<<edge.u<<" "<<edge.v<<endl;
            cost+=edge.w;
        }

    }
    cout<<"cost:"<<cost;
    return 0;
}
