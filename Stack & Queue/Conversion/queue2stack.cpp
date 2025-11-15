#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q;
    public:
        void push(int);
        int top();
        void pop();
        int size();
        bool empty();
};

void Stack::push(int data)
{
    if(q.size() == 0)
        q.push(data);
    else
    {
        
        int length = q.size();
        q.push(data);
        while(length--)
        {
            q.push(q.front());
            q.pop();
        }
    }
}

int Stack::top() {
    if (q.empty()) {
        cout << "Error: Stack is empty" << endl;
        return -1;
    }
    return q.front();
}

void Stack::pop() {
    if (q.empty()) {
        cout << "Error: Cannot pop from empty stack" << endl;
        return;
    }
    q.pop();
}

int Stack::size() {return q.size();}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl; // Should print 30
    s.pop();                                      // Remove 30

    cout << "Top after pop: " << s.top() << endl; // Should print 20
    cout << "Size: " << s.size() << endl;         // Should print 2

    s.pop();
    s.pop();
    s.pop(); // Optional: will not crash, but you might want to handle empty case

    return 0;
}