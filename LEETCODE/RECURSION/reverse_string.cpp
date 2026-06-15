// #include "bits/stdc++.h"
// using namespace std;
// #define int long long int
// #define double long double
// #define endl '\n'
// const int MOD = 1000000007;

// void reverse_string(int i, int j, string& s){
//     if(i>j) return;
//     swap(s[i], s[j]);
//     reverse_string(++i, --j, s);
// }

// void solve()
// {
//     // Add your code here
//     string input = "tanay";
//     string output = input;
//     int length = input.size();
//     reverse_string(0, length-1, output);
//     cout<<output<<endl;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int t = 1;
    

//     while (t--) {
//         solve();
//     }

//     return 0;
// }





// #include "bits/stdc++.h"
// using namespace std;

// #define double long double
// #define endl '\n'
// const int MOD = 1000000007;

// string a = "tanay";
// int idx = 0;

// void reverse_string(){
//     int length = a.size();
//     if(idx>=(length/2))    return;
//     swap(a[idx], a[length-idx-1]);
//     idx++;
//     reverse_string();
// }

// void solve()
// {
//     // Add your code here
//     reverse_string();
//     cout<<a<<endl;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);

//     int t = 1;

//     while (t--) {
//         solve();
//     }

//     return 0;
// }


#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

string reverse(string s){
    if (s.size() <= 1) return s;
    return s.back() + reverse(s.substr(1, s.size() - 2)) + s.front();
}


void solve()
{
    // Add your code here
    string a = "tanay";
    cout<<reverse(a)<<endl;
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