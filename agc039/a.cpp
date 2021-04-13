#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    ll k;
    cin >> s;
    cin >> k;
    vector<ll> v;
    v.push_back(1);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
            v[v.size() - 1]++;
        } else {
            v.push_back(1);
        }
    }
    if (s.front() != s.back()) {
        ll result = 0;
        for (auto x : v) {
            result += x / 2 * k;
        }
        cout << result << endl;
    } else {
        ll result = 0;
        if (v.size() == 1) {
            cout << s.size() * k / 2 << endl;
            return 0;
        }
        for (int i = 1; i < v.size() - 1; ++i) {
            result += v[i] / 2 * k;
        }
        result += (v.front() + v.back()) / 2 * (k - 1);
        result += v.front() / 2 + v.back() / 2;
        cout << result << endl;
    }
}
