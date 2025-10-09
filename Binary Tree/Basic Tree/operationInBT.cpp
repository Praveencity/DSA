#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data1 = 0, Node *left1 = nullptr, Node *right1 = nullptr)
    {
        data = data1;
        left = left1;
        right = right1;
    }
};

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Height of Binary tree

int maxDepth(Node *root)
{
    if (!root)
        return 0;
    int lf = maxDepth(root->left);
    int rt = maxDepth(root->right);
    return 1 + max(lf, rt);
}

// Check whether tree is balance

int balanceTree(Node *root)
{
    if (!root)
        return 0;
    int lf = balanceTree(root->left);
    if (lf == -1)
        return -1;
    int rt = balanceTree(root->right);
    if (rt == -1)
        return -1;
    if (abs(lf - rt) > 1)
        return -1;
    return 1 + max(lf,rt);
}

// Find the Diameter of binary tree
int maxi = 0;

int treeDiameter(Node* root)
{
    if(!root)
        return 0;
    int lf = treeDiameter(root->left);
    int rt = treeDiameter(root->right);
    if(maxi < lf + rt)
        maxi = lf+rt;
    return 1 + max(lf,rt);
}

int maxiPath = 0;

int maxPathSum(Node* root)
{
    if(!root) return 0;
    int lf = maxPathSum(root->left);
    int rt = maxPathSum(root->right);
    if(maxiPath < lf+rt+root->data) maxiPath = lf + rt + root->data;

    return root->data + max(lf,rt);

}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    inorder(root);

    //Maximum Height
    cout << "\nMaximum Height of Tree : " << maxDepth(root) << endl;

    //Balance Tree
    string balance = balanceTree(root)== -1 ? "NO" : "YES"; 
    cout << "\nIs tree balance : " << balance << endl;
    
    //Diameter of tree
    treeDiameter(root);
    cout << "\nDiameter of tree : " << maxi << endl;
    
    //Maximum Path Sum
    maxPathSum(root);
    cout << "\nMax Path sum of tree : " << maxiPath << endl;

}