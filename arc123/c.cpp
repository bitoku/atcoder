#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    map<ll, int> row, col;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        row[a] = 1;
        col[b] = 1;
        v[i] = {a, b};
    }
    int i = 1;
    for (auto& [x, y]: row) {
        y = i++;
    }
    i = 1;
    for (auto& [x, y]: col) {
        y = i++;
    }
    for (auto [r, c]: v) {
        cout << row[r] << ' ' << col[c] << endl;
    }
}