// func(ind, prev) -> no of arrays possible till index ind, such that next element is prev
// dp[ind][x] = no of valid arrays till ind which have x at index ind 
// final ans is sum(dp[n-1][1...x])
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;
 
// int func(int ind, int nxt, int m, vector<int>& a, vector<vector<int>>& dp){
//     if(ind<0) return 1;
 
//     if(ind<a.size()-1 && dp[ind][nxt]!=-1)   return dp[ind][nxt];
//     if(ind==a.size()-1){
//         if(a[ind]==0){
//             int cnt=0;
//             for(int i=1; i<=m; i++){
//                 cnt = (cnt + func(ind-1, i, m, a, dp))%MOD;
//             }
//             return dp[ind][nxt] = cnt; 
//         }
//         else{
//             return dp[ind][nxt] = func(ind-1, a[ind], m, a, dp)%MOD;
//         }
//     }
//     if(a[ind]==0){
//         int cnt=0;
//         for(int i=1; i<=m; i++){
//             if(abs(i-nxt)<=1)  cnt = (cnt + func(ind-1, i, m, a, dp))%MOD;
//         }
//         return dp[ind][nxt] = cnt;
//     }
//     else{
//         if(abs(a[ind]-nxt)<=1){
//             return dp[ind][nxt] = func(ind-1, a[ind], m, a, dp)%MOD;
//         }
//         else return dp[ind][nxt]=0;
//     }
// }
 
void solve()
{
    // Add your code here
    int n,m;    cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0; i<n; i++)  cin>>a[i];
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    // cout<<func(n-1, 0, m, a, dp)<<endl;
    if(a[0]==0) for(int i=1; i<=m; i++) dp[1][i]=1;
    else dp[1][a[0]] = 1;
    for(int ind=2; ind<=n; ind++){
        for(int x=1; x<=m; x++){
            if(a[ind-1]==0){
                int prev = 0, curr = dp[ind-1][x], next = 0;
                if(x-1>=0)  prev = dp[ind-1][x-1];
                if(x+1<=m) next = dp[ind-1][x+1];
                dp[ind][x] = (prev + curr + next)%MOD;
            }
            else if(a[ind-1]==x){
                int prev = 0, curr = dp[ind-1][x], next = 0;
                if(x-1>=0)  prev = dp[ind-1][x-1];
                if(x+1<=m) next = dp[ind-1][x+1];
                dp[ind][x] = (prev + curr + next)%MOD;
            }
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    int ans = 0;
    for(int i : dp[n])    ans=(ans+i)%MOD;
    cout<<ans<<endl;
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