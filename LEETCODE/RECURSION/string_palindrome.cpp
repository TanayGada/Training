#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

bool check_palindrome(string s, int front, int back){
    if(front>back)  return true;
    if(s[front]!=s[back])   return false;
    return check_palindrome(s, ++front, --back);
}


void solve()
{
    // Add your code here
    string input = "nayahn";
    cout<<check_palindrome(input, 0, input.size()-1)<<endl;
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