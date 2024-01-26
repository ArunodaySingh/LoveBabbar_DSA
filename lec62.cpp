// construct a binary tree and using preorder traversal
#include <bits/stdc++.h>
using namespace std;
class Tree
{
public:
    int data;
    Tree *left = NULL;
    Tree *right = NULL;
    Tree(){};
    Tree(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Tree *buildingTree(Tree *root)
{
    cout << "Enter the data of the node \n";
    int n;
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }
    root = new Tree(n); // It's alloted node a address
    cout << "Enter the left node of the node which have data " << root->data << endl;

    root->left = buildingTree(root->left);
    cout << root->left << endl;
    cout << "Enter the right node of the node which have data " << root->data << endl;
    // cout<<root->right<<endl;
    root->right = buildingTree(root->right);
}

// traverse in preorder
void traverse(Tree *root)
{
    cout << root->data << " ";
    if (root->left != NULL && root->right == NULL)
    {
        traverse(root->left);
    }
    else if (root->left == NULL && root->right != NULL)
    {
        traverse(root->right);
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    else
    {
        traverse(root->left);
        traverse(root->right);
    }
}

// traverse in inorder
void inTraverse(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inTraverse(root->left);

    cout << root->data << " ";
    inTraverse(root->right);
}

// trverse in postorder
void postorder(Tree *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}
// level order traversal
void level_order(Tree *root)
{
    if (root == NULL)
        return;
    queue<Tree *> q;
    q.push(root);
    cout << "Level Order :";
    while (q.empty() == false)
    {
        Tree *temp = q.front();

        cout << temp->data << " ";
        q.pop();
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}
// Delete elemeent in the BT tree
void deletenode(Tree *root, int ele)
{
    if (root == NULL)
        return;
    if (root->data == ele)
    {
        Tree *temp = new Tree();
        temp = root;
    }
    deletenode(root->left, ele);
    deletenode(root->right, ele);
}

int main()
{
    Tree *root = NULL;
    root = buildingTree(root);
    // cout << "Preorder :";
    // traverse(root);
    // cout <<endl<< "Inorder: ";
    // inTraverse(root);
    // cout <<endl<< "Postorder: " ;
    // postorder(root);
    // cout << endl;
    // level_order(root);
    // cout<<endl;
    // deletenode(root,3);
    return 0;
}