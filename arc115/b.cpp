#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }
    vector<ll> bd(n-1);
    for (int j = 0; j < n-1; ++j) {
        bd[j] = c[0][j+1] - c[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if (c[i][j+1] - c[i][j] != bd[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    vector<ll> ad(n-1);
    for (int i = 0; i < n - 1; ++i) {
        ad[i] = c[i+1][0] - c[i][0];
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            if (c[i+1][j] - c[i][j] != ad[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    vector<ll> a(n);
    ll aoffset = 0;
    for (int i = 1; i < n; ++i) {
        a[i] = ad[i-1] + a[i-1];
        aoffset = max(aoffset, -a[i]);
    }
    for (int i = 0; i < n; ++i) {
        a[i] = a[i] + aoffset;
    }
    vector<ll> b(n);
    b[0] = c[0][0] - a[0];
    if (b[0] < 0) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        b[i] = b[i-1] + bd[i-1];
        if (b[i] < 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << a[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << a[i];
    }
    cout << endl;
    cout << b[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << b[i];
    }
    cout << endl;
}