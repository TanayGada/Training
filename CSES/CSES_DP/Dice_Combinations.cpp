// pick not pick works for combination problems
// this is permutation problem
// dp[k] -> no of ways to get sum k
// i am at k-1, i want to reach k, i need dp[k-1] step and a die 1
// i am at k-2, i want to reach k, i need dp[k-2] step and a die 2
// ..
// i am at k-6, i want to reach k, i need dp[k-6] step and a die 6
// dp[k] = dp[k-1] + dp[k-2] + ... + dp[k-6]
// dp[0] = 1
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;


void solve()
{
    // Add your code here
    int n;  cin>>n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int target=1; target<=n; target++){
        int sum = 0;
        for(int i=1; i<=6; i++){
            if(target-i>=0) sum += dp[target-i];
        }
        dp[target] = (dp[target]+sum)%MOD;
    }
    cout<<dp[n]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;
    // cin>>t;

    while (t--) {
        solve();
    }

    return 0;
}