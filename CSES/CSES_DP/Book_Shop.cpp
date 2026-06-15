// dp[k][x] -> max pages bought till ind k with max budget x
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

int func(int ind, int budget, vector<int>& price, vector<int>& pages, vector<vector<int>>& dp){
    if(ind==0){
        if(budget>=price[ind])   return pages[ind];
        else return 0;
    }
    if(dp[ind][budget]!=-1) return dp[ind][budget];
    int pick = 0;
    if(budget>=price[ind])  pick = pages[ind] + func(ind-1, budget-price[ind], price, pages, dp);
    int not_pick = func(ind-1, budget, price, pages, dp);
    return dp[ind][budget] = (max(pick, not_pick))%MOD;
}

void solve()
{
    // Add your code here
    int n, x;  cin>>n>>x;
    vector<int> price(n, 0);
    vector<int> pages(n, 0);
    for(int i=0; i<n; i++)  cin>>price[i];
    for(int i=0; i<n; i++)  cin>>pages[i];
    vector<int> prev(x+1, 0);
    for(int budget=0; budget<= x; budget++){
        if(budget>=price[0])   prev[budget] = pages[0];
    }
    for(int ind=1; ind<n; ind++){
        vector<int> curr(x+1, 0);
        for(int budget=0; budget<=x; budget++){
            int pick = 0;
            if(budget>=price[ind])  pick = pages[ind] + prev[budget-price[ind]];
            int not_pick = prev[budget];
            curr[budget] = (max(pick, not_pick))%MOD;
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