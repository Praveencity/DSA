#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
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
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// BFS traversal

void bfs(Node* root)
{
    vector<vector<int>> ans;
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int len = q.size();
        vector<int> level;
        for(int i=0;i<len;i++){
            Node * curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << ' ';
        }
    }
}

// Iterative

void iterativePreorder(Node* root)
{
    if(!root) return;
    stack<Node*> s;
    s.push(root);
    while(!s.empty())
    {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
}

void iterativeInorder(Node* root)
{
    stack<Node*> st;
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
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
    
}

void iterative2StPostorder(Node* root)
{
    if(!root) return;
    stack<Node*> st1,st2;
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
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void iterativePostorder(Node* root)
{
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node * curr = st.top();
        st.pop();
        ans.push_back(curr->data);
        if(curr->left) st.push(curr->left);
        if(curr->right) st.push(curr->right);
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
        cout << i << ' ';
}

void iterativeTraversal(Node* root)
{
    
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->left = new Node(6);


    //DFS traversal

    cout << "\nPreorder DFS: ";
    preorder(root);

    cout << "\nInorder DFS: ";
    inorder(root);

    cout << "\nPostorder DFS: ";
    postorder(root);

    //BFS
    cout << "\nBFS: ";
    bfs(root);

    // Iterative
    cout << "\nIterative Preorder: ";
    iterativePreorder(root);
    
    cout << "\nIterative Inorder: ";
    iterativeInorder(root);

    cout << "\nIterative Postorder 2 stack: ";
    iterative2StPostorder(root);
    
    cout << "\nIterative Postorder 1 stack: ";
    iterativePostorder(root);

    
}