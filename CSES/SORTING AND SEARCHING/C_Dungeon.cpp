#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

// int N = 1e6;
// vector<bool> isPrime(N+1, true);
// vector<int> spf(N+1, 1e9);
// vector<int> fact(N+1, 0);
// vector<int> invFact(N+1, 0);


// // time complexity -> log2(b)
// int binExpo(int a, int b, int MOD){
//     int res = 1;
//     while(b>0){
//         if(b&1)    res = (1LL * res * a)%MOD;
//         a = (1LL*a*a)%MOD;
//         b>>=1;
//     }
//     return res;
// }

// // time complexity -> log2(b)
// int inv(int n){
//     return binExpo(n, MOD-2, MOD);
// }


// // prime factors in form -> (p1, t1), (p2, t2), .. for q queries using spf
// // time complexity -> O(spf) + qlogn = sqrt(n) * log(logn) + qlogn
// vector<pair<int,int>> primeFactorization(int n){
//     vector<pair<int,int>> primeFactors;
//     while(n>1){
//         int prime = spf[n];
//         int cnt = 0;
//         while(n%prime==0){
//             cnt++;
//             n/=prime;
//         }
//         primeFactors.push_back({prime, cnt});
//     }
//     return primeFactors;
// }

// // marks prime numbers as true in isPrime
// // stores smallest prime factor for each number in spf 
// // time complexity -> sqrt(n) * log(logn)
// void sieve(){
//     isPrime[0] = isPrime[1] = false;
//     for(int i=2; i<=N; i++){
//         if(isPrime[i]){
//             spf[i] = i;
//             for(int j=i*i; j<=N; j+=i){
//                 isPrime[j] = false;
//                 spf[j] = min(spf[j], i);
//             }
//         }
//     }
// }

// // needs primeFactors for a number -> tc = sqrt(n) * log(logn) + logn
// int numberOfDivisors(int n, vector<pair<int,int>> primeFactors){
//     int res = 1;
//     for(auto i : primeFactors){
//         res = (1LL*res*(i.second+1))%MOD;
//     }
//     return res;
// }

// // needs primeFactors for a number -> tc = sqrt(n) * log(logn) + logn
// // time complexity -> log2(b) * log2(n)
// int sumOfDivisors(int n, vector<pair<int,int>> primeFactors){
//     int res = 1;
//     for(auto i : primeFactors){
//         int p = i.first;
//         int e = i.second;
//         int num = binExpo(p, e+1, MOD) - 1;
//         int den = p-1;
//         res= (1LL*res*(num*inv(den)))%MOD;
//     }
//     return res;
// }


// // calculates gcd of a number -> log2(min(a,b))
// int gcd(int a, int b){
//     while(a){
//         a = a%b;
//         swap(a,b);
//     }
//     return b;
// }

// // calculates gcd of a number -> log2(min(a,b))
// int lcm(int a, int b){
//     int prod = 1LL*a*b;
//     int gcd1 = gcd(a,b);
//     return prod*inv(gcd1);
// }

// // O(n)
// void factorial(){
//     fact[0] = 1;
//     for(int i=1;i<=N; i++){
//         fact[i] = (1LL*fact[i-1]*i)%MOD;
//     }
// }
// // O(log2(MOD) + n) 
// void inverseFactorial(){
//     invFact[N] = inv(fact[N]);
//     for(int i=N-1; i>=0; i--){
//         invFact[i] = (1LL*invFact[i+1]*(i+1))%MOD;
//     }
// }

// // O(1) for 1 query -> useful when there are q queries -> O(q)
// int nCr(int n, int r){
//     r = min(r, n-r);
//     if(r < 0 || r > n)  return 0;
//     int val = (1LL * fact[n] * invFact[n-r])% MOD;
//     val = (val * invFact[r])%MOD;
//     return val;
// }


void solve()
{
    // Add your code here
    int n, m;   cin>>n>>m;
    multiset<int> a;
    for(int i=0; i<n; i++){
        int aa=0;   cin>>aa;
        a.insert(aa);
    }
    vector<int> b(m,0), c(m,0);
    for(int i=0; i<m; i++)  cin>>b[i];
    for(int i=0; i<m; i++)  cin>>c[i];

    vector<int> bb;
    vector<vector<int>> cb;
    for(int i=0; i<m; i++){
        if(c[i])  cb.push_back({b[i], c[i]});
        else bb.push_back(b[i]);
    }
    sort(cb.begin(), cb.end());
    sort(bb.begin(), bb.end());
    int cnt = 0;
    for(auto &it : cb){
        int health = it[0];
        int power = it[1];
        auto lb = a.lower_bound(health);
        if(lb != a.end()){
            cnt++;
            int swordPower = *lb;
            if(swordPower<power){
                a.erase(lb);
                a.insert(power);
            }
        }
    }
    for(int i : bb){
        auto lb = a.lower_bound(i);
        if(lb != a.end()){
            cnt++;
            a.erase(lb);
        }
    }
    cout<<cnt<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;
    cin>>t;

    while (t--) {
        solve();
    }

    return 0;
}




#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1e9+7;

void solve()
{
    // Add your code here

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;
    cin>>t;

    while (t--) {
        solve();
    }

    return 0;
}