// dp[k] -> combi allowed to make sum k
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

void solve()
{
    // Add your code here
    int n,x;    cin>>n>>x;
    vector<int> c(n,0);
    for(int i=0; i<n; i++)  cin>>c[i];
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int i=1; i<=x; i++){
        for(int coin : c){
            if(i>=coin) dp[i] = (dp[i] + dp[i-coin])%MOD;
        }
    }
    cout<<dp[x]<<endl;

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