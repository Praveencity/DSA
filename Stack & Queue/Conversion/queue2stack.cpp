#include <iostream>
#include <queue>

class Stack
{
    std::queue<int> q;
    public:
        void push(int);
        int top();
        void pop();
        int size();
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

int Stack::top() {return q.front();}

void Stack::pop() {q.pop();}

int Stack::size() {return q.size();}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top: " << s.top() << std::endl; // Should print 30
    s.pop();                                      // Remove 30

    std::cout << "Top after pop: " << s.top() << std::endl; // Should print 20
    std::cout << "Size: " << s.size() << std::endl;         // Should print 2

    s.pop();
    s.pop();
    s.pop(); // Optional: will not crash, but you might want to handle empty case

    return 0;
}