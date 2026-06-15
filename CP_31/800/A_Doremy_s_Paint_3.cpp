/*
Access Map and Set elements using iterators
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
    map<int,int> mp;
    set<int> st;
    for(int i=0;i<n;i++){
        int a;  cin>>a;
        mp[a]++;
        st.insert(a);
    }
    if(st.size()==1)    cout<<"Yes\n";
    else if(st.size()==2){
        int n1 = mp[*st.begin()];
        int n2 = mp[*(++st.begin())];
        
        if(max(n2,n1)==((n+1)/2))   cout<<"Yes\n";
        else    cout<<"No\n";

    }
    else    cout<<"No\n";
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