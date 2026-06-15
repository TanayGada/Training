/*
try to observe cases
when x!=1   always possible
when x==1{
    if(k==2)    only even n are possible
    if(k>2)     we have (n/2)-1 times 2 and then 1 3
}
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
    int n,k,x;  cin>>n>>k>>x;
    if(k==1 && x==1){
        cout<<"NO\n";
    }
    else if(k==2 && x==1){
        if(n&1) cout<<"NO\n";
        else{
            cout<<"YES\n";
            cout<<n/2<<endl;
            for(int i=0;i<n/2;i++)  cout<<"2 ";
            cout<<endl;
        }
    }
    else if(k>1 && x!=1) {
        cout<<"YES\n";
        cout<<n<<endl;
        for(int i=0;i<n;i++)    cout<<"1 ";
        cout<<endl;
    }
    else if(x==1 && k>2){
        if(n&1){
            cout<<"YES\n";
            cout<<((n+1)/2) - 1<<endl;
            cout<<3<<" ";
            n-=3;
            for(int i=0;i<n/2;i++)  cout<<"2 ";
            cout<<endl;
        }
        else{
            cout<<"YES\n";
            cout<<n/2<<endl;
            for(int i=0;i<n/2;i++)  cout<<"2 ";
            cout<<endl;
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