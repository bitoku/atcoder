#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll W, H;
    cin >> W >> H;
    vector<ll> p(W);
    vector<ll> q(H);
    for (int i = 0; i < W; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < H; ++i) {
        cin >> q[i];
    }
    vector<int> pi(W);
    vector<int> qi(H);
    iota(pi.begin(), pi.end(), 0);
    iota(qi.begin(), qi.end(), 0);
    sort(pi.begin(), pi.end(), [&](int i, int j) {return p[i] < p[j];});
    sort(qi.begin(), qi.end(), [&](int i, int j) {return q[i] < q[j];});
    int pii = 0;
    int qii = 0;
    ll result = 0;
    while (pii < W && qii < H) {
        if (p[pi[pii]] < q[qi[qii]]) {
            result += p[pi[pii]] * (H + 1 - qii);
            pii++;
        } else {
            result += q[qi[qii]] * (W + 1 - pii);
            qii++;
        }
    }
    if (pii == W) {
        for (int i = qii; i < H; ++i) {
            result += q[qi[i]];
        }
    }
    if (qii == H) {
        for (int i = pii; i < W; ++i) {
            result += p[pi[i]];
        }
    }
    cout << result << endl;
}