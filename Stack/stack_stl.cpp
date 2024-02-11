#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);

    s.pop();
    cout << "Printing top element: " << s.top() << endl;
    cout << "Size of stack: " << s.size() << endl;
    if (s.empty())
    {
        cout << "Stack is empty!!" << endl;
    }
    else
    {
        cout << "Stack is empty!!" << endl;
    }
    s.pop();
    cout << "Printing top element: " << s.top() << endl;
    cout << "Size of stack: " << s.size() << endl;
    if (s.empty())
    {
        cout << "Stack is empty!!" << endl;
    }
    else
    {
        cout << "Stack is empty!!" << endl;
    }

    return 0;
}