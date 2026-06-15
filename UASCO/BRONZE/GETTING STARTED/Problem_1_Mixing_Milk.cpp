/*
Visualize the problem
*/

#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

void solve()
{ 
    freopen("mixmilk.in", "r", stdin);
    vector<int> containerCapacity(4,0);
    vector<int> milk(4,0);
    for(int i=0;i<3;i++){
        cin>>containerCapacity[i+1];
        cin>> milk[i+1];
    }
    for(int i=1;i<=33;i++){
        int bCap = containerCapacity[2] - milk[2];
        if(bCap>milk[1]){
            milk[2]+=milk[1];
            milk[1]=0;
        }
        else{
            milk[1] -= bCap;
            milk[2] = containerCapacity[2];
        }
        int cCap = containerCapacity[3] - milk[3];
        if(cCap>milk[2]){
            milk[3]+=milk[2];
            milk[2]=0;
        }
        else{
            milk[2] -= cCap;
            milk[3] = containerCapacity[3];
        }
        int aCap = containerCapacity[1] - milk[1];
        if(aCap>milk[3]){
            milk[1]+=milk[3];
            milk[3]=0;
        }
        else{
            milk[3] -= aCap;
            milk[1] = containerCapacity[1];
        }
        
    }
    int bCap = containerCapacity[2] - milk[2];
    if(bCap>milk[1]){
        milk[2]+=milk[1];
        milk[1]=0;
    }
    else{
        milk[1] -= bCap;
        milk[2] = containerCapacity[2];
    }
    freopen("mixmilk.out", "w", stdout);
    for(int i=0;i<3;i++){
        cout<<milk[i+1]<<endl;
    }   
    
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
