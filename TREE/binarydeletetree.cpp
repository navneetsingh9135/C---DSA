#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *inorderSucc(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node *deleteInBST(node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

// Inorder traversal of the BST
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteInBST(root, 5);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
