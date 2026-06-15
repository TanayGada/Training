// a[0] = 1*x + 2*y
// a[1] = 2*x + 1*y
// y = (2*a[0]-a[1])/3 -> where (2*a[0]-a[1]) divisible by 3
// x = 2*a[0] - y
// if the pair is correct then x and y should be positive
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{
    // Add your code here
    vector<int> a(2,0);
    cin>>a[0]>>a[1];
    int y = (2*a[0]-a[1]);
    if((y%3)==0){
        y/=3;
    }
    else{
        cout<<"NO\n";
        return;
    }
    int x = 2*(a[0]-2*y);
    if(x>=0 && y>=0)    cout<<"YES\n";
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