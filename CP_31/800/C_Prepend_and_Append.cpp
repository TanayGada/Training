/*
basic two pointer
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
    string s;   cin>>s;
    int l=0, r=n-1;
    int cnt = 0;
    while(l<r){
        if((s[l]=='0' && s[r]=='1')||(s[l]=='1' && s[r]=='0')){
            cnt+=2;
        }
        else{
            break;
        }
        l++,r--;
    }
    cout<<n-cnt<<endl;
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