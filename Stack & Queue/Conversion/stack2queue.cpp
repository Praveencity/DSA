#include <iostream>
#include <stack>

class Queue
{
    std::stack<int> s1;
    std::stack<int> s2;

    public:
        void push(int);
        int front();
        int back();
        void pop();
        int size();

};

void Queue::push(int data) {s1.push(data);}

int Queue::front() 
{
    if(!s2.size())
    {
        while(s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}

int Queue::back()
{
    if(!s1.empty()) return s1.top();

    std::stack<int> temp = s2;
    while(temp.size() > 1) temp.pop();
    return temp.top();
}

void Queue::pop() 
{
    if(!s2.size())
    {
        while(s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}

int Queue::size() {return s1.size() + s2.size();}

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front: " << q.front() << "\n"; // 10
    std::cout << "Back: " << q.back() << "\n";   // 30

    q.pop();
    std::cout << "After pop:\n";
    std::cout << "Front: " << q.front() << "\n"; // 20
    std::cout << "Back: " << q.back() << "\n";   // 30

    q.push(40);
    std::cout << "After pushing 40:\n";
    std::cout << "Front: " << q.front() << "\n"; // 20
    std::cout << "Back: " << q.back() << "\n";   // 40

    std::cout << "Size: " << q.size() << "\n";   // 3
    return 0;
}