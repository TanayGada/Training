// lets root tree at node 1
// for node at root, max distance is also the height of tree
// depth[u] = 1 + max(depth[ci]) (ci is children of u)
// for nodes not rooted at node1, ans can be 
// 1. in subtree of that node, -> depth[v]
// 2. in other part of tree -> 1 + partial_ans[parent]
// partial_ans[parent] = max distance for parent considering parent doesnot have child v


#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

void eval_depth(int node, int parent, vector<vector<int>>& adj, vector<int>& depth){
    bool leaf = true;
    int maxChild = 0;
    for(int child : adj[node]){
        if(child==parent)   continue;
        leaf = false;
        eval_depth(child, node, adj, depth);
        maxChild = max(maxChild, depth[child]);
    }
    if(leaf)    depth[node] = 0;
    else depth[node] = 1+maxChild;
}

void get_max_dist(int node, int par, int parAns, vector<vector<int>>& adj, vector<int>& depth, vector<int>& dist){
    vector<int> prefix, suffix;
    for(int child : adj[node]){
        if(child==par)   continue;
        prefix.push_back(depth[child]);
        suffix.push_back(depth[child]);
    }
    for(int i=1; i<prefix.size(); i++)  prefix[i] = max(prefix[i], prefix[i-1]);
    for(int i=suffix.size()-2; i>=0; i--)  suffix[i] = max(suffix[i], suffix[i+1]);

    int child_ind = 0;
    for(int child : adj[node]){
        if(child==par)   continue;
        int op1 = (child_ind==0? INT_MIN : prefix[child_ind-1]);
        int op2 = (child_ind==suffix.size()-1? INT_MIN : suffix[child_ind+1]);
        int partialAns = 1 + max({op1, parAns, op2});
        get_max_dist(child, node, partialAns, adj, depth, dist);
        child_ind++;
    }
    dist[node] = 1 + max(parAns, prefix.size()==0?-1:prefix.back());
}

void solve()
{
    // Add your code here
    int n;  cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=1; i<n; i++){
        int a,b;    cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> depth(n+1, 0);
    vector<int> dist(n+1, 0);
    eval_depth(1, 0, adj, depth);
    get_max_dist(1, 0, -1, adj, depth, dist);
    for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}