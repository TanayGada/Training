/*
binary search on ans(1 to nxn)
fir every row me another binary search (1*i to n*i) to calculate how many ele are smaller than val from 1st BS

predicate function => if x<median   false
                   => if x>=median  true
we need smallest true value

we can elminate 2nd BS by using maths
maths here is every row has mid/i values less than mid
*/
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

bool isPossible(int mid, int n){
    int noOfEle = 0;
    for(int i=1;i<=n;i++){
        noOfEle += min(mid/i,n);
    }
    if(noOfEle>((n*n)/2))  return true;
    return false;
}

void solve()
{
    // Add your code here
    int n;
    cin>>n;
    int low = 1, high = n*n;
    int ans = 1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(mid, n)){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}