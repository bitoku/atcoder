#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll a, b;
    cin >> a >> b;
    vector<vector<bool>> coprime(b - a + 1, vector<bool>(b - a + 1));
    for (ll i = a; i <= b; ++i) {
        for (ll j = a; j <= b; ++j) {
            if (gcd(i, j) == 1) coprime[i-a][j-a] = true;
        }
    }
    ll result = 0;
    if (a % 2 == 1) {
        ll odd = (b - a) / 2 + 1;
        for (int i = 1; i < (1 << odd); ++i) {
            vector<int> n;
            for (int j = 0; j < odd; ++j) {
                if (i & (1 << j)) {
                    n.push_back(2 * j);
                }
            }
            bool ok = true;
            for (auto x: n) {
                for (auto y: n) {
                    if (x == y) continue;
                    if (!coprime[x][y]) ok = false;
                }
            }
            if (!ok) continue;
            result++;
            for (ll j = 1; j <= b - a; j += 2) {
                ok = true;
                for (auto y: n) {
                    if (!coprime[j][y]) ok = false;
                }
                if (!ok) continue;
                result++;
            }
        }
        for (ll i = 1; i <= b - a; i += 2) {
            result++;
        }
        cout << result + 1 << endl;
        return 0;
    } else {
        ll odd = (b - a + 1) / 2;
        for (int i = 1; i < (1 << odd); ++i) {
            vector<int> n;
            for (int j = 0; j < odd; ++j) {
                if (i & (1 << j)) {
                    n.push_back(2 * j + 1);
                }
            }
            bool ok = true;
            for (auto x: n) {
                for (auto y: n) {
                    if (x == y) continue;
                    if (!coprime[x][y]) ok = false;
                }
            }
            if (!ok) continue;
            result++;
            for (ll j = 0; j <= b - a; j += 2) {
                ok = true;
                for (auto y: n) {
                    if (!coprime[j][y]) ok = false;
                }
                if (!ok) continue;
                result++;
            }
        }
        for (ll i = 0; i <= b - a; i += 2) {
            result++;
        }
        cout << result + 1 << endl;
        return 0;
    }
}