#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template <class T>
bool sameline(pair<T, T> a, pair<T, T> b, pair<T, T> c) {
    auto [ax, ay] = a;
    auto [bx, by] = b;
    auto [cx, cy] = c;
    return (bx - ax) * (cy - ay) == (by - ay) * (cx - ax);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }
    ll result = 0;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    vector<ll> m(n+1);
    vector<vector<bool>> done(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (done[i][j]) continue;
            vector<int> x = {i, j};
            ll cnt = 2;
            for (int l = j + 1; l < n; ++l) {
                if (done[i][l] || done[j][l]) continue;
                if (sameline(v[i], v[j], v[l])) {
                    x.push_back(l);
                    cnt++;
                }
            }
            for (int ii = 0; ii < cnt; ++ii) {
                for (int jj = ii+1; jj < cnt; ++jj) {
                    done[x[ii]][x[jj]] = true;
                }
            }
            if (cnt >= k) result++;
        }
    }
    cout << result << endl;
}