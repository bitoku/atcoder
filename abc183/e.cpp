#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    vector<vector<ll>> cnt(h, vector<ll>(w, 0));
    vector<vector<ll>> sum_row(h, vector<ll>(w, 0));
    vector<vector<ll>> sum_col(h, vector<ll>(w, 0));
    vector<vector<ll>> sum_diag(h, vector<ll>(w, 0));
    cnt[0][0] = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') continue;
            if (j > 0) cnt[i][j] += sum_row[i][j-1];
            if (i > 0) cnt[i][j] += sum_col[i-1][j];
            if (i > 0 && j > 0) cnt[i][j] += sum_diag[i-1][j-1];
            cnt[i][j] %= mod;

            sum_row[i][j] = cnt[i][j];
            sum_col[i][j] = cnt[i][j];
            sum_diag[i][j] = cnt[i][j];
            if (j > 0) sum_row[i][j] += sum_row[i][j-1];
            if (i > 0) sum_col[i][j] += sum_col[i-1][j];
            if (i > 0 && j > 0) sum_diag[i][j] += sum_diag[i-1][j-1];
            sum_row[i][j] %= mod;
            sum_col[i][j] %= mod;
            sum_diag[i][j] %= mod;
        }
    }
    cout << cnt[h-1][w-1] << endl;
}
