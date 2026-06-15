/*
we can select all nums such that mini<=nums<=maxi
we need to find mini which is sum of first k nums
maxi is sum of last k nums
sum of last k nums = nums of n nums - sum of n-k nums
                   = n*(n+1)/2 - (n-k)(n-k+1)/2 = ((n2 + n) - (n2 -nk + n -nk +k2 - k))/2
                   = (2nk + k - k2)/2     
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
    int n, k, x;    cin>>n>>k>>x;
    int mini = (k*(k+1))/2;
    int maxi = (2*n*k + k - k*k)/2;
    if(mini<=x && x<=maxi)  cout<<"YES\n";
    else cout<<"NO\n";
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