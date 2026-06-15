/*
check if string s is substring of x 
if(x.find(s)!= string::npos)    cout<<"s is a substring of x";
else cout<<"s is not a substring of x";
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
    int n,m;    cin>>n>>m;
    string x,s;
    cin>>x>>s;
    int o=5;
    while(o>=0){
        if(x.size()>=s.size()){
            if(x.find(s)!=string::npos){
                cout<<5-o<<endl;
                return;
            }
        }
        o--;
        x.append(x);
    }
    cout<<-1<<endl;
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