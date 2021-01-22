//
// Created by 徳備彩人 on 2020/02/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int fact(ll a, ll b){
    ll result = 1;
    for(int i=0;i<b;++i){
        result *= a;
        a--;
        result %= MOD;
    }
    return result;
}

int mpow(ll x, ll n){
    ll result = 1;
    while( n != 0 ) {
        if (n & 1) result = result*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return result % MOD;
}

int combination(ll a, ll b) {
    ll result = fact(a, b) % MOD;
    result *= mpow(fact(b, b), MOD-2) % MOD;
    return result % MOD;
}

int main(){
    long long n, a, b;
    cin >> n >> a >> b;
    ll s = mpow(2, n) - 1;
    s = (s - combination(n, a) - combination(n, b)) % MOD;
    cout << (s + MOD) % MOD << endl;
}



