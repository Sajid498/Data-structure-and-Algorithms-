#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    int edmondsAlgorithm(int root, bool findMin) {
        vector<int> incomingWeight(V, findMin ? INT_MAX : INT_MIN);
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);

        for (const auto& edge : edges) {
            if (edge.u != edge.v && ((findMin && edge.weight < incomingWeight[edge.v]) ||
                                     (!findMin && edge.weight > incomingWeight[edge.v]))) {
                incomingWeight[edge.v] = edge.weight;
                parent[edge.v] = edge.u;
            }
        }

        for (int i = 0; i < V; ++i) {
            if (i == root || visited[i]) continue;

            int current = i;
            vector<int> cycle;
            while (!visited[current] && current != root) {
                visited[current] = true;
                cycle.push_back(current);
                current = parent[current];
            }

            if (current != root && !cycle.empty() && find(cycle.begin(), cycle.end(), current) != cycle.end()) {

                int cycleStart = current;
                int cycleWeight = 0;
                int cycleVertex = -1;
                for (int v : cycle) {
                    if (v == cycleStart) cycleWeight += incomingWeight[v];
                    else cycleWeight += incomingWeight[v] - incomingWeight[parent[v]];
                }

                cycleVertex = V++;
                incomingWeight.push_back(cycleWeight);
                parent.push_back(-1);

                for (const auto& edge : edges) {
                    if (find(cycle.begin(), cycle.end(), edge.u) != cycle.end()) {
                        addEdge(cycleVertex, edge.v, edge.weight - incomingWeight[edge.u]);
                    } else if (find(cycle.begin(), cycle.end(), edge.v) != cycle.end()) {
                        addEdge(edge.u, cycleVertex, edge.weight);
                    }
                }
            }
        }

        int totalWeight = 0;
        for (int i = 0; i < V; ++i) {
            if (i != root && parent[i] != -1) {
                totalWeight += incomingWeight[i];
            }
        }

        return totalWeight;
    }
};
int main() {
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 1);

    int root = 0;

    int minWeight = g.edmondsAlgorithm(root, true);
    cout << "The total weight of the minimum spanning tree is: " << minWeight << endl;

    int maxWeight = g.edmondsAlgorithm(root, false);
    cout << "The total weight of the maximum spanning tree is: " << maxWeight << endl;

    return 0;
}

