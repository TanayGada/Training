// total number of ways of placing 2 knights on nx board = ((n*n) * (n*n-1))/2
// divide by 2 because both knight are same
// number of attacking positions = 2x3 and 3x2 grids in four directons from a particular knight
// 2x3 and 3x2 can be made in (n-1)*(n-2) ways
//total attacking positions = 4*(n-1)*(n-2)
//ans = ((n*n) * (n*n-1))/2 - 4*(n-1)*(n-2)
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{ 
    int r;
    cin>>r;
    for(int n=1; n<=r; n++){
        int firstTerm = ((n*n)*((n*n)-1))/2;
        int secondTerm = (4*(n-1)*(n-2));
        cout<<firstTerm - secondTerm<<endl;
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
