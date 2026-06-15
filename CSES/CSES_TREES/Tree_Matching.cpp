// dp[node][0] -> max size of matching in subtree rooted at "node", such that there is no edge (node, x)
// dp[node][1] -> max size of matching in subtree rooted at "node", such that there is 1 edge (node, x)
// ans is max(dp[root][0], dp[root][1])
// dp[node][0] -> suffix[0] = prefix[n-1] of children
// dp[node][1] -> select 1 edge with a child, rest children return their max 
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

void func(int node, int par, vector<vector<int>>& adj, vector<vector<int>>& dp){
    vector<int> prefix, suffix;
    dp[node][0] = dp[node][1] = 0;
    
    bool leaf = true;
    for(int child : adj[node]){
        if(child==par)  continue;
        leaf = false;
        func(child, node, adj, dp);
    }
    if(leaf) return;

    for(int child : adj[node]){
        if(child==par)  continue;
        prefix.push_back(max(dp[child][0], dp[child][1]));
        suffix.push_back(max(dp[child][0], dp[child][1]));
    }
    for(int i=1; i<prefix.size(); i++)      prefix[i] += prefix[i-1];
    for(int i=suffix.size()-2; i>=0; i--)   suffix[i] += suffix[i+1];
    dp[node][0] = suffix[0];
    int child_number = 0;
    for(int child : adj[node]){
        if(child==par)  continue;
        int leftChildren = (child_number==0? 0 : prefix[child_number-1]);
        int rightChildren = (child_number==prefix.size()-1? 0 : suffix[child_number+1]);
        dp[node][1] = max(dp[node][1], 1 + leftChildren+dp[child][0]+rightChildren);
        child_number++;
    }
}

void solve()
{
    // Add your code here
    int n;  cin>>n;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> dp(n+1, vector<int> (2));
    for(int i=1; i<n; i++){
        int a,b;    cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    func(1, 0, adj, dp);
    cout<<max(dp[1][0], dp[1][1])<<endl;

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