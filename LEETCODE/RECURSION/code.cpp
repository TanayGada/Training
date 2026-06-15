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
    string s;   cin>>s;
    
    int ab = 0, bc = 0;
    int a = 0, c = 0;
    
    for(int i=0; i<n; i++){
        if(s[i] == 'A'){
            a++;
        }
        else if(s[i] == 'B'){
            ab += a;
        }
        else if(s[i] == 'C'){
            a = 0;
        }
    }
    
    for(int i=n-1; i>=0; i--){
        if(s[i] == 'C'){
            c++;
        }
        else if(s[i] == 'B'){
            bc += c;
        }
        else if(s[i] == 'A'){
            c = 0; 
        }
    }
    
    cout<<max(ab, bc)<<endl;
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