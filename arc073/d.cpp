#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, W;
    cin >> n >> W;
    deque<ll> w[4];
    ll v, w0 = 0;
    cin >> w0 >> v;
    w[0].push_back(v);
    for (int i = 1; i < n; ++i) {
        ll ww;
        cin >> ww >> v;
        w[ww - w0].push_back(v);
    }
    sort(w[0].begin(), w[0].end(), greater<>());
    sort(w[1].begin(), w[1].end(), greater<>());
    sort(w[2].begin(), w[2].end(), greater<>());
    sort(w[3].begin(), w[3].end(), greater<>());
    for (auto & wi : w) {
        wi.push_front(0);
        for (int j = 1; j < wi.size(); ++j) {
            wi[j] += wi[j - 1];
        }
    }
    ll result = 0;
    ll w1 = w0 + 1;
    ll w2 = w0 + 2;
    ll w3 = w0 + 3;
    for (int i = 0; i < w[0].size(); ++i) {
        if (w0 * i > W) break;
        for (int j = 0; j < w[1].size(); ++j) {
            if (w0 * i + w1 * j > W) break;
            for (int k = 0; k < w[2].size(); ++k) {
                if (w0 * i + w1 * j + w2 * k > W) break;
                for (int l = 0; l < w[3].size(); ++l) {
                    if (w0 * i + w1 * j + w2 * k + w3 * l > W) break;
                    result = max(w[0][i] + w[1][j] + w[2][k] + w[3][l], result);
                }
            }
        }
    }
    cout << result << endl;
}
