#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int H, W, M;
    cin >> H >> W >> M;
    set<pair<int, int>> pos;
    vector<int> hcnt(H+1);
    vector<int> wcnt(W+1);
    for (int i = 0; i < M; ++i) {
        int h, w;
        cin >> h >> w;
        hcnt[h]++;
        wcnt[w]++;
        pos.insert(make_pair(h, w));
    }
    vector<ll> hs;
    ll Hmax = 0;
    for (int i = 1; i <= H; ++i) {
        if (hcnt[i] > Hmax) {
            hs.clear();
            hs.push_back(i);
            Hmax = hcnt[i];
        } else if (hcnt[i] == Hmax) {
            hs.push_back(i);
        }
    }

    vector<ll> ws;
    ll Wmax = 0;
    for (int i = 1; i <= W; ++i) {
        if (wcnt[i] > Wmax) {
            ws.clear();
            ws.push_back(i);
            Wmax = wcnt[i];
        } else if (wcnt[i] == Wmax) {
            ws.push_back(i);
        }
    }
    for (const auto h: hs) {
        for (const auto w: ws) {
            if (pos.find(make_pair(h, w)) == pos.end()) {
                cout << Hmax + Wmax << endl;
                return 0;
            }
        }
    }
    cout << Hmax + Wmax - 1 << endl;
}
