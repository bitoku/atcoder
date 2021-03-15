#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve on my own

int main() {
    int n;
    cin >> n;
    vector<ll> T(n);
    vector<ll> V(n);
    vector<ll> t(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
        T[i] *= 2;
    }
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
        V[i] *= 2;
    }
    for (int i = 0; i < n; ++i) {
        t[i+1] = t[i] + T[i];
    }
    ll g = t[n];
    vector<ll> v(g + 1, 100000);
    for (ll j = 0; j <= g; ++j) {
        v[j] = min(j, g - j);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= t[i]; ++j) {
            v[j] = min(v[j], V[i] + t[i] - j);
        }
        for (int j = t[i]; j <= t[i + 1]; ++j) {
            v[j] = min(v[j], V[i]);
        }
        for (int j = t[i + 1]; j <= g; ++j) {
            v[j] = min(v[j], V[i] + j - t[i + 1]);
        }
    }
    ll result = 0;
    for (int i = 0; i <= g; ++i) {
        result += v[i];
    }
    cout << setprecision(15) << result / 4.0 << endl;
}
