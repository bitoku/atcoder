#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    a = (a + 1) * a / 2 % mod;
    b = (b + 1) * b / 2 % mod;
    c = (c + 1) * c / 2 % mod;
    cout << (a * b % mod) * c % mod << endl;
}
