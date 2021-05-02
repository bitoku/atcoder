#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x);
    for (int i = 0; i < x; ++i) {
        cin >> a[i];
    }
    vector<ll> b(y);
    for (int i = 0; i < y; ++i) {
        cin >> b[i];
    }
    vector<ll> c(z);
    for (int i = 0; i < z; ++i) {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    priority_queue<tuple<ll, ll, ll, ll>> pq;
    pq.push(make_tuple(a.back() + b.back() + c.back(), x - 1, y - 1, z - 1));
    set<tuple<ll, ll, ll>> s;
    for (int i = 0; i < k; ++i) {
        auto [t, xx, yy, zz] = pq.top(); pq.pop();
        if (s.find(make_tuple(xx, yy, zz)) != s.end()) {
            --i;
            continue;
        }
        s.insert(make_tuple(xx, yy, zz));
        cout << t << endl;
        if (xx > 0) pq.push(make_tuple(a[xx-1]+b[yy]+c[zz], xx-1, yy, zz));
        if (yy > 0) pq.push(make_tuple(a[xx]+b[yy-1]+c[zz], xx, yy-1, zz));
        if (zz > 0) pq.push(make_tuple(a[xx]+b[yy]+c[zz-1], xx, yy, zz-1));
    }
}