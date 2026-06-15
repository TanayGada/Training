#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

int func(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& dp){
    if(i==0 && j==0)    return 1;
    if(i<0 || j<0)  return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    int up = 0;
    int left = 0;
    if(i>0 && grid[i][j]=='.') up = func(i-1, j, grid, dp);
    if(j>0 && grid[i][j]=='.') left = func(i, j-1, grid, dp);
    return dp[i][j] = (up+left)%MOD;
}

void solve()
{
    // Add your code here
    int n;  cin>>n;
    vector<vector<char>> grid(n, vector<char> (n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)  cin>>grid[i][j];
    }
    if(grid[0][0]=='*' || grid[n-1][n-1]=='*'){
        cout<<0<<endl;
        return;
    }
    vector<vector<int>> dp(n, vector<int> (n,-1));
    cout<<func(n-1, n-1, grid, dp)<<endl;

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