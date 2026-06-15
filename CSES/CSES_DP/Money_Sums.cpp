#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

void func(int ind, int sum, set<int>& st, vector<int>& a, vector<vector<int>>& dp){
    st.insert(sum);
    if(ind<0) return;
    if(dp[ind][sum]!=-1)    return;
    func(ind-1, sum+a[ind], st, a, dp);
    func(ind-1, sum, st, a, dp);
}

void solve()
{
    // Add your code here
    int n;  cin>>n;
    vector<int> a(n,0);
    for(int i=0; i<n; i++)  cin>>a[i];
    set<int> st;
    int sum = 0; 
    for(int i : a)  sum+=i;
    vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
    // func(n-1, 0, st, a, dp);
    // cout<<st.size()-1<<endl;
    dp[0][0] = true;
    for(int ind=1; ind<=n; ind++){
        for(int s=0; s<=sum; s++){
            dp[ind][s] = dp[ind-1][s];
            if(s>=a[ind-1]) dp[ind][s] = dp[ind-1][s-a[ind-1]] || dp[ind][s];
        }
    }
    int cnt = 0;
    for(int i : dp[n]) if(i) cnt++;
    cout<<cnt-1<<endl;
    for(int i=1; i<=sum; i++)   if(dp[n][i])  cout<<i<<" ";
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
