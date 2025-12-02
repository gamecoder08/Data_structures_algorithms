#include <iostream>
#include <vector>
#include <list>

class HashTable
{
private:
    int tableSize;
    std::vector<std::list<int>> table;

    int hashFunction(int key)
    {
        return key % tableSize;
    }

public:
    HashTable(int size)
    {
        tableSize = size;
        table.resize(size);
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void search(int key)
    {
        int index = hashFunction(key);
        for (int item : table[index])
        {
            if (item == key)
            {
                std::cout << "Found " << key << " in the hash table at index: " << index << std::endl;
                return;
            }
        }
        std::cout << key << " not found in the hash table." << std::endl;
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void printTable()
    {
        for (int i = 0; i < tableSize; i++)
        {
            std::cout << i << ": ";
            for (int item : table[i])
            {
                std::cout << item << " -> ";
            }
            std::cout << "nullptr" << std::endl;
        }
    }
};

int main()
{
    HashTable ht(10);

    ht.insert(6);
    ht.insert(15);
    ht.insert(25);
    ht.search(15);
    ht.printTable();
    ht.remove(15);
    ht.search(15);
    ht.printTable();
    return 0;
}