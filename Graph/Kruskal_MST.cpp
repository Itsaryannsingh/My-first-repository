#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int source;
    int destination;
    int weight;
};

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rankValue.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (parent[node] != node)
        {
            parent[node] = findParent(parent[node]);
        }

        return parent[node];
    }

    bool unite(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV)
        {
            return false;
        }

        if (rankValue[parentU] < rankValue[parentV])
        {
            parent[parentU] = parentV;
        }
        else if (rankValue[parentU] > rankValue[parentV])
        {
            parent[parentV] = parentU;
        }
        else
        {
            parent[parentV] = parentU;
            rankValue[parentU]++;
        }

        return true;
    }
};

void kruskalMST(int vertices, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(vertices);

    int totalWeight = 0;
    int selectedEdges = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (Edge edge : edges)
    {
        if (ds.unite(edge.source, edge.destination))
        {
            cout << edge.source << " -- "
                 << edge.destination
                 << " : " << edge.weight << endl;

            totalWeight += edge.weight;
            selectedEdges++;
        }

        if (selectedEdges == vertices - 1)
        {
            break;
        }
    }

    if (selectedEdges != vertices - 1)
    {
        cout << "MST does not exist because the graph "
             << "is disconnected.\n";
        return;
    }

    cout << "Minimum Total Weight = "
         << totalWeight << endl;
}

int main()
{
    int vertices, numberOfEdges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> numberOfEdges;

    vector<Edge> edges(numberOfEdges);

    cout << "Enter source, destination and weight:\n";

    for (int i = 0; i < numberOfEdges; i++)
    {
        cin >> edges[i].source
            >> edges[i].destination
            >> edges[i].weight;
    }

    kruskalMST(vertices, edges);

    return 0;
}
