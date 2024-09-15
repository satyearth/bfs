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
/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

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
    int numNodes, startNode;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;

    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the starting node for BFS traversal: ";
    cin >> startNode;
    cout << "BFS Traversal starting from node " << startNode << ": ";
    clock_t start = clock();
    BFS(graph, startNode);
    clock_t end = clock();
    double time_spent = double(end - start);
    cout << "\ntime spent: " << time_spent << " ms";
    return 0;
}
/*
Output-
Enter the number of nodes in the graph: 5
Enter the adjacency matrix for the graph:
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0
Enter the starting node for BFS traversal: 0
BFS Traversal starting from node 0: 0 1 3 2 4
*/
*/

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int V;                       // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    
    Graph(int vertices) : V(vertices)
    {
        adjList.resize(V);
    }  

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        queue<int> q;                   // Create a queue for BFS

        visited[startVertex] = true; // Mark the current node as visited and enqueue it
        q.push(startVertex);

        while (!q.empty())
        {
            startVertex = q.front(); // Dequeue a vertex from queue and print it
            cout << startVertex << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex.
            // If an adjacent has not been visited, then mark it visited and enqueue it
            for (int i = 0; i < adjList[startVertex].size(); ++i)
            {
                int adjVertex = adjList[startVertex][i];
                if (!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }
    }
};

int main()
{
    int V = 6; // Number of vertices
    Graph graph(V);

    // Adding edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    int startVertex = 0; // Starting vertex for BFS

    cout << "Vertices reachable from vertex " << startVertex << " using BFS: ";
    clock_t start,end;
    start = clock ();
    graph.BFS(startVertex);
    end = clock();
    double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    cout<<"\ntime spent: "<<time_spent;
    cout << endl;

    return 0;
}
*/
