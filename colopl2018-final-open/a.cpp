#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a;
    char before = 'X';
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            if (before == 'A') {
                a[a.size() - 1]++;
            } else {
                a.push_back(1);
            }
            before = 'A';
        } else {
            before = 'B';
        }
    }
    if (s.front() == 'B' || s.back() == 'B') {
        ll result = 0;
        for (const auto x: a) {
            result += x * (x + 1) / 2;
        }
        cout << result * n << endl;
    } else {
        ll result = 0;
        if (a.size() == 1) {
            cout << (a[0] * n) * (a[0] * n + 1) / 2 << endl;
            return 0;
        }
        for (int i = 1; i < a.size() - 1; ++i) {
            result += a[i] * (a[i] + 1) / 2;
        }
        result *= n;
        result += (a.front() + a.back()) * (a.front() + a.back() + 1) / 2 * (n - 1);
        result += a.front() * (a.front() + 1) / 2;
        result += a.back() * (a.back() + 1) / 2;
        cout << result << endl;
    }
}
