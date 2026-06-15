/*
1st condition => there are more(or equal) +1 than -1
2nd condition => there are even number of -1
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
    int n;  cin>>n;
    int minus=0, plus=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==-1)   minus++;
        else    plus++;
    }
    if(plus>=minus){
        if(minus&1) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else{
        int d = minus-plus;
        minus-=((d+1)/2);
        plus+=((d+1)/2);
        if(minus&1) cout<<((d+1)/2)+1<<endl;
        else cout<<((d+1)/2)<<endl;
        
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