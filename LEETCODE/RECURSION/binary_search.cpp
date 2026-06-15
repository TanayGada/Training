#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;


bool is_present(int number_to_find, vector<int>& array, int low, int high){
    if(low>high)   return false;
    int mid = low + (high-low)/2;
    int element_at_mid = array[mid];
    if(element_at_mid==number_to_find)  return true;
    if(element_at_mid>number_to_find)   return is_present(number_to_find, array, low, mid-1);
    else return is_present(number_to_find, array, mid + 1, high);
}

void solve()
{
    // Add your code here
    vector<int> array = {1,2,3,4,5,6,7};
    int length = array.size();
    int number_to_find = 1;
    int low = 0, high = length-1;
    if(is_present(number_to_find, array, low, high)){
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