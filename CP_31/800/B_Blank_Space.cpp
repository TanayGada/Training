/*
Basic Implementation
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
    for(int i=0;i<n;i++)    cin>>a[i];
    int cnt = 0, ans=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cnt++; 
        }
        else cnt=0;
        ans = max(ans, cnt);
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