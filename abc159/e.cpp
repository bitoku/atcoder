#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    vector<vector<ll>> choco(h, vector<ll>(w));
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if (s[j] == '1') choco[i][j] = 1;
        }
    }
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < (1 << (h - 1)); ++i) {
        vector<vector<ll>> c(1, vector<ll>(w));
        for (int j = 0; j < w; ++j) {
            c[0][j] = choco[0][j];
        }
        ll temp = 0;
        for (int j = 0; j < h - 1; ++j) {
            if (i & (1 << j)) {
                c.emplace_back(w);
                temp++;
            }
            for (int l = 0; l < w; ++l) {
                c.back()[l] += choco[j+1][l];
            }
        }
        bool imp = false;
        for (int j = 0; j < c.size(); ++j) {
            if (any_of(c[j].begin(), c[j].end(), [&](ll x) {return x > k;})) {
                imp = true;
                break;
            }
        }
        if (imp) {
            continue;
        }
        vector<ll> t(c.size());
        for (int l = 0; l < w; ++l) {
            for (int j = 0; j < c.size(); ++j) {
                t[j] += c[j][l];
            }
            if (any_of(t.begin(), t.end(), [&](ll x) {return x > k;})) {
                for (int j = 0; j < c.size(); ++j) {
                    t[j] = c[j][l];
                }
                temp++;
            }
        }
        result = min(result, temp);
    }
    cout << result << endl;
}