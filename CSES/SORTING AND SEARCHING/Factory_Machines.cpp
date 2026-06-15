/*
we need to find shortest time to make t products
we know there exists time x such that all time<x required condition fails
and for time>=x the condition satisifies 
we apply binary search on ans to get that x


mini => min_element in array
maxi => (min_element in array)*t
*/
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

bool isPossible(int time, int products, vector<int>& a){
    int noOfProducts = 0;
    for(int i=0;i<a.size();i++){
        noOfProducts += time/a[i];
    }
    if(noOfProducts>=products)  return true;
    return false;
}

void solve()
{
    // Add your code here
    int n,t;    cin>>n>>t;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)    cin>>a[i];
    int mini=*min_element(a.begin(),a.end());
    int maxi=(*min_element(a.begin(),a.end())*t);
    int ans = maxi;
    while(mini<=maxi){
        int mid = mini+((maxi-mini)/2);
        if(isPossible(mid,t,a)){
            maxi = mid-1;
            ans = min(ans, mid);
        }
        else{
            mini = mid+1;
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