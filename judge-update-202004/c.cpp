#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    vector<ll> x( a1 + a2 + a3);
    iota(x.begin(), x.end(), 1);
    ll result = 0;
    do {
        bool ok = true;
        vector<vector<ll>> k(3);
        for (int i = 0; i < a1; ++i) k[0].push_back(x[i]);
        for (int i = 0; i < a2; ++i) k[1].push_back(x[a1+i]);
        for (int i = 0; i < a3; ++i) k[2].push_back(x[a1+a2+i]);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j + 1 < k[i].size(); ++j) {
                if (k[i][j] > k[i][j+1]) ok = false;
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < min(k[i].size(), k[i+1].size()); ++j) {
                if (k[i][j] > k[i+1][j]) ok = false;
            }
        }
        if (ok) result++;
    } while (next_permutation(x.begin(), x.end()));
    cout << result << endl;
}
