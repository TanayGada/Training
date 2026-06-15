/*
Initially all teams have 0 score
So after all matches the sum of scores should also be 0
*/

#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{
    // Add your code here
    int n;  cin>>n;
    int ans = 0;
    for(int i=0;i<n-1;i++){
        int a =0;
        cin>>a;
        ans+=a;
    }
    cout<<-ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}