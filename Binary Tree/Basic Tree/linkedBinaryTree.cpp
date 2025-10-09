#include <iostream>
#include <queue>
#include <stack>

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int data1 = 0, Node* left1 = nullptr, Node* right1 = nullptr)
        {
            data = data1;
            left = left1;
            right = right1;
        }
};

// DFS traversal

void preorder(Node* root)
{
    if(!root) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

// BFS traversal

void bfs(Node* root)
{
    if (!root) return;
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        std::cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

// Iterative

void iterativePreorder(Node* root)
{
    if(!root) return;
    std::stack<Node*> s;
    s.push(root);
    while(!s.empty())
    {
        Node* curr = s.top();
        s.pop();
        std::cout << curr->data << " ";
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
}

void iterativeInorder(Node* root)
{
    std::stack<Node*> st;
    Node* curr = root;
    while(true)
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if(st.empty()) break;
            curr = st.top();
            st.pop();
            std::cout << curr->data << " ";
            curr = curr->right;
        }
    }
    
}

void iterative2StPostorder(Node* root)
{
    if(!root) return;
    std::stack<Node*> st1,st2;
    st1.push(root);

    while(!st1.empty())
    {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
    }
    while(!st2.empty())
    {
        std::cout << st2.top()->data << " ";
        st2.pop();
    }
}

void iterativePostorder(Node* root)
{
    std::stack<Node*> st;
    Node* curr = root;
    while(!st.empty() || curr)
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node* temp = st.top()->right;
            if(!temp)
            {
                temp = st.top();
                st.pop();
                std::cout << temp->data << " ";
                while(!st.empty() && temp == st.top()->right)
                {
                    std::cout << st.top()->data << " ";
                    temp = st.top();
                    st.pop();
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
}

void iterativeTraversal(Node* root)
{
    
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->left = new Node(4);
    root->right->left = new Node(4);


    //DFS traversal

    std::cout << "\nPreorder DFS: ";
    preorder(root);

    std::cout << "\nInorder DFS: ";
    inorder(root);

    std::cout << "\nPostorder DFS: ";
    postorder(root);

    //BFS
    std::cout << "\nBFS: ";
    bfs(root);

    // Iterative
    std::cout << "\nIterative Preorder: ";
    iterativePreorder(root);
    
    std::cout << "\nIterative Inorder: ";
    iterativeInorder(root);

    std::cout << "\nIterative Postorder 2 stack: ";
    iterative2StPostorder(root);
    
    std::cout << "\nIterative Postorder 1 stack: ";
    iterativePostorder(root);

    
}