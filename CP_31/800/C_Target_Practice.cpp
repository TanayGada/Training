/*
Try to break into small problem and try various techniques on Sample Test Cases
Try to get inputs into 1st quandrant and then calculated values assigned to them
Alternatively we could have constructed a matrix with score at each cell and then mapped input "X" to get value
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
    int ans = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            char c;  cin>>c;
            if(c=='X'){
                int a = i, b = j;
                if(a>=5){
                    a=9-a;
                }
                if(b>=5){
                    b=9-b;
                }
                if(a==b){
                    ans+=(a+1);
                }
                else {
                    ans+=(min(a,b)+1);
                }
                    
            }
        }
    }
    cout<<ans<<endl;
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