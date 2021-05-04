#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    deque<ll> xs, ys;
    bool xx = true;
    xs.push_back(0);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'F') {
            if (xx) xs[xs.size() - 1]++;
            else ys[ys.size() - 1]++;
        } else {
            if (xx) {
                if (xs.back() == 0) xs.pop_back();
                ys.push_back(0);
            }
            else {
                if (ys.back() == 0) ys.pop_back();
                xs.push_back(0);
            }
            xx = !xx;
        }
    }
    if (s[0] == 'F') {
        x -= xs.front();
        xs.pop_front();
    }
    set<ll> pool;
    pool.insert(0);
    for (int i = 0; i < xs.size(); ++i) {
        set<ll> newpool;
        for (auto k: pool) {
            newpool.insert(k + xs[i]);
            newpool.insert(k - xs[i]);
        }
        pool = newpool;
    }
    if (pool.find(x) == pool.end()) {
        cout << "No" << endl;
        return 0;
    }
    pool.clear();
    pool.insert(0);
    for (int i = 0; i < ys.size(); ++i) {
        set<ll> newpool;
        for (auto k: pool) {
            if (k + ys[i] < -8000 || k + ys[i] > 8000) continue;
            newpool.insert(k + ys[i]);
            newpool.insert(k - ys[i]);
        }
        pool = newpool;
    }
    if (pool.find(y) == pool.end()) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}