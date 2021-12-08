#include<stdio.h>
#include<stdlib.h>

//A BST node comprises of the value, left subtree & right subtree : 
struct BSTnode
{
    int value;
    struct BSTnode* left;
    struct BSTnode* right;
};

//Creating a node :
struct BSTnode* createnode(int value){
    struct BSTnode* newnode = (struct BSTnode*)malloc(sizeof(struct BSTnode));
    newnode->left=newnode->right=0;
    newnode->value = value;
    return newnode;
}

//Inserting a node (If value <= rootvalue, insert as left child. Else if value >= rootvalue, insert as right child.) : 
struct BSTnode* insertnode(struct BSTnode* root, int value){
    if (root==NULL)
    {
        root = createnode(value);
    }
    else if (value<=root->value)
    {
        root->left = insertnode(root->left, value);
    }
    else if(value>=root->value)
    {
        root->right = insertnode(root->right, value);
    }
    return root;
}

//Inorder Traversal & Display :
void printInorder(struct BSTnode* root){
    if (root!=NULL)
    {
        printInorder(root->left);
        printf("%d  ", root->value);
        printInorder(root->right);
    }
}

//Preorder Traversal & Display :
void printPreorder(struct BSTnode* root){
    if(root!=NULL){
    printf("%d  ", root->value);
    printPreorder(root->left);
    printPreorder(root->right);}
}

//Postorder traversal & Display :
void printPostorder(struct BSTnode* root){
    if(root!=NULL){
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d  ", root->value);}
}

//Main function (Testing the above functions for tree traversals) :
int main(int argc, char const *argv[])
{
    //Creating a BST with some random values:
    struct BSTnode* root = NULL;

    root = insertnode(root, 5);
    root = insertnode(root, 1);
    root = insertnode(root, 2);
    root = insertnode(root, 3);
    root = insertnode(root, 6);
    root = insertnode(root, 7); 


     printf("Inorder Traversal : ");
     printInorder(root); //Invokes function 'printInorder' which displays the Inorder traversal of the newly created BST.
     printf("\n");

     printf("Preorder Traversal : ");
     printPreorder(root); //Invokes function 'printPreorder' which displays the Preorder traversal of the BST.
     printf("\n");

     printf("Postorder Traversal : ");
     printPostorder(root); //Invokes function 'printPostorder' which displays the Postorder traversal of the BST.

    return 0;
}
