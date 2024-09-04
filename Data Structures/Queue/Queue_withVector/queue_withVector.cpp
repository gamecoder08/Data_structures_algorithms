#include <iostream>
#include <vector>

using namespace std;

class queue
{
    vector<int> vec;

public:
    void push(int x)
    {
        vec.push_back(x);
    }

    void pop()
    {
        if (vec.empty())
        {
            cout << "No elements in queue" << endl;
            return;
        }
        vec.erase(vec.begin());
    }

    int peek()
    {
        if (vec.empty())
        {
            cout << "No elements in queue" << endl;
            return -1;
        }
        return *vec.begin();
    }

    bool isempty()
    {
        if (vec.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    queue q;
    q.push(7);
    q.push(8);
    q.push(20);
    q.push(21);
    q.push(29);

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.isempty() << endl;

    return 0;
}