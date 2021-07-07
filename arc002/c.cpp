#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string key = "ABXY";
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll result = LONG_LONG_MAX;
    for (auto w: key) {
        for (auto x: key) {
            for (auto y: key) {
                for (auto z: key) {
                    string l = {w, x};
                    string r = {y, z};
                    if (l == r) continue;
                    ll temp = 0;
                    for (int i = 0; i < n; ++i) {
                        if (i < n - 1 && (s.substr(i, 2) == l || s.substr(i, 2) == r)) i++;
                        temp++;
                    }
                    result = min(result, temp);
                }
            }
        }
    }
    cout << result << endl;
}