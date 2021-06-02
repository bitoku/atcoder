#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> classroom(n + 2);
    vector<pair<ll, ll>> ms(m);
    for (int i = 0; i < m; ++i) {
        ll s, t;
        cin >> s >> t;
        ms[i] = make_pair(s, t);
        classroom[s]++;
        classroom[t+1]--;
    }
    for (int i = 1; i < n+2; ++i) {
        classroom[i] += classroom[i-1];
    }
    for (int i = 0; i < n+2; ++i) {
        if (classroom[i] != 1) classroom[i] = 0;
    }
    for (int i = 1; i < n+2; ++i) {
        classroom[i] += classroom[i-1];
    }
    vector<int> result;
    for (int i = 0; i < m; ++i) {
        auto [s, t] = ms[i];
        if (classroom[t] - classroom[s - 1] == 0) {
            result.push_back(i+1);
        }
    }
    cout << result.size() << endl;
    for (auto x: result) {
        cout << x << endl;
    }
}