#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{
    // Add your code here
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n,m;    cin>>n>>m;
    vector<int> limit(100,0);
    vector<int> bessie(100,0);
    int ini = 0;
    for(int i=0;i<n;i++){
        int a,b;    cin>>a>>b;
        for(int j=ini; j<ini+a; j++){
            limit[j] = b;
        }
        ini += a;
    }
    int in = 0;
    for(int i=0;i<m;i++){
        int a,b;    cin>>a>>b;
        for(int j=in; j<in+a; j++){
            bessie[j] = b;
        }
        in += a;
    }
    int ans = 0;
    for(int i=0;i<100;i++){
        ans = max(bessie[i] - limit[i], ans);
    }
    cout<<ans<<endl;

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