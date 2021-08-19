#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Data {
    int x;
    int y;
    int z;
    ll w;
};

int main() {
    ll n, q;
    cin >> n >> q;
    vector<Data> v(q);
    for (int i = 0; i < q; ++i) {
        cin >> v[i].x >> v[i].y >> v[i].z >> v[i].w;
        v[i].x--; v[i].y--; v[i].z--;
    }
    ll result = 1;
    for (int i = 0; i < 60; ++i) {
        ll temp = 0;
        for (int j = 0; j < (1 << n); ++j) {
            vector<bool> t(n);
            for (int k = 0; k < n; ++k) {
                if (j & (1 << k)) t[k] = true;
            }
            bool ok = true;
            for (int k = 0; k < q; ++k) {
                bool bit = v[k].w & (1ll << i);
                ok &= (t[v[k].x] | t[v[k].y] | t[v[k].z]) == bit;
            }
            if (ok) temp++;
        }
        result *= temp;
        result %= mod;
    }
    cout << result << endl;
}