#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(7);
    q.push(8);
    q.push(20);
    q.push(21);
    q.push(29);

    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;
    q.pop();

    cout << q.empty() << endl;

    return 0;
}