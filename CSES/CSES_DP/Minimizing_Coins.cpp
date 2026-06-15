// dp[n] = min coins req to get sum n
// i have coins 1 5 7
// i want to make 11
// i have 3 choices, from 11-1, take 1, from 11-5 take 5, from 11-7 take 7
// i want to make 
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

void solve()
{
    // Add your code here
    int n,sum;    cin>>n>>sum;
    vector<int> coins(n, 0);
    for(int i=0; i<n; i++)  cin>>coins[i];
    vector<int> dp(sum+1, INT_MAX);
    dp[0] = 0;
    
    for(int ind=1; ind<=sum; ind++){
        int minCoins = INT_MAX;
        for(int j=0; j<n; j++){
            if(ind>=coins[j]) dp[ind] = min(dp[ind], 1 + dp[ind-coins[j]]);
        }
    }
    if(dp[sum]==(INT_MAX))    cout<<-1<<endl;
    else cout<<dp[sum]<<endl;
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