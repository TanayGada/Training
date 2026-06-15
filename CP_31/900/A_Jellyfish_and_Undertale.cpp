/*
when currTime==1, we add the time from vector to it
if that exceeds a, we add a-1 to currTime to make currTime=a
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
    int a,b,n;  cin>>a>>b>>n;
    vector<int> v(n,0); 
    for(int i=0;i<n;i++)    cin>>v[i];
    int ans = b;
    for(int i=0;i<n;i++){
        if(v[i]<a)  ans+=v[i];
        else    ans+=(a-1);
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