#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, int source)
{
    int n = graph.size();

    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);

    distance[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int current = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] &&
                (current == -1 ||
                 distance[i] < distance[current]))
            {
                current = i;
            }
        }

        if (current == -1)
            break;

        visited[current] = true;

        for (auto edge : graph[current])
        {
            int next = edge.first;
            int weight = edge.second;

            if (distance[current] != INT_MAX &&
                distance[current] + weight < distance[next])
            {
                distance[next] =
                    distance[current] + weight;
            }
        }
    }

    cout << "\nShortest distances from vertex "
         << source << ":\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i << " = ";

        if (distance[i] == INT_MAX)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }
}

int main()
{
    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;

        cin >> u >> v >> weight;

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}
