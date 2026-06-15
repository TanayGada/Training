// store # children nodes for each root
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;


int func(int node, vector<vector<int>>& adjList, vector<int>& ans){
    int cnt = 0;
    for(int i : adjList[node]){
        cnt += (1+func(i, adjList, ans));
    }
    return ans[node] = cnt;
}

void solve()
{
    // Add your code here
    int n;  cin>>n;
    vector<vector<int>> adjList(n+1);
    for(int i=2; i<=n; i++){
        int a;  cin>>a;
        adjList[a].push_back(i);
    }
    vector<int> ans(n+1, 0);
    func(1, adjList, ans);
    for(int i=1; i<ans.size(); i++)    cout<<ans[i]<<" ";
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