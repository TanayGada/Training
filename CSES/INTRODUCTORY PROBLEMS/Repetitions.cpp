//check if curr ele is same as previous ele
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{ 
    int n = 0;
    string s;
    cin>>s;
    n = s.size();
    if(n==0)   {
        cout<<0<<endl;
        return;
    }
    int cnt = 1, ans = 1;
    for(int i=1;i<n;i++){
        if(s[i-1]==s[i])    cnt++;
        else{
            cnt=1;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
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
