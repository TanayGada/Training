// make the grid of size 5x5 and notice elements at top and left side
// there are perfect squares and both sides and the x==y line divides the grid
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{ 
    int y,x;
    cin>>x>>y;
    if(x<y){
        int iniAns = 0;
        if(y&1){
            iniAns = y*y;
            iniAns -=(x-1);
        }
        else{
            iniAns = (y-1)*(y-1)+1;
            iniAns += (x-1);
        }
        cout<<iniAns<<endl;
        
    }
    else {
        int iniAns = 0;
        if(!(x&1)){
            iniAns = x*x;
            iniAns -= (y-1);
        }
        else{
            iniAns = (x-1)*(x-1)+1;
            iniAns += (y-1);
        }
        cout<<iniAns<<endl;

    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    cin>>t;
    
    while(t--){
        solve();
    }

    return 0;
}
