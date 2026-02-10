#include <iostream>
#include <vector>
#include <queue>

class DirectedGraph
{
private:
    int V;
    std::vector<std::vector<int>> adjList;

public:
    DirectedGraph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
    }

    void printGraph()
    {
        for (int i = 0; i < V; ++i)
        {
            std::cout << "Vertex " << i << ":";
            for (int neighbor : adjList[i])
            {
                std::cout << " " << neighbor;
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
            int current = q.front();
            q.pop();
            std::cout << current << " ";
            for (int neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void dfsUtil(int vertex, std::vector<bool> &visited)
    {
        visited[vertex] = true;
        std::cout << vertex << " ";
        for (int neighbor : adjList[vertex])
        {
            if (!visited[neighbor])
            {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(int start)
    {
        std::vector<bool> visited(V, false);
        dfsUtil(start, visited);
    }
};

int main()
{
    DirectedGraph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);

    std::cout << "Graph adjacency list:" << std::endl;
    graph.printGraph();

    std::cout << "Breadth-First Search starting from vertex 0:" << std::endl;
    graph.bfs(0);
    std::cout << std::endl;

    std::cout << "Depth-First Search starting from vertex 0:" << std::endl;
    graph.dfs(0);
    std::cout << std::endl;

    return 0;
}