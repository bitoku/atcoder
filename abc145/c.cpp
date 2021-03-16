#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll fact(ll n) {
    if (n == 0) return 1;
    return n * fact(n-1);
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos[i].first >> pos[i].second;
    }
    ld result = 0;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result += sqrt((pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (pos[i].second - pos[j].second) * (pos[i].second - pos[j].second));
        }
    }
    cout << setprecision(15) << result / n << endl;
}
