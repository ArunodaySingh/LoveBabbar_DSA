#include <iostream>
using namespace std;

class bst
{
public:
    int _id;
    int salary;
    bst *left;
    bst *right;
    bst(){};
    bst(int id, int data)
    {
        _id = id;
        salary = data;
        left = NULL;
        right = NULL;
    }
};

bst *insertion(bst *root, int id, int salary)
{
    // root ka dekh lo
    if (root == NULL)
    {
        root = new bst(id, salary);
        return root;
    }

    // left dekh  lo
    if (root->salary > salary)
    {
        root->left = insertion(root->left, id, salary);
    }
    // righ dekh lo
    else
    {
        root->right = insertion(root->right, id, salary);
    }
}

int searching(bst *root)
{
    bst *temp = new bst();
    temp = root;
    int max = temp->salary;
    while (temp != NULL)
    {
        max = temp->_id;
        temp = temp->right;
    }
    return max;
}

int main()
{
    bst *root = NULL;
    int sal, id;
    cout << "Enter the id and salary " << endl;
    cin >> id >> sal;
    while (sal != -1 || id != -1)
    {
        root = insertion(root, id, sal);
        cout << "Enter the id and salary " << endl;
        cin >> id >> sal;
    }
    cout << "Maximum salary of the employee id is  " << searching(root);
    return 0;
}