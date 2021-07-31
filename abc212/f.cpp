#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Path {
    ll s;
    ll t;
    int
};

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, map<int, pair<int, ll>>> src;
    map<ll, map<int, pair<int, ll>>> dst;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll s, t;
        cin >> a >> b >> s >> t;
        a--; b--;
        src[s][a] = make_pair(b, t);
        dst[t][b] = make_pair(a, s);
    }


}