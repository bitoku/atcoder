#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 09/21

int main() {
    ll n;
    cin >> n;
    multiset<ll> a;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.insert(x);
    }
    ll result = 0;
    while (!a.empty()) {
        ll x = *a.rbegin();
        a.erase(a.find(x));
        for (int j = 1; j <= 30; ++j) {
            if ((1ll << j) < x) continue;
            if ((1ll << j) > 2 * x) break;
            auto it = a.find((1ll << j) - x);
            if (it == a.end()) continue;
            a.erase(it);
            result++;
        }
    }
    cout << result << endl;
}