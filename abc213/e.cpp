#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int H, W;

int make_idx(int h, int w) {
    return h * W + w;
}

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 0});
    vector<vector<ll>> dist(H, vector<ll>(W, LONG_LONG_MAX));
    while (!pq.empty()) {
        auto [c, x] = pq.top(); pq.pop();
        int h = x / W;
        int w = x % W;
        if (dist[h][w] < c) continue;
        if (w > 0 && S[h][w-1] != '#' && dist[h][w-1] > c) {
            dist[h][w-1] = c;
            pq.push({c, make_idx(h, w-1)});
        }
        if (w < W - 1 && S[h][w+1] != '#' && dist[h][w+1] > c) {
            dist[h][w+1] = c;
            pq.push({c, make_idx(h, w+1)});
        }
        if (h > 0 && S[h-1][w] != '#' && dist[h-1][w] > c) {
            dist[h-1][w] = c;
            pq.push({c, make_idx(h-1, w)});
        }
        if (h < H - 1 && S[h+1][w] != '#' && dist[h+1][w] > c) {
            dist[h+1][w] = c;
            pq.push({c, make_idx(h+1, w)});
        }
        for (int row: {-2, -1, 0, 1, 2}) {
            for (int col: {-2, -1, 0, 1, 2}) {
                if (abs(row) + abs(col) == 4) continue;
                if (0 <= w + col && w + col < W && 0 <= h + row && h + row < H && dist[h + row][w + col] > c + 1) {
                    dist[h+row][w+col] = c+1;
                    pq.push({c+1, make_idx(h+row, w+col)});
                }
            }
        }
    }
    cout << dist[H-1][W-1] << endl;
}