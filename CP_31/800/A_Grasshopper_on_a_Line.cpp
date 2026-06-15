/*
if(k==1)    not possible
if(k>x)     1 move i.e. x
if(x%k==0)  2 moves i.e. x-1, 1
if(x%k!=0)  1 move i.e. x
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
    int x,k;    cin>>x>>k;
    if(k>x){
        cout<<1<<endl<<x<<endl;
    }
    else if(x%k){
        cout<<1<<endl<<x<<endl;
    }
    else{
        cout<<2<<endl<<x-1<<" "<<1<<endl;
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