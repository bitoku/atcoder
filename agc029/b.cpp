#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

struct Edge {
    int from;
    int to;
};

int main() {
    ll n;
    cin >> n;
    multiset<ll> a;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.insert(x);
    }
    auto it = a.rbegin();
    ll cnt = 0;
    for (; it != a.rend(); it = a.rbegin()) {
        ll t = *it;
        ll x = t;
        a.erase(--(it.base()));
        ll k = 0;
        while (t > 0) {
            t >>= 1;
            k++;
        }
        auto pit = a.find((1 << k) - x);
        if (pit != a.end()) {
            a.erase(pit);
            cnt++;
        }
    }
    cout << cnt << endl;
}
