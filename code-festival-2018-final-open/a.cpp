#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<map<ll, ll>> v(n);
    for (int i = 0; i < m; ++i) {
        ll a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        v[a][l]++;
        v[b][l]++;
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        for (const auto [l, x]: v[i]) {
            if (l == 1270) {
                result += (x * (x - 1));
            } else {
                result += (x * v[i][2540 - l]);
            }
        }
    }
    cout << result / 2 << endl;
}
