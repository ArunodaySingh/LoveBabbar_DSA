// Graph Representation using Adjacency List and map

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph
{
public:
unordered_map<int,list<int>>M;

// insert element in the graph
void insertion(int u,int v,bool isdir)
{
    M[u].push_back(v);
    // 0 for Undirected Graph
    // 1 for Directed Graph
    if(isdir==0)
    {
      M[v].push_back(u);
    }
}

// Print data
void print()
{
    for(auto x:M)
    {
       cout<<x.first<<"-> ";
       for(auto y:x.second)
       {
        cout<<y<<" ";
       }
       cout<<endl;
    }
}

};

int main()
{
 graph obj;
 int n,u,v;
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cin>>u>>v;  
  obj.insertion(u,v,0);
 } 
 obj.print(); 
 return 0;
}

/*
6
0 1
1 2
2 3
3 1
3 4
0 4
*/