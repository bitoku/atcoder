#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> v(h, vector<ll>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> v[i][j];
        }
    }
    vector<ll> k(h), l(w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            k[i] += v[i][j];
            l[j] += v[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        cout << k[i] + l[0] - v[i][0];
        for (int j = 1; j < w; ++j) {
            cout << ' ' << k[i] + l[j] - v[i][j];
        }
        cout << endl;
    }
}