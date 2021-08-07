#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll g = gcd(gcd(a, b), c);
    cout << (a + b + c) / g - 3 << endl;
}