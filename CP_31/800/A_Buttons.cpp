#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{
    // Add your code here
    int a,b,c;  cin>>a>>b>>c;
    if(c&1){
        //First wins unless b>a
        if(b>a){
            cout<<"Second\n";
        }
        else{
            cout<<"First\n";
        }
    }
    else{
        //Second Wins unless a>b
        if(a>b){
            cout<<"First\n";
        }
        else{
            cout<<"Second\n";
        }
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