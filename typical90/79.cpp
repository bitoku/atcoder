#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    vector<vector<ll>> b(h, vector<ll>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> b[i][j];
        }
    }
    ll result = 0;
    for (int i = 0; i < h-1; ++i) {
        for (int j = 0; j < w-1; ++j) {
            ll d = b[i][j] - a[i][j];
            a[i][j] += d;
            a[i][j+1] += d;
            a[i+1][j] += d;
            a[i+1][j+1] += d;
            result += abs(d);
        }
    }
    bool ok = true;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ok &= a[i][j] == b[i][j];
        }
    }
    if (ok) {
        cout << "Yes" << endl;
        cout << result << endl;
    }
    else cout << "No" << endl;
}