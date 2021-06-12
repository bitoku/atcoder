#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

unordered_map<ll, ll> fact_memo;
ll mod_fact(ll x) {
    if (fact_memo.find(x) != fact_memo.end()) return fact_memo[x];
    if (x == 0) return 1;
    fact_memo[x] = x * mod_fact(x - 1) % mod;
    return fact_memo[x];
}

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;
    vector<int> x(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        if (s[i] == 'B') {
            if (cnt % 2 == 0) {
                x[i] = 0;
                cnt++;
            } else {
                x[i] = 1;
                cnt--;
            }
        }
        else {
            if (cnt % 2 == 0) {
                x[i] = 1;
                cnt--;
            } else {
                x[i] = 0;
                cnt++;
            }
        }
    }
    ll result = 1;
    cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        cnt += x[i];
    }
    if (cnt != n) {
        cout << 0 << endl;
        return 0;
    }
    cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (x[i] == 0) cnt++;
        else {
            result *= cnt;
            result %= mod;
            cnt = max(cnt - 1, 0ll);
        }
    }
    for (int i = 0; i < n; ++i) {
        mod_fact(i);
    }
    cout << result * mod_fact(n) % mod << endl;
}