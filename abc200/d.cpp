#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<vector<ll>>> v(n, vector<vector<ll>>(200));
    v[0][a[0] % 200].push_back(1);
    for (int i = 1; i < n; ++i) {
        v[i][a[i] % 200].push_back(i + 1);
        for (int j = 0; j < 200; ++j) {
            if (v[i-1][j].empty()) continue;
            v[i][(a[i] + j) % 200] = v[i-1][j];
            v[i][(a[i] + j) % 200].push_back(i + 1);
        }
        for (int j = 0; j < 200; ++j) {
            if (v[i-1][j].empty()) continue;
            if (!v[i][j].empty()) {
                cout << "Yes" << endl;
                cout << v[i-1][j].size() << ' ';
                cout << v[i-1][j][0];
                for (int k = 1; k < v[i-1][j].size(); ++k) {
                    cout << ' ' << v[i-1][j][k];
                }
                cout << endl;
                cout << v[i][j].size() << ' ';
                cout << v[i][j][0];
                for (int k = 1; k < v[i][j].size(); ++k) {
                    cout << ' ' << v[i][j][k];
                }
                cout << endl;
                return 0;
            }
            v[i][j] = v[i-1][j];
            v[i-1][j].clear();
        }
    }
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (!v[j][i].empty() && !v[k][i].empty()) {
                    cout << "Yes" << endl;
                    cout << v[j][i].size() << ' ';
                    cout << v[j][i][0];
                    for (int l = 1; l < v[j][i].size(); ++l) {
                        cout << ' ' << v[j][i][l];
                    }
                    cout << endl;
                    cout << v[k][i].size() << ' ';
                    cout << v[k][i][0];
                    for (int l = 1; l < v[k][i].size(); ++l) {
                        cout << ' ' << v[k][i][l];
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}