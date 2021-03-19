#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    n %= k;
    set<ll> s;
    ll minx = n;
    while (s.find(n) == s.end()) {
        minx = min(minx, n);
        s.insert(n);
        n = abs(n - k);
    }
    cout << minx << endl;
}
