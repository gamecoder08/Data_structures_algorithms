#include <iostream>
#include <vector>
#include <queue>

class UnDirectedGraph
{
    int V;
    std::vector<std::vector<int>> adj;

public:
    UnDirectedGraph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            std::cout << i << " -> ";
            for (auto j : adj[i])
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }

    void bfs(int start)
    {
        std::vector<bool> visited(V, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            std::cout << u << " ";

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void dfsUtil(int u, std::vector<bool> &visited)
    {
        visited[u] = true;
        std::cout << u << " ";

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                dfsUtil(v, visited);
            }
        }
    }

    void dfs(int start)
    {
        std::vector<bool> visited(V, false);
        dfsUtil(start, visited);
    }
};

int
main()
{
    UnDirectedGraph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(4, 3);
    g.addEdge(4, 2);

    std::cout << "Graph: \n";
    g.printGraph();

    std::cout << "\nBFS from 0: ";
    g.bfs(0);

    std::cout << "\nDFS from 0: ";
    g.dfs(0);

    return 0;
}