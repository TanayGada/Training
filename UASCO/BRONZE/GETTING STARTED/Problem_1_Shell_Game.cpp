/*
We consider box number and ele in Box separately
*/
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{ 
    freopen("shell.in", "r", stdin);
    int n;  cin>>n;
    vector<int> eleInBox(4,0);
    eleInBox[1] = 1;
    eleInBox[2] = 2;
    eleInBox[3] = 3;
    vector<int> cnt(4,0);
    for(int i=0;i<n;i++){
        int a,b,c;    cin>>a>>b>>c;
        swap(eleInBox[a], eleInBox[b]);
        cnt[eleInBox[c]]++;
    }
    freopen("shell.out", "w", stdout);
    cout<<max(cnt[1], max( cnt[2], cnt[3]))<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    
    
    while(t--){
        solve();
    }

    return 0;
}
