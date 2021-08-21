#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/21

int main() {
    ll n;
    cin >> n;
    vector<int> w(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int wm = *max_element(w.begin(), w.end());
    vector<vector<ll>> grundy(55, vector<ll>(1500));
    for (int i = 0; i <= wm; ++i) {
        for (int j = 0; j < 1500; ++j) {
            vector<int> mex(1500);
            for (int k = 0; k < 1500; ++k) {
                mex[k] = 0;
            }
            if (j >= 2) {
                for (int k = 1; k <= j / 2; ++k) {
                    mex[grundy[i][j - k]] = 1;
                }
            }
            if (i > 0 && j + i < 1500) {
                mex[grundy[i-1][j+i]] = 1;
            }
            for (int k = 0; k < 1500; ++k) {
                if (mex[k] == 0) {
                    grundy[i][j] = k;
                    break;
                }
            }
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result ^= grundy[w[i]][b[i]];
    }
    if (result == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
}