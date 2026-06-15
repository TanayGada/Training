
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

int mth_power_of_n(int n, int m){
    if(m==0)    return 1;
    int a = mth_power_of_n(n, m/2);
    if(m&1){
        return n*a*a;
    }
    else return a*a;
    
}

void solve()
{
    // Add your code here
    int m = 3, n = 7;
    cout<<mth_power_of_n(n, m)<<endl;
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