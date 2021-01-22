#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int h, w;
const int INF = INT_MAX / 2;

struct Point {
    int x;
    int y;
};

void dijkstra(
        const vector<string>& map,
        vector<vector<ll>>& dist
        ) {
    typedef pair<ll, Point> P;
    queue<P> q;
    Point initPoint = {0};
    vector<Point> warp[26];
    bool warped[26] = {false};
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            dist[i][j] = INF;
            if (map[i][j] == 'S') {
                initPoint.x = i;
                initPoint.y = j;
            }
            if ('a' <= map[i][j] && map[i][j] <= 'z') {
                warp[map[i][j] - 'a'].push_back(Point{x: i, y: j});
            }
        }
    }
    q.push(P(0, initPoint));
    dist[initPoint.x][initPoint.y] = 0;
    while (!q.empty()) {
        auto info = q.front(); q.pop();
        Point cur = info.second;
        char c = map[cur.x][cur.y];

        ll xs[4] = {1, -1, 0, 0};
        ll ys[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i) {
            Point next = {x: static_cast<int>(cur.x + xs[i]), y: static_cast<int>(cur.y + ys[i])};
            if ((next.x < 0 || next.x >= h) || (next.y < 0 || next.y >= w) || (map[next.x][next.y] == '#')) {
                continue;
            }
            if (dist[next.x][next.y] != INF) {
                continue;
            }
            dist[next.x][next.y] = info.first + 1;
            q.push(P(dist[next.x][next.y], next));
        }
        if ('a' <= c && c <= 'z' && !warped[c - 'a']) {
            warped[c - 'a'] = true;
            for (const auto next: warp[c - 'a']) {
                if (dist[next.x][next.y] != INF) {
                    continue;
                }
                dist[next.x][next.y] = info.first + 1;
                q.push(P(dist[next.x][next.y], next));
            }
        }
    }
}

int main() {
    cin >> h >> w;
    vector<string> m(h);
    vector<vector<ll>> dist(h, vector<ll>(w));
    for (int i = 0; i < h; ++i) {
        cin >> m[i];
    }
    dijkstra(m, dist);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (m[i][j] == 'G') {
                if (dist[i][j] == INF) {
                    cout << -1 << endl;
                } else {
                    cout << dist[i][j] << endl;
                }
                return 0;
            }
        }
    }
}
