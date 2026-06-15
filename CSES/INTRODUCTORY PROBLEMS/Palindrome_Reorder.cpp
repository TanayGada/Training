// element with odd freq is placed at middle
// then placed from start and end simultaneously
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{
    // Add your code here
    string s;   cin>>s;
    int n = s.size();
    map<char,int> mp1;
    vector<char> ans(n);
    for(int i=0;i<n;i++){
        mp1[s[i]]++;
    }                       
    // A -> 6
    // B -> 1
    // C -> 2
    int cnt = 0;
    for(auto i : mp1){
        if(i.second&1)  cnt++;
    }
    if(cnt>1){
        cout<<"NO SOLUTION\n";
        return;
    }
    else{
        
        int j = 0;
        for(auto i : mp1){
            if(i.second&1){
                ans[n/2] = i.first;
                i.second--;
            }
            for(; j<=n/2 && i.second>0; j++){
                
                ans[j] = i.first;
                ans[n-j-1] = i.first;
                i.second-=2;
            }
        }
    }
    for(char i : ans)   cout<<i;
    cout<<endl;
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



