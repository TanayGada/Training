/*
if previous ele is greater than curr, then its beautiful
but in case of repeating nums
if first and second numbers are same, then its not beautiful else always beautiful
so we can have largest ele at 1st and smallest ele at 2nd and then anything 
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
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(a[0]==a[n-1]){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    cout<<a[n-1]<<" "<<a[0]<<" ";
    for(int i=1;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
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