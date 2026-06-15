#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

vector<int> getDigits(int n){
    vector<int> a;
    while(n>0){
        if(n%10!=0) a.push_back(n%10);
        n/=10;
    }
    return a;
}

// memoized
int func(int n, vector<int>& dp){
    if(n==0)    return 0;
    if(dp[n]!=-1)   return dp[n];
    vector<int> a = getDigits(n);
    int val = INT_MAX;
    for(int i : a){
        if(n-i>=0)
        val = min(1+func(n-i, dp), val);
    }
    return dp[n] = val;
}

void solve()
{
    // Add your code here
    int n;  cin>>n;
    vector<int> dp(n+1, 0);
    // cout<<func(n, dp)<<endl;
    for(int i=1; i<=n; i++){
        vector<int> a = getDigits(i);
        int val = INT_MAX;
        for(int x : a){
            if(i-x>=0)
            val = min(1+func(i-x, dp), val);
        }
        dp[i] = val;
    }
    cout<<dp[n]<<endl;
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