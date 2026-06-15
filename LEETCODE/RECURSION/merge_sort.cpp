#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;


void merge(vector<int>& array, int low, int high){
    int mid = low + (high-low)/2;
    vector<int> new_array;
    int left = low, right = mid+1;
    while(left<=mid && right<=high){
        if(array[left]<=array[right]){
            new_array.push_back(array[left]);
            left++;
        }
        else{
            new_array.push_back(array[right]);
            right++;
        }
    }

    while(left<=mid){
        new_array.push_back(array[left]);
        left++;   
    }
    
    while(right<=high){
        new_array.push_back(array[right]);
        right++;   
    }

    for(int i=low; i<=high; i++)    array[i] = new_array[i-low];
}

void merge_sort(vector<int>& array, int low, int high){
    if(low>=high)    return;
    int mid = low + (high-low)/2;

    merge_sort(array, low, mid);
    merge_sort(array, mid+1, high);

    merge(array, low, high);

}


void solve()
{
    // Add your code here
    vector<int> array = {4,1,5,8,1,3,2};

    merge_sort(array, 0, array.size()-1);
    for(int i=0;i<array.size();i++) cout<<array[i]<<" ";
    cout<<endl;
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