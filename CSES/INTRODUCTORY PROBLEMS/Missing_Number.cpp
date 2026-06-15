//summation of 1 to n numbers - summation of given n-1 numbers
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
    vector<bool> num(n+1,false);
    for(int i =0;i<n-1;i++){
        int x=0;
        cin>>x;
        num[x] = true;
    }
    for(int i=1;i<=n;i++){
        if(num[i]==false)  cout<<i<<endl;
    }
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
