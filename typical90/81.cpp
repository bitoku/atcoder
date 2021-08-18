#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> v(5001, vector<ll>(5001));
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[a][b]++;
    }
    for (int i = 0; i <= 5000; ++i) {
        for (int j = 0; j < 5000; ++j) {
            v[i][j+1] += v[i][j];
        }
    }
    for (int j = 0; j <= 5000; ++j) {
        for (int i = 0; i < 5000; ++i) {
            v[i+1][j] += v[i][j];
        }
    }
    ll result = 0;
    k++;
    for (int i = 0; i <= 5000 - k; ++i) {
        for (int j = 0; j <= 5000 - k; ++j) {
            result = max(result, v[i+k][j+k] - v[i+k][j] - v[i][j+k] + v[i][j]);
        }
    }
    cout << result << endl;
}