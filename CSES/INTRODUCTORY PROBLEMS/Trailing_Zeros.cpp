// trailing zeros means factorial have 10 as a factor
// 10 = 2*5
// 2 is in abundance, 5 is scarce
// count the total number of 5s in prime factors of n! -> floor(n/5)
// Trailing 0s in n! = Count of 5s in prime factors of n! = floor(n/5) + floor(n/25) + floor(n/125) + ..

#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve(){
    int n = 0;  cin>>n;
    int cnt = 0;
    for(int i=5; i<=n; i*=5){
        cnt += n/i;
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
