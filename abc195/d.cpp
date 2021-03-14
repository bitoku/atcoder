#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    map<ll, multiset<ll>> baggage;
    for (int i = 0; i < n; ++i) {
        ll w, v;
        cin >> w >> v;
        baggage[w].insert(v);
    }
    vector<ll> box(m);
    for (int i = 0; i < m; ++i) {
        cin >> box[i];
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        vector<ll> nbox;
        for (int j = 0; j < m; ++j) {
            if (l <= j && j < r) continue;
            nbox.push_back(box[j]);
        }
        sort(nbox.begin(), nbox.end());
        map<ll, multiset<ll>> temp = baggage;
        ll result = 0;
        for (long long x : nbox) {
            ll ww, vv;
            vv = 0;
            for (auto& [w, v]: temp) {
                if (w > x) break;
                if (v.empty()) continue;
                if (vv < *rbegin(v)) {
                    vv = *rbegin(v);
                    ww = w;
                }
            }
            if (vv == 0) continue;
            auto it = temp[ww].find(vv);
            temp[ww].erase(it);
            result += vv;
        }
        cout << result << endl;
    }
}
