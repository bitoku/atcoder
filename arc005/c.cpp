#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> c(h);
    for (int i = 0; i < h; ++i) {
        cin >> c[i];
    }
    ll sh, sw, gh, gw;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (c[i][j] == 's') {
                sh = i;
                sw = j;
            }
            if (c[i][j] == 'g') {
                gh = i;
                gw = j;
            }
        }
    }
    priority_queue<tuple<ll, int, int, int>> pq;
    pq.push(make_tuple(0, sh, sw, 2));
    vector<vector<vector<ll>>> dist(h, vector<vector<ll>>(w, vector<ll>(3, -1)));
    while (!pq.empty()) {
        auto [cost, hh, ww, p] = pq.top(); pq.pop();
        if (dist[hh][ww][p] != -1) continue;
        dist[hh][ww][p] = cost;
        if (hh == gh && ww == gw) break;
        if (hh + 1 < h && dist[hh+1][ww][p] == -1) {
            if (c[hh+1][ww] == '#') {
                if (p > 0) pq.push(make_tuple(cost+1, hh+1, ww, p-1));
            } else {
                pq.push(make_tuple(cost+1, hh+1, ww, p));
            }
        }
        if (hh - 1 >= 0 && dist[hh-1][ww][p] == -1) {
            if (c[hh-1][ww] == '#') {
                if (p > 0) pq.push(make_tuple(cost+1, hh-1, ww, p-1));
            } else {
                pq.push(make_tuple(cost+1, hh-1, ww, p));
            }
        }
        if (ww + 1 < w && dist[hh][ww+1][p] == -1) {
            if (c[hh][ww+1] == '#') {
                if (p > 0) pq.push(make_tuple(cost+1, hh, ww+1, p-1));
            } else {
                pq.push(make_tuple(cost+1, hh, ww+1, p));
            }
        }
        if (ww - 1 >= 0 && dist[hh][ww-1][p] == -1) {
            if (c[hh][ww-1] == '#') {
                if (p > 0) pq.push(make_tuple(cost+1, hh, ww-1, p-1));
            } else {
                pq.push(make_tuple(cost+1, hh, ww-1, p));
            }
        }
    }
    if (dist[gh][gw][0] == -1 && dist[gh][gw][1] == -1 && dist[gh][gw][2] == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}