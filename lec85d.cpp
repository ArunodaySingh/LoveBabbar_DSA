// Using Adjacency matrix

#include <bits/stdc++.h>
using namespace std;
class graph
{

public:
    int mat[4][4];
    void insertion();
    void print();
};

void graph::insertion()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Graphs connected from vertex " << i << endl;
        for (int j = 1; j < 4; j++)
        {
            int n;
            cout << "Enter 0 for Not connected or 1 for connected to vertex " << j << endl;
            cin >> n;
            if (n == 0)
            {
                mat[i][j] = 0;
            }
            else
            {
                mat[i][j] = 1;
                mat[j][i] = 1;
            }
        }
    }
}

void graph::print()
{
    for (int i = 0; i < 4; i++)
    {
        cout << i << "-> ";
        for (int j = 0; j < 4; j++)
        {
            if (mat[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    graph obj;
    obj.insertion();
    obj.print();
}

// 1
// 0
// 1
// 0
// 1
// 0
// 1
// 0
// 0
// 0
// 1
// 0