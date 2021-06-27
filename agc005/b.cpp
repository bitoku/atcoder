#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<pair<ll, ll>> idx;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idx.insert(make_pair(a[i], i));
    }
    set<ll> b;
    b.insert(-1);
    b.insert(n);
    ll result = 0;
    for (auto [x, k]: idx) {
        auto right = b.upper_bound(k);
        auto left = b.upper_bound(k); left--;
        result += x * (k - *left) * (*right - k);
        b.insert(k);
    }
    cout << result << endl;
}