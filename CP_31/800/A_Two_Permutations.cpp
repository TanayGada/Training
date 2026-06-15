/*
if a+b+2 <= n, we find 2 permutations always
also if both permutation are equal then a==b==n
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
    int a,b;
    cin>>a>>b;`
    if((a+b+2<=n) || (a==b && b==n)){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
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