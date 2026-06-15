// odd numbers followed by even numbers -> 1 3 5 2 4
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
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==4){
        cout<<"2 4 1 3\n";
        return;
    }
    if(n==2 || n==3){
        cout<<"NO SOLUTION\n";
        return;
    }
    for(int i =1;i<=n;i+=2){
        cout<<i<<" ";
    }
    for(int i = 2; i<=n; i+=2){
        cout<<i<<" ";
    }
    cout<<endl;
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
