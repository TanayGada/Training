//implement the algorithm
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
    cout<<n<<" ";
    while(n!=1){
        if(n&1==1)  {
            n*=3;
            n++;
        }
        else{
            n/=2;
        }
        cout<<n<<" ";
    }
    cout<<"\n";
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
