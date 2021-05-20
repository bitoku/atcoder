#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<ll> mx(n - k + 1, -1);
    vector<ll> mn(n - k + 1, LONG_LONG_MAX);
    set<ll> s;
    for (int i = 0; i < k; ++i) {
        mx[0] = max(mx[0], p[i]);
        mn[0] = min(mn[0], p[i]);
        s.insert(p[i]);
    }
    for (int i = k; i < n; ++i) {
        s.erase(p[i-k]);
        s.insert(p[i]);
        mx[i-k+1] = *s.rbegin();
        mn[i-k+1] = *s.begin();
    }
    vector<int> ascend(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        ascend[i] = p[i] < p[i+1] ? 1 : 0;
    }
    int x = 0;
    vector<int> sorted(n - k + 1);
    for (int i = 0; i < k - 1; ++i) {
        x += ascend[i];
    }
    if (x == k - 1) sorted[0] = 1;
    else sorted[0] = 0;
    for (int i = k - 1; i < n - 1; ++i) {
        x -= ascend[i - k + 1];
        x += ascend[i];
        if (x == k - 1) sorted[i - k + 2] = 1;
        else sorted[i - k + 2] = 0;
    }
    ll result = 1;
    bool ss = false;
    if (sorted[0]) {
        ss = true;
    }
    for (int i = 0; i < n-k; ++i) {
        if (p[i] == mn[i] && p[i + k] == mx[i + 1]) continue;
        if (ss && sorted[i+1]) continue;
        if (sorted[i+1]) ss = true;
        result++;
    }
    cout << result << endl;
}