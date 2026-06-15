/*
we need to check gcd of first 2 numbers of the final sequence, whether it is beautiful or not
i.e. there should be atleast one pair such that gcd(ai,aj)<=2
*/
#include<bits/stdc++.h>
#include <numeric>
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
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(gcd(a[i],a[j])<=2){
                cout<<"Yes\n";
                return;
            }
        }
    }
    cout<<"No\n";

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