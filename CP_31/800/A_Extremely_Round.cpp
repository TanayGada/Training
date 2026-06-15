/*
from 0 to 9 there are 9 specNums
from 10 to 99 there are 9 specNums
from 100 to 999 there are 9 specNums
..
..

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
    while(n){
        ans += min(n,9ll);
        n/=10;
    }
    cout<<ans<<endl;
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