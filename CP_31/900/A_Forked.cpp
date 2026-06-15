/*
any coordinate can be approached by a knight in 8 ways
so we get those 8 ways for both king and queen and then take intersection

alternatively we can visualize x and y coordinate of king and queen separately
if dist = dist(kx,qx) = abs(kx-qx),
we need knight somewhere in between kz and qx kuch that abs(kx,x)+abs(qx,x)=dist
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
    int a,b;    cin>>a>>b;
    int kx,ky;  cin>>kx>>ky;
    int qx,qy;  cin>>qx>>qy;
    int cnt = 0;
    vector<pair<int,int>> moves = {{a,b}, {b,a},{-a,b}, {-b,a}, {a,-b},{b,-a},{-a,-b},{-b,-a}};
    for(auto [x,y] : moves){
        int u = abs(kx-qx+x);
        int v = abs(ky-qy+y);
        if((u==a && v==b)||(u==b && v==a)){
            cnt++;
        }
    }
    if(a==b){
        cnt/=2;
    }
    cout<<cnt<<endl;

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