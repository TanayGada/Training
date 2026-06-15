// dp[k] -> distinct ways of making sum k
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

void solve()
{
    // Add your code here
    int n, x;   cin>>n>>x;
    vector<int> coins(n,0);
    for(int i=0; i<n; i++)  cin>>coins[i];
    vector<int> prev (x+1, 0);
    for(int target=0; target<=x; target++) if(target%coins[0]==0)   prev[target] = 1;
    for(int ind=1; ind<n; ind++){
        vector<int> curr (x+1, 0);
        for(int target=0; target<=x; target++){
            int pick = 0;
            if(target>=coins[ind])  pick = curr[target-coins[ind]];
            int not_pick = prev[target];
            curr[target]=(pick+not_pick)%MOD;
        }
        prev = curr;
    }
    cout<<prev[x]<<endl;

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