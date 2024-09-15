#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void BFS(vector<vector<int>> &graph, int startNode)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        int currentNode = q.front();
        cout << currentNode << " ";
        q.pop();

        for (int i = 0; i < numNodes; ++i)
        {
            if (graph[currentNode][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int numNodes = 5, startNode;

    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    cout << "Enter the starting node for BFS traversal: ";
    cin >> startNode;

    cout << "BFS Traversal starting from node " << startNode << ": ";
    clock_t start = clock();
    BFS(graph, startNode);
    clock_t end = clock();
    double time_spent = double(end - start) / CLOCKS_PER_SEC * 1000.0; // Convert to milliseconds
    cout << "\nTime spent: " << time_spent << " ms";
    return 0;
}
