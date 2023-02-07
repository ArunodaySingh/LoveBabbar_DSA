// Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(){};
    Tree(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Tree Generator
Tree *BuildingTree(Tree *root, int data)
{
    // Base case
    if (root == NULL)
    {
        root = new Tree(data);
        return root;
    }

    // left dekh lunga
    if (root->data > data)
    {
        root->left = BuildingTree(root->left, data);
    }
    // right dekh lunga
    else
    {
        root->right = BuildingTree(root->right, data);
    }
}

// Input Handler
Tree *takeInput(Tree *root)
{
    cout << "Enter the Parent node data \n";
    int n;
    cin >> n;
    while (n != -1)
    {
        root = BuildingTree(root, n);
        cin >> n;
    }
    return root;
}

// level order traversal
void traverse(Tree *root)
{
    if (root == NULL)
        return;
    queue<Tree *> q;
    q.push(root);
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
    cout << endl;
}

// Inorder Traversal
void Intraverse(Tree *root)
{
    // Base case
    if (root == NULL)
        return;
    Intraverse(root->left);
    cout << root->data << " ";
    Intraverse(root->right);
}

// search in tree
bool search(Tree *root, int n)
{
    Tree *temp = new Tree();
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            // cout<<temp->data;
            return true;
        }
        else if (temp->data > n)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}

// find min value
Tree *minVal(Tree *root)
{
    // base class
    if (root == NULL)
        return NULL;
    Tree *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// delete element from BST
Tree *deleteEle(Tree *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
    {
        // case1
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case2
        if (root->left != NULL && root->right == NULL)
        {
            Tree *temp = root->left;
            delete root;
            return temp;
        }
        // case3
        if (root->right != NULL && root->left == NULL)
        {
            Tree *temp = root->right;
            delete root;
            return temp;
        }
        // case4
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteEle(root->right, mini);
            return root;
        }
    }
    else if (root->data > data)
    {
        root->left = deleteEle(root->left, data);
        return root;
    }
    else
    {
        root->right = deleteEle(root->right, data);
        return root;
    }
}

// Inorder Predecessor
/*
First approach is to store it in a queue aur stack
and get predecessor from there.
*/
void InorderPre(Tree *root, int data)
{
    Tree *temp = NULL;
    while (root != NULL)
    {
        if (data <= root->data)
        {
            root = root->left;
        }
        else
        {
            temp = root;
            root = root->right;
        }
    }
    cout << "Inorder Pre " << temp->data << endl;
}

// Inorder Successor
void InorderSuc(Tree *root, int data)
{
    Tree *suceesor = NULL;
    while (root != NULL)
    {
        if (data >= root->data)
        {
            root = root->right;
        }
        else
        {
            suceesor = root;
            root = root->left;
        }
    }
    cout << "Inorder Suc :" << suceesor->data << endl;
}

// Main function
int main()
{
    Tree *root = NULL;
    Tree *root1 = NULL;
    Tree *pre = NULL;
    root1 = takeInput(root);
    traverse(root1);   // using level order traversal
    Intraverse(root1); // inorder traversal
    cout << "\n  Enter the data which you want to search \n";
    int n;
    cin >> n;
    cout << search(root1, n) << endl;
    cout << " Enter the data which you want to delete \n";
    cin >> n;
    deleteEle(root1, n);
    traverse(root1);
    cout << " Enter the data which successor you want \n";
    cin>>n;
    InorderSuc(root1, n);
    InorderPre(root1, n);

    return 0;
}