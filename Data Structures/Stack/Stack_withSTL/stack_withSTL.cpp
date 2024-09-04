#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;
    st.push(7);
    st.push(8);
    st.push(10);
    st.push(25);
    st.push(29);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;
    st.pop();
    st.pop();
    cout << st.empty() << endl;
    return 0;
}