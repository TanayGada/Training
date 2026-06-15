// if curr element is smaller than previous element we make it equal to prev element
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{ 
    int n;
    cin>>n;
    vector<int> s(n,0);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    if(n==0){
        cout<<0<<endl;
        return;
    }
    int cnt = 0;
    for(int i = 1; i<n; i++){
        if(s[i-1]>s[i]){
            cnt += (s[i-1] - s[i]);
            s[i] = s[i-1];
        }
    }
    cout<<cnt<<endl;
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
