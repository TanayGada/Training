/*
Catch here is that we can xor all elements with x and not 1
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
    vector<int> a(n,0);
    int ans = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans^=a[i];
    }
    if(n&1){
        cout<<ans<<endl;
    }
    else{
        if(ans==0)  cout<<0<<endl;
        else cout<<-1<<endl;
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