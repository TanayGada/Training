//if total sum from 1 to n is divisible by 2, then it can be divided into 2 sets
//make first set such starting from n such that sum = (totalSum)/2
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{ 
    int n;
    cin>>n;
    set<int> eleInArr1;
    int totSum = (n*(n+1))/2;
    if(totSum&1){
        cout<<"NO\n";
        return;
    }
    else{
        int reqSum = 0;
        for(int i=n;i>=1;i--){
            reqSum+=i;
            if(reqSum>(totSum/2)){
                reqSum -=i;
            }
            else{
                eleInArr1.insert(i);
            }
            if(reqSum==(totSum/2)){
                break;
            }
        }
    }
    int size1 = eleInArr1.size();
    int size2 = n- size1;
    cout<<"YES\n";
    cout<<size2<<endl;
    for(int i=1;i<=n;i++){
        if(eleInArr1.find(i)==eleInArr1.end())  cout<<i<<" ";
    }
    cout<<endl;
    cout<<size1<<endl;
    for(int i : eleInArr1)  cout<<i<<" ";
    cout<<endl;
        
    
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    
    
    while(t--){
        solve();
    }

    return 0;
}
