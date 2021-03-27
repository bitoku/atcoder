#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll h, w;
    ll n;
    cin >> h >> w >> n;
    set<pair<ll, ll>> vs;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        vs.insert(make_pair(a, b));
    }
    set<pair<ll, ll>> s;
    ll result[10] = {};
    for (const auto [a, b]: vs) {
        for (ll na = a-1; na <= a+1; ++na) {
            for (ll nb = b-1; nb <= b+1; ++nb) {
                if (s.find(make_pair(na, nb)) != s.end()) continue;
                s.insert(make_pair(na, nb));
                bool inside = true;
                int cnt = 0;
                for (int j = -1; j <= 1; ++j) {
                    for (int k = -1; k <= 1; ++k) {
                        if (na + j <= 0 || na + j > h || nb + k <= 0 || nb + k > w) {
                            inside = false;
                            break;
                        }
                        if (vs.find(make_pair(na+j, nb+k)) != vs.end()) cnt++;
                    }
                }
                if (!inside) continue;
                result[cnt]++;
            }
        }
    }
    ll blank = (h - 2) * (w - 2);
    for (int i = 1; i < 10; ++i) {
        blank -= result[i];
    }
    result[0] = blank;
    for (int i = 0; i < 10; ++i) {
        cout << result[i] << endl;
    }
}
