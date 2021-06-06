#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> t(n);
    set<ll> tt;
    ll sum = 0;
    tt.insert(0);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        sum += t[i];
        set<ll> newtt;
        for (auto x: tt) {
            newtt.insert(x);
            newtt.insert(x + t[i]);
        }
        tt = newtt;
    }
    ll result = LONG_LONG_MAX;
    for (auto x: tt) {
        result = min(result, max(sum - x, x));
    }
    cout << result << endl;
}