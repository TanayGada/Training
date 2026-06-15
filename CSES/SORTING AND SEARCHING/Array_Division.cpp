/*
We apply binary search on answer (minimum maxi sum)
range of ans = maxEle to sumOfAllEle
select a possible value val from solution range
check if we can split array into less than equal to k subarrays each having sum less than val
*/
#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;


/*
for val=8,k=3
a = [2,4,7,3,5]
it   sum    noOfSubArrays
0    0      1
1    2      1
2    6      1
3    7      2
4    3      3
5    8      3

*/
int isPossible(int val, int k, vector<int>& a){
    int noOfSubArrays = 1;
    int sum = 0;
    for(int i=0;i<a.size();i++){
        if((sum+a[i])<=val){                          
            sum+=a[i];
        }
        else{
            noOfSubArrays++;
            if(a[i]>val)    return false;
            sum=a[i];
        }
    }
    if(noOfSubArrays<=k)   return true;
    return false;
}

void solve()
{
    // Add your code here
    int n=0,k=0;    cin>>n>>k;
    vector<int> a(n,0); 
    for(int i=0;i<n;i++)    cin>>a[i];
    int mini = *max_element(a.begin(),a.end());  
    int maxi = 0;                                   
    for(int i=0;i<n;i++)    maxi+=a[i];          
    int ans = maxi;                              
    while(mini<=maxi){
        int mid = mini + (maxi-mini)/2;          
        if(isPossible(mid,k,a)){
            maxi = mid-1;
            ans = min(mid,ans);
        }
        else{
            mini = mid+1;
        }
    }
    cout<<ans<<endl;
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