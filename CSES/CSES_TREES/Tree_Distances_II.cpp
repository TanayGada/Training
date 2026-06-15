// for root node "node1", subtreeSum = sum[child1] + cnt[child1] ...for all children
// subtreeSum[child1] = sum of distances of all nodes in subtree rooted at child1
// noOfNodes[child1] = no of nodes in subtree rooted at child1
// using this, ans[child1] = sumOfSubtreeum[child1] + partial_ans[child1] + (totalNodes-noOfNodes[child1]))
// partial_ans[child1] = (ans[parent]-sumOfSubtreeum[child1]-noOfNodes[child1])
// 1. sumOfSubtreeum and noOfNodes -> preprocesing
// 2. calculate ans
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

void preprocessing(int node, int parent, vector<vector<int>>& adj, vector<int>& subtreeSum, vector<int>& subtreeSize){
    int noOfNodes = 1;
    int sumOfSubtree = 0;
    for(int child : adj[node]){
        if(child==parent)   continue;
        preprocessing(child, node, adj, subtreeSum, subtreeSize);
        noOfNodes+= subtreeSize[child];
        sumOfSubtree += subtreeSum[child]+subtreeSize[child];
    }
    subtreeSize[node] = noOfNodes;
    subtreeSum[node] = sumOfSubtree;
}

void calculateDist(int node, int parent, int partial_ans, int totalNodes, vector<vector<int>>& adj, vector<int>& subtreeSum, vector<int>& subtreeSize, vector<int>& ans){
    ans[node] = subtreeSum[node] + partial_ans + (totalNodes - subtreeSize[node]);
    for(int child : adj[node]){
        if(child==parent)   continue;
        calculateDist(child, node, ans[node]-subtreeSum[child]-subtreeSize[child], totalNodes, adj, subtreeSum, subtreeSize, ans);
    }
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
    vector<int> subtreeSum(n+1, 0);
    vector<int> subtreeSize(n+1, 0);
    vector<int> ans(n+1, 0);
    preprocessing(1, 0, adj, subtreeSum, subtreeSize);
    // for(int i : subtreeSum) cout<<i<<" ";
    // cout<<endl;
    // for(int i : subtreeSize) cout<<i<<" ";
    // cout<<endl;
    calculateDist(1, 0, 0, n, adj, subtreeSum, subtreeSize, ans);
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;

}
    //     1
    // 2       3
    //       4   5

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