//Below Code Contains the Four traversal techniques of Trees
//Author: Satyam Shukla
#include <bits/stdc++.h>
using namespace std;
class Node //Declaring a Node Structure
{
    public:
    int data;
    Node *left;
    Node *right;
    public :
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void preorder(Node *root) // Recursive Preorder Traversal
{
    if (!root)
        return;
    cout << root->data << " "; //Step 1: calling root
    preorder(root->left); // Step 2: Moving on to the left subtree of root 
    preorder(root->right); // Step 3: Moving on to the right subtree of root 
}
void inorder(Node *root) // Recursive Inorder Traversal
{
    if (!root)
        return;

    inorder(root->left); // Step 1: Moving on to the left subtree of root 
    cout << root->data << " "; //Step 2: calling root
    inorder(root->right);// Step 3: Moving on to the right subtree of root 
}
void postorder(struct Node *root) // Recursive PostOrder Traversal
{
    if (!root)
        return;
    postorder(root->left); //Step 1: Moving on to the left subtree of root 
    postorder(root->right); // Step 2:  Moving on to the right subtree of root
    cout << root->data << " "; //Step 3: calling root
}
void levelOrder(Node *root) // Recursive Level Order Traversal
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root); // Pushing the root in the queue
    q.push(NULL);

    while (!q.empty()) // check whether queue is not empty
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left) //pushing the left subtree descendats of the current node in queue
                q.push(node->left);
            if (node->right) //pushing the right subtree descendats of the current node in queue
                q.push(node->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}
int32_t main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //preorder traversal
    preorder(root);
    cout << endl;

    //inorder traversal
    inorder(root);
    cout << endl;

    //postorder traversal
    postorder(root);
    cout << endl;

    //levelOrder traversal
    levelOrder(root);
    cout << endl;
}
