/*
Considering taking input in suitable data structures
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
    int n, k;   cin>>n>>k;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int a =0;
        cin>>a;
        mp[a]++;
    }
    if(mp[k]==0)    cout<<"NO\n";
    else cout<<"YES\n";
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