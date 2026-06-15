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
    int odd=0, even=0;
    for(int i=0;i<n;i++){
        int ele = 0;
        cin>>ele;
        if(ele&1)   odd++;
        else even++;
    }
    if(odd&1)   cout<<"NO\n";
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