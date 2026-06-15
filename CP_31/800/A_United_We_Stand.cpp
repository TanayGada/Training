/*
c[i] is not divisor of b[j] => any ele of b cannot be divided by any ele of c
so we need c to be largest
also we need alteast one ele in both b and c
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
    for(int i=0;i<n;i++)    cin>>a[i];
    vector<int> b,c;
    int maxEle = *max_element(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]==maxEle){
            c.push_back(a[i]);
        }
        else    b.push_back(a[i]);
    }
    if(b.size()==0)  cout<<-1<<endl;
    else{
        cout<<b.size()<<" "<<c.size()<<endl;
        for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
        cout<<endl;
        for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
        cout<<endl;
        
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