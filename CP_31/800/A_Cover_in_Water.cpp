/*
if i have 3 consecutive blanks, i will require 2 type1 operations to fill it completely
else noOfBlanks === noOfType1
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
    vector<char> a(n,0);
    for(int i=0;i<n;i++)    cin>>a[i];
    if(n>=3){
        for(int i=0;i<n-2;i++){
            if(a[i]=='.' && a[i+1]=='.' && a[i+2]=='.'){
                cout<<"2"<<endl;
                return;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]=='.')   cnt++;
    }
    cout<<cnt<<endl;
    
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