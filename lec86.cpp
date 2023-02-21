// Traversing using BFS
/*
Like if we have a graph we need to traverse one by one according to the level
and as we know for that we need queue which take one element show the result and take its child in the queue as we do in
level order traversal 
another ds we want here which take a node and bool so we get to know which element already visited;
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class bfs
{
public:
void insertion(int u,int v,unordered_map<int,list<int>>&adjlist);
void print(vector<int>&ans);
void performbfs(unordered_map<int,list<int>>&adjlist , unordered_map<int,bool>&visited , vector<int>&ans,int  );
};

// adjecenct list bna lete hai
void bfs::insertion(int u,int v,unordered_map<int,list<int>>&adjlist)
{
adjlist[u].push_back(v);
adjlist[v].push_back(u);
}

// priny kre le bhai
void bfs::print(vector<int>&ans)
{
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
}

// bfs peroform krdo
void bfs:: performbfs(unordered_map<int,list<int>>&adjlist , unordered_map<int,bool>&visited , vector<int>&ans,int node )
{
    queue<int>q;
    q.push(node);
    visited[node]=1;  // because nodes sequence mein hai
    while(!q.empty()) // 5 step jo kaam bnade asan
    {
        int frontnode=q.front();
        q.pop(); 
        ans.push_back(frontnode);
        for(auto x:adjlist[frontnode])
        {
          if(!visited[x])
          {
             q.push(x);
             visited[x]=1;
          }
        }
       

    }
}

int main()
{
 unordered_map<int,list<int>>adjlist; // list idhar hai undirected graph ka
 unordered_map<int,bool>visited; // visited hai kya
 vector<int>ans; // ans idhar milega
 bfs obj;
 cout<<"Enter the number of vertex "<<endl;
 int n,u,v;
 cin>>n;
 for(int i=0;i<n;i++)
 {
    cin>>u>>v;
    obj.insertion(u,v,adjlist);
 }

 for(int i=0;i<n;i++)
 {
    if(!visited[i])
    {
       obj.performbfs(adjlist , visited , ans,i );
    }
 }

 obj.print(ans);
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