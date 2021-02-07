#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    int ch, cw;
    cin >> ch >> cw;
    ch--; cw--;
    int dh,dw;
    cin >> dh >> dw;
    dh--; dw--;
    int dpos = dh * w + dw;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    vector<bool> done(h * w);
    pq.push(make_pair(0, ch * w + cw));
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        int cost = x.first;
        int pos = x.second;
        if (done[pos]) continue;
        done[pos] = true;
        if (pos == dpos) {
            cout << cost << endl;
            return 0;
        }
        int ph = pos / w;
        int pw = pos % w;
        int dirs[4][2] = {
          {-1, 0},
          {0, -1},
          {1, 0},
          {0, 1}
        };
        for (auto & dir : dirs) {
            int nh = ph + dir[0];
            int nw = pw + dir[1];
            if (nh < 0 || nh >= h || nw < 0 || nw >= w) continue;
            int npos = nh * w + nw;
            if (done[npos]) continue;
            if (s[nh][nw] == '#') continue;
            pq.push(make_pair(cost, npos));
        }
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                int nh = ph + i;
                int nw = pw + j;
                if (nh < 0 || nh >= h || nw < 0 || nw >= w) continue;
                int npos = nh * w + nw;
                if (done[npos]) continue;
                if (s[nh][nw] == '#') continue;
                pq.push(make_pair(cost+1, npos));
            }
        }
    }
    cout << -1 << endl;
}
