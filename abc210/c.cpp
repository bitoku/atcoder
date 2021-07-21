#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    map<ll, ll> m;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        m[c[i]]++;
    }
    ll result = m.size();
    for (int i = k; i < n; ++i) {
        m[c[i-k]]--;
        if (m[c[i-k]] == 0) m.erase(c[i-k]);
        m[c[i]]++;
        result = max(result, (ll)m.size());
    }
    cout << result << endl;
}