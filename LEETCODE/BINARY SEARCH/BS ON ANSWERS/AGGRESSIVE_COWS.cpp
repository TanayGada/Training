/*
link: https://www.spoj.com/problems/AGGRCOW/

Aggressive cows
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
*/

#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

bool isPossible(int dist, vector<int>& arr, int n, int c){
    bool fg = true;
    
    int next = arr[0] + dist;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(arr[i]>=next){
            cnt++;
            next = arr[i] + dist;
        }
    }
    if(cnt>=c)  return true;
    return false;
}

void solve()
{ 
    int n,c;
    cin>>n>>c;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)    cin>>arr[i];
    sort(arr.begin(), arr.end());
    int low = 1,  high = arr[n-1];
    int ans = 1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(mid, arr, n, c)){
            low = mid+1;
            ans = max(ans, mid);
        }
        else{
            high = mid-1;
        }
    }
    cout<<ans<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    cin>>t;
    
    while(t--){
        solve();
    }

    return 0;
}
