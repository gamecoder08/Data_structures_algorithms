#include <iostream>
#include <vector>

class Graph
{
    int v;
    std::vector<std::vector<int>> adj;

    public:
    Graph(int vertices)
    {
        v = vertices;
        adj.resize(v);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display()
    {
        for(int i = 0 ; i < v; i++)
        {
            std::cout<< i << " -> ";
            for(auto j : adj[i])
            {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();

    return 0;
}
