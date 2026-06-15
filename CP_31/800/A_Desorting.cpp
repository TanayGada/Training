/*
We see that if ai and ai+1 has d difference
We increase a0, a1, ..., ai by 1 for d/2 times
and decrease ai+1, ai+2, ..., an-1 by 1 for d/2 times
this makes ai === ai+1 => but we want to desort it => so need one more operation
so ceil(d/2)
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
    int n=0;    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(!is_sorted(a.begin(),a.end()))   cout<<"0\n";
    else{
        int mini = INT_MAX;
        for(int i=0;i<n-1;i++){
            mini = min(mini, (a[i+1]-a[i]+2)/2);
        }
        cout<<mini<<endl;
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