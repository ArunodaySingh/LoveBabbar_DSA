// graph traversal using dfs

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class dfs
{
public:
    void insertion(int u, int v, unordered_map<int, list<int>> &adjlist);
    void print(vector<int> &ans);
    void printadj(unordered_map<int, list<int>> &M);
    void performdfs(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &ans, int);
};

// adjecenct list bna lete hai
void dfs::insertion(int u, int v, unordered_map<int, list<int>> &adjlist)
{
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}

// adjence check

void dfs::printadj(unordered_map<int, list<int>> &M)
{
    for (auto x : M)
    {
        cout << x.first << "-> ";
        for (auto y : x.second)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

// print kre le bhai
void dfs::print(vector<int> &ans)
{
    for (auto x : ans)
    {
        cout << x << " ";
    }
}

// dfs peroform krdo
void dfs::performdfs(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    ans.push_back(node);
    visited[node] = 1;
    for (auto x : adjlist[node])
    {
        if (!visited[x])
        {
            performdfs(adjlist, visited, ans, x);
        }
    }
}

int main()
{
    unordered_map<int, list<int>> adjlist; // list idhar hai undirected graph ka
    unordered_map<int, bool> visited;      // visited hai kya
    vector<int> ans;                       // ans idhar milega
    dfs obj;
    cout << "Enter the number of edges " << endl;
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        obj.insertion(u, v, adjlist);
    }

    for (int i = 0; i < adjlist.size(); i++)
    {
        if (!visited[i])
        {
            obj.performdfs(adjlist, visited, ans, i);
        }
    }

    obj.printadj(adjlist);
    obj.print(ans);
    return 0;
}