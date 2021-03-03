#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int r, c;
    cin >> r >> c;
    int sh, sw, gh, gw;
    cin >> sh >> sw;
    sh--; sw--;
    cin >> gh >> gw;
    gh--; gw--;
    vector<vector<int>> d(r, vector<int>(c, -1));
    vector<string> s(r);
    for (int i = 0; i < r; ++i) {
        cin >> s[i];
    }
    deque<pair<int, int>> dq;
    dq.emplace_back(sh, sw);
    while (!dq.empty()) {
        const auto [h, w] = dq.front(); dq.pop_front();
        int dirs[4][2] = {
                {-1, 0},
                {0, -1},
                {1, 0},
                {0, 1}
        };
        for (auto & dir : dirs) {
            int nh = h + dir[0];
            int nw = w + dir[1];
            if (s[nh][nw] == '#') continue;
            if (d[nh][nw] >= 0) continue;
            dq.emplace_back(nh, nw);
            d[nh][nw] = d[h][w] + 1;
            if (gh == nh && gw == nw) {
                cout << d[nh][nw]+1 << endl;
                return 0;
            }
        }
    }
}
