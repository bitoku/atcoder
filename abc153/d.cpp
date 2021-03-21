#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

unordered_map<ll, ll> m;

ll solve(ll h) {
    if (m.find(h) != m.end()) return m[h];
    m[h] = 2 * solve(h / 2) + 1;
    return m[h];
}

int main() {
    ll h;
    cin >> h;
    m[1] = 1;
    cout << solve(h) << endl;

}
