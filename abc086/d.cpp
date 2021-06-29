#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 06/29

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> b(k+1, vector<ll>(k+1));
    vector<vector<ll>> w(k+1, vector<ll>(k+1));
    for (int i = 0; i < n; ++i) {
        ll x, y, c;
        char bw;
        cin >> x >> y >> bw;
        if (bw == 'B') c = 0;
        else c = 1;
        if (x / k % 2 == 1) c = 1 - c;
        x %= k;
        if (y / k % 2 == 1) c = 1 - c;
        y %= k;
        x++;
        y++;
        if (c == 0) b[x][y]++;
        else w[x][y]++;
    }
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j < k; ++j) {
            b[i][j+1] += b[i][j];
            w[i][j+1] += w[i][j];
        }
    }
    for (int j = 0; j <= k; ++j) {
        for (int i = 0; i < k; ++i) {
            b[i+1][j] += b[i][j];
            w[i+1][j] += w[i][j];
        }
    }
    ll result = 0;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            ll temp = b[i][k] + b[k][j] - 2 * b[i][j];
            temp += w[k][k] - w[i][k] - w[k][j] + 2 * w[i][j];
            result = max(result, temp);
            temp = w[i][k] + w[k][j] - 2 * w[i][j];
            temp += b[k][k] - b[i][k] - b[k][j] + 2 * b[i][j];
            result = max(result, temp);
        }
    }
    cout << result << endl;
}