/*
If n is even it is possible
If n is odd{
    n>k and k must be odd
}
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
    if(n&1){
        if(k&1 && n>=k)  cout<<"YES\n";
        else cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
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