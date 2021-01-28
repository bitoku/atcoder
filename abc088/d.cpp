#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> m(h);
    for (int i = 0; i < h; ++i) {
        cin >> m[i];
    }
    typedef pair<int, int> P;
    priority_queue<P, vector<P>, greater<>> pq;
    vector<bool> done(h * w);
    int result = 0;
    pq.push(P(0, 0));
    while (!pq.empty()) {
        auto info = pq.top(); pq.pop();
        if (info.second == h * w - 1) {
            result = info.first;
            break;
        }
        if (done[info.second]) {
            continue;
        }
        done[info.second] = true;
        int height = info.second / w;
        int width = info.second % w;
        int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < 4; ++i) {
            int nh = height + direction[i][0];
            int nw = width + direction[i][1];
            if (nh < 0 || nh >= m.size() || nw < 0 || nw >= m[0].size()) {
                continue;
            }
            if (m[nh][nw] == '#') {
                continue;
            }
            pq.push(P(info.first+1, nh * w + nw));
        }
    }
    if (result == 0) {
        cout << -1 << endl;
        return 0;
    }
    int black = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (m[i][j] == '#') {
                black++;
            }
        }
    }
    cout << h * w - black - result - 1 << endl;
}
