// diameter can be one of 2 cases
// 1. current node is part of diameter -> start/end in left/right subtree -> 2 + top 2 longest path in children
// 2. current node is not part of diameter -> diameter path in left/right subtree -> max(downPath over all children)
// need downPath/height of each node

#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

void evalDownwardDistance(int node, int par, vector<vector<int>>& adj, vector<int>& downDist){
    bool leaf = true;
    int bestChild = 0;
    for(int child : adj[node]){
        if(child==par)  continue;
        leaf = false;
        evalDownwardDistance(child, node, adj, downDist);
        bestChild = max(bestChild, downDist[child]);
    }
    if(leaf)    downDist[node] = 0;
    else downDist[node] = 1+ bestChild;
}

void calculateDiameter(int node, int par, vector<vector<int>>& adj, vector<int>& downDist, int& diamater){
    vector<int> childrenDownPath;
    for(int child : adj[node]){
        if(child==par)  continue;
        calculateDiameter(child, node, adj, downDist, diamater);
        childrenDownPath.push_back(downDist[child]);
    }
    sort(childrenDownPath.begin(), childrenDownPath.end());
    int childrenCount = childrenDownPath.size();
    int ans = downDist[node];
    if(childrenCount==0);
    else if(childrenCount==1)   ans = max(ans, 1 + childrenDownPath[0]);
    else ans = 2 + childrenDownPath[childrenCount-1] + childrenDownPath[childrenCount-2];
    diamater = max(diamater, ans);
}

void solve()
{
    // Add your code here
    int n;  cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=1; i<n; i++){
        int a, b;   cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> downDist(n+1, 0);
    evalDownwardDistance(1, 0, adj, downDist);
    int diameter = 0;
    calculateDiameter(1, 0, adj, downDist, diameter);
    // cout<<"downDist: ";
    // for(int i : downDist)   cout<<i<<" ";
    // cout<<endl;
    cout<<diameter<<endl;

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