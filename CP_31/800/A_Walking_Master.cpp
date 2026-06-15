/*
s => startPosition (a,b)
x => finalDestination   (c,d)
if x is below s => not possible => (d<b)
if x is at right-bottom side of diagonal from s => not possible => c-a>d-b
otherwise always possible 
height = d-b, width = c-a
    moves=2*height-width
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
    int a,b,c,d;    cin>>a>>b>>c>>d;
    if((d<b)||(a<c && ((c-a)>(d-b)))) cout<<-1<<endl;
    else{
        int h = d-b, w = c-a;
        cout<<2*h-w<<endl;
        
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