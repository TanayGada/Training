/*
2 cases
case1: 2 consecutive elements in b can be 2 consecutive elements in a 
case2: there can be 1 element in between 2 consecutive elements from b in a
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
    int n=0;    cin>>n;
    vector<int> a;
    int ele;
    cin>>ele;
    a.push_back(ele);
    for(int i=1;i<n;i++){
        cin>>ele;
        if(a.back()>ele){
            a.push_back(1);
            a.push_back(ele);
        }
        else{
            a.push_back(ele);
        }
    }
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++)    cout<<a[i]<<" ";
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