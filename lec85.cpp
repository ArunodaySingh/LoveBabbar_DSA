// Graph Representation using Adjacency List and vector

#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    vector<int> p[5];
    vector<vector<int>> v1;
    graph()
    {
        v1 = vector<vector<int>>(5);  // initialize inside a constructor it's doesnt work without constructor
    }

    void insertadj()
    {
        // undirected graph -> 0
        // directed graph ->
        cout << "Enter the nodes \n";
        for (int i = 0; i < 6; i++)
        {

            int u, v;
            cin >> u >> v;
            p[u].push_back(v);
            p[v].push_back(u);
        }
        for (int i = 0; i < 5; i++)
        {
            v1[i].push_back(i);
            for (int j = 0; j < p[i].size(); j++)
            {
                v1[i].push_back(p[i][j]);
            }
        }
    }
    void print()
    {
       for(int i=0;i<v1.size();i++)
       {
         cout<<v1[i][0]<<"-> ";
        for(int j=1;j<v1[i].size();j++)
        {
             cout<<v1[i][j]<<" ";
        }
        cout<<endl;
       }
     
    }
};

int main()
{
    graph obj;
    obj.insertadj();
    obj.print();
    return 0;
}

/*
0 1
1 2
2 3
3 1
3 4
0 4
*/

/*
The code vector<vector<int>> v1[5]; declares an array v1 of size 5,
where each element of the array is a vector of vectors of integers.
This means that v1 is an array of 5 elements, where each element can hold a collection of vectors of integers.
Each individual vector can be accessed by using the standard vector indexing syntax.

The code vector<vector<int>> v1(5);
declares a vector v1 that contains 5 elements, where each element is itself a vector of integers.

The two statements vector<vector<int>> v1[5]; and vector<vector<int>> v1(5); are similar in that they both involve a vector of vectors of integers, but they are used to accomplish different tasks.

The first statement vector<vector<int>> v1[5]; declares an array of 5 vectors, where each vector can hold a collection of vectors of integers.
This is useful when you need to store a fixed number of vectors,each of which can have a variable number of integers.
You can access the vectors using array indexing syntax, for example, v1[0][1] would give you the second vector in the first element of the array.

The second statement vector<vector<int>> v1(5); declares a vector with 5 elements, where each element is itself a vector of integers.
This is useful when you need a dynamic array where you know the number of vectors in advance,
but the size of each vector may vary. You can access the elements using the standard vector indexing syntax, for example, v1[1][2] would give you the third element of the second vector in the vector v1.
*/