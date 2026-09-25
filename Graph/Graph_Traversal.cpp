#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Add an edge to the graph
void addEdge(vector<vector<int>>& graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Display adjacency list
void displayGraph(const vector<vector<int>>& graph)
{
    cout << "\n===== ADJACENCY LIST =====\n";

    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";

        for (int neighbour : graph[i])
        {
            cout << neighbour << " ";
        }

        cout << endl;
    }
}

// Breadth First Search
void BFS(const vector<vector<int>>& graph, int start)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbour : graph[current])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    cout << endl;
}

// Depth First Search
void DFSUtil(
    const vector<vector<int>>& graph,
    int current,
    vector<bool>& visited)
{
    visited[current] = true;

    cout << current << " ";

    for (int neighbour : graph[current])
    {
        if (!visited[neighbour])
        {
            DFSUtil(graph, neighbour, visited);
        }
    }
}

// Start DFS
void DFS(const vector<vector<int>>& graph, int start)
{
    vector<bool> visited(graph.size(), false);

    cout << "DFS Traversal: ";

    DFSUtil(graph, start, visited);

    cout << endl;
}

int main()
{
    int vertices;
    int choice;

    cout << "===== GRAPH CREATION =====\n";

    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices);

    do
    {
        cout << "\n===== GRAPH MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. BFS Traversal\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int u, v;

            cout << "Enter first vertex: ";
            cin >> u;

            cout << "Enter second vertex: ";
            cin >> v;

            if (u >= 0 && u < vertices &&
                v >= 0 && v < vertices)
            {
                addEdge(graph, u, v);

                cout << "Edge added successfully.\n";
            }
            else
            {
                cout << "Invalid vertex!\n";
            }

            break;
        }

        case 2:
            displayGraph(graph);
            break;

        case 3:
        {
            int start;

            cout << "Enter starting vertex: ";
            cin >> start;

            if (start >= 0 && start < vertices)
            {
                BFS(graph, start);
            }
            else
            {
                cout << "Invalid starting vertex!\n";
            }

            break;
        }

        case 4:
        {
            int start;

            cout << "Enter starting vertex: ";
            cin >> start;

            if (start >= 0 && start < vertices)
            {
                DFS(graph, start);
            }
            else
            {
                cout << "Invalid starting vertex!\n";
            }

            break;
        }

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
