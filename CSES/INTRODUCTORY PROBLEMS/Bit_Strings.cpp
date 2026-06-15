// a^b where b is large
// binary exponentiation where if b is odd -> a^b = a * a^(b-1) where b-1 is even
//when b is even -> a^b = (a^2)^(b/2)
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;


int binaryExponential(int a, int b){
    int ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*1ll*a)%MOD;
            b--;
        }
        else{
            a = (a*1ll*a)%MOD;
            b /= 2;
        }
    }
    return ans;
}


void solve()
{
    int n;
    cin>>n;
    int ans = binaryExponential(2, n);
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
