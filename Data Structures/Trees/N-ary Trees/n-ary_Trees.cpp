#include <iostream>
#include <vector>
#include <queue>
#include <memory>

class Node {
public:
    int data;
    std::vector<std::unique_ptr<Node>> children;

    Node(int value) : data(value) {}
};

class NaryTree {
public:
    std::unique_ptr<Node> root;

    NaryTree(int value) {
        root = std::make_unique<Node>(value);
    }

    void dfs(Node* node) {
        if (node == nullptr) return;

        std::cout << node->data << " ";

        for (auto& child : node->children) {
            dfs(child.get());
        }
    }

    void bfs(Node* node) {
        if (node == nullptr) return;

        std::queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            std::cout << current->data << " ";

            for (auto& child : current->children) {
                q.push(child.get());
            }
        }
    }
};

int main() {
    NaryTree tree(1);

    tree.root->children.push_back(std::make_unique<Node>(2));
    tree.root->children.push_back(std::make_unique<Node>(3));
    tree.root->children.push_back(std::make_unique<Node>(4));

    tree.root->children[0]->children.push_back(std::make_unique<Node>(5));
    tree.root->children[0]->children.push_back(std::make_unique<Node>(6));

    tree.root->children[1]->children.push_back(std::make_unique<Node>(7));

    std::cout << "DFS Traversal: ";
    tree.dfs(tree.root.get());
    std::cout << std::endl;

    std::cout << "BFS Traversal: ";
    tree.bfs(tree.root.get());
    std::cout << std::endl;

    return 0;
}
