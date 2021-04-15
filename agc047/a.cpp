#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<pair<int, int>, ll> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        auto k = s.find('.');
        if (k == string::npos) {
            a[i] = stoll(s) * 1000000000;
        } else {
            int t = 10 - s.size() + k;
            s.erase(k, 1);
            a[i] = stoll(s);
            for (int j = 0; j < t; ++j) {
                a[i] *= 10;
            }
        }
        int two = 0;
        int five = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            two++;
        }
        while (a[i] % 5 == 0) {
            a[i] /= 5;
            five++;
        }
        m[make_pair(two, five)]++;
    }
    ll result = 0;
    for (const auto [p1, x] : m) {
        for (const auto [p2, y] : m) {
            if (p1.first + p2.first < 18 || p1.second + p2.second < 18) continue;
            if (p1 == p2) result += x * (y - 1);
            else result += x * y;
        }
    }
    cout << result / 2 << endl;
}
