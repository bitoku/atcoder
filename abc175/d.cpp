#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve on my own

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<int> cycle;
    ll result = LONG_LONG_MIN;
    for (int i = 0; i < n; ++i) {
        vector<ll> v;
        ll score = 0;
        int u = i;
        do {
            u = p[u];
            score += c[u];
            v.push_back(score);
        } while (u != i);
        ll sz = v.size();
        for (ll j = 0; j < min(k, sz); ++j) {
            result = max(result, v[j] + (k - j - 1) / sz * max(0ll, score));
        }
    }
    cout << result << endl;
}
