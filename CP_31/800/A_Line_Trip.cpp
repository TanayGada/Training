/*
Read Test Cases and get Hints and Understand Question Well
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
    int n,x;    cin>>n>>x;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)    cin>>a[i];

    int maxi = a[0];
    for(int i=0;i<n-1;i++){
        maxi = max(maxi, a[i+1]-a[i]);
    }
    maxi = max(maxi, 2*(x-a[n-1]));
    cout<<maxi<<endl;

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