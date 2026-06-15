#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;


bool is_present(int number_to_find, vector<int>& array, int index){
    if(index>=array.size()) return false;
    if(array[index]==number_to_find)    return true;
    if(is_present(number_to_find, array, index+1)) return true;
    else return false;
}

void solve()
{
    // Add your code here
    
    vector<int> array = {1, 2, 4, 5, 6, 7, 10};
    int length = array.size();
    int number_to_find = 10;
    if(is_present(number_to_find, array, 0))  {
        cout<<"Number "<<number_to_find<<" present in array\n";
    }
    else{
        cout<<"Number "<<number_to_find<<" not present in array\n";
    }
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