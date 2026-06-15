/*
if there are x nums with odd freq;
if we remove atleast x-1 nums, we can have palindromic string
so k should be greater than equal to x-1
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
    int n, k;   cin>>n>>k;
    string s= "";   cin>>s;
    map<int,int> mp;
    for(int i=0;i<n;i++)    mp[s[i]]++;
    int odd =0 , even=0;
    for(auto i : mp){
        if(i.second&1)  odd++;
        else even++;
    }
    if(odd>k+1){
        cout<<"NO\n";
    }
    else    cout<<"YES\n";
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