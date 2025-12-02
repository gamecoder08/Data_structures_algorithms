#include <iostream>
#include <vector>
#include <list>

class HashTable
{
private:
    int tableSize;
    std::vector<std::list<std::pair<int, int>>> table;

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

    void insert(int key, int value)
    {
        int index = hashFunction(key);

        for (auto &keyValue : table[index])
        {
            if (keyValue.first == key)
            {
                keyValue.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }

    void search(int key)
    {
        int index = hashFunction(key);
        for (auto &item : table[index])
        {
            if (item.first == key)
            {
                std::cout << "Found " << key << " in the hash table at index: " << index << " and value: " << item.second << std::endl;
                return;
            }
        }
        std::cout << key << " not found in the hash table." << std::endl;
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->first == key)
            {
                table[index].erase(it);
                return;
            }
        }
    }

    void printTable()
    {
        for (int i = 0; i < tableSize; i++)
        {
            std::cout << i << ": ";
            for (auto &kv : table[i])
            {
                std::cout << "(" << kv.first << "," << kv.second << ") -> ";
            }
            std::cout << "nullptr\n";
        }
    }
};

int main()
{
    HashTable ht(10);

    ht.insert(6, 60);
    ht.insert(15, 150);
    ht.insert(25, 250);

    ht.search(15);
    ht.printTable();

    ht.remove(15);
    ht.search(15);
    ht.printTable();

    return 0;
}