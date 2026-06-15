/*
is_sorted() => to check if an array is sorted 
*/

#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;


bool isSorted(vector<int> &a){
    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i]>a[i+1])    return false;
    }
    return true;
}

void solve()
{
    // Add your code here
    int n,k;    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    if(k==1 && !is_sorted(a.begin(), a.end())){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES\n";
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