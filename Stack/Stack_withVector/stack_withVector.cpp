#include <iostream>
#include <vector>

using namespace std;

class stack
{
    vector<int> vec;
    int top;

public:
    void push(int x)
    {
        vec.push_back(x);
    }

    int pop()
    {
        if (vec.empty())
        {
            cout << "Stack is empty. Nothing to pop." << endl;
            return -1;
        }
        vec.pop_back();
    }
    int Top()
    {
        if (vec.empty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return vec.back();
    }

    bool isEmpty()
    {
        return vec.empty();
    }
};

int main()
{
    stack st;
    st.push(7);
    st.push(8);
    st.push(10);
    st.push(25);
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.isEmpty() << endl;

    return 0;
}