#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

int get_sum(int number){             //1
    if(number==0)   return 0;
    int digit = number%10;          //1 //0 //1
    return digit + get_sum(number/10);   //1 + 0 + 1 + ...
}

void solve()
{
    // Add your code here
    int number = 10112;
    int sum = get_sum(number);
    cout<<sum<<endl;
    
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