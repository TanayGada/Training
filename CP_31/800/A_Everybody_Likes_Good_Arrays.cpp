/*
if there are 2 consec odd => we multiply to get odd
if there are 2 consec even => we multiply to get even
so if we have eve od od od od ev => we use 3 operation to remove 3 odds
similar for even
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
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(a[i]&1 && a[i+1]&1)  cnt++;
        else if(!(a[i]&1) && !(a[i+1]&1))  cnt++;
    }
    cout<<cnt<<endl;
    
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