#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define double long double
#define endl '\n'
const int MOD = 1000000007;

int N = 1e6;
vector<bool> isPrime(N+1, true);
vector<int> spf(N+1, 1e9);

// // time complexity -> log2(b)
// int binaryExponentiation(int a, int b, int MOD){
//     int res = 1;
//     while(b>0){
//         if(b&1)    res = (res * a)%MOD;
//         a = (a*a)%MOD;
//         b>>=1;
//     }
//     return res;
// }

// // time complexity -> log2(b)
// int multiplicativeInverse(int n){
//     return binaryExponentiation(n, MOD-2, MOD);
// }


// prime factors in form -> (p1, t1), (p2, t2), .. for q queries using spf
// time complexity -> O(spf) + qlogn = sqrt(n) * log(logn) + qlogn
vector<pair<int,int>> primeFactorization(int n){
    vector<pair<int,int>> primeFactors;
    while(n>1){
        int prime = spf[n];
        int cnt = 0;
        while(n%prime==0){
            cnt++;
            n/=prime;
        }
        primeFactors.push_back({prime, cnt});
    }
    return primeFactors;
}

// marks prime numbers as true in isPrime
// stores smallest prime factor for each number in spf 
// time complexity -> sqrt(n) * log(logn)
void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=N; i++){
        if(isPrime[i]){
            spf[i] = i;
            for(int j=i*i; j<=N; j+=i){
                isPrime[j] = false;
                spf[j] = min(spf[j], i);
            }
        }
    }
}

// needs primeFactors for a number -> tc = sqrt(n) * log(logn) + logn
int numberOfDivisors(int n, vector<pair<int,int>> primeFactors){
    int res = 1;
    for(auto i : primeFactors){
        res = (res*(i.second+1))%MOD;
    }
    return res;
}

// // needs primeFactors for a number -> tc = sqrt(n) * log(logn) + logn
// // time complexity -> log2(b) * log2(n)
// int sumOfDivisors(int n, vector<pair<int,int>> primeFactors){
//     int res = 1;
//     for(auto i : primeFactors){
//         int p = i.first;
//         int e = i.second;
//         int num = binaryExponentiation(p, e+1, MOD) - 1;
//         int den = p-1;
//         res= (res*(num*multiplicativeInverse(den)))%MOD;
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
//     int prod = a*b;
//     int gcd1 = gcd(a,b);
//     return prod*multiplicativeInverse(gcd1);
// }


void solve()
{
    // Add your code here
    int n;  cin>>n;
    vector<pair<int,int>> primeFactors = primeFactorization(n);
    cout<<numberOfDivisors(n, primeFactors)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}