#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{ 
     freopen("cowsignal.in", "r", stdin);
    int m,n,k;  cin>>m>>n>>k;
    
    vector<string> input(m," ");
    for(int i=0;i<m;i++){
        string a;
        cin>>a;
        for(int j=0;j<n;j++){
            input[i][j] = a[j];
        }   
    }
    freopen("cowsignal.out", "w", stdout);
    for(int i=0;i<m;i++){
        for(int l = 0; l<k; l++){
            for(int j=0;j<n;j++){
                for(int q = 0; q<k; q++){
                    cout<<input[i][j];
                }
            }
            cout<<endl;
        }
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
