#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll R, C;
    cin >> R >> C;
    vector<vector<ll>> a(R, vector<ll>(C-1));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C - 1; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> b(R-1, vector<ll>(C));
    for (int i = 0; i < R - 1; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> b[i][j];
        }
    }
    priority_queue<tuple<ll, int, int, int>, vector<tuple<ll, int, int, int>>, greater<>> pq;
    pq.push(make_tuple(0, 0, 0, 0));
    vector<vector<vector<ll>>> dist(2, vector<vector<ll>>(R, vector<ll>(C, -1)));
    while (!pq.empty()) {
        auto [cost, f, r, c] = pq.top(); pq.pop();
        if (dist[f][r][c] != -1) continue;
        dist[f][r][c] = cost;
        if (f == 0 && r == R-1 && c == C-1) break;
        if (f == 0) {
            if (c + 1 < C && dist[0][r][c + 1] == -1) pq.push(make_tuple(cost + a[r][c], 0, r, c + 1));
            if (c - 1 >= 0 && dist[0][r][c - 1] == -1) pq.push(make_tuple(cost + a[r][c - 1], 0, r, c - 1));
            if (r + 1 < R && dist[0][r + 1][c] == -1) pq.push(make_tuple(cost + b[r][c], 0, r + 1, c));
            if (dist[1][r][c] == -1) pq.push(make_tuple(cost + 1, 1, r, c));
        } else {
            if (dist[0][r][c] == -1) pq.push(make_tuple(cost, 0, r, c));
            if (r - 1 >= 0 && dist[1][r - 1][c] == -1) pq.push(make_tuple(cost + 1, 1, r - 1, c));
        }
    }
    cout << dist[0][R-1][C-1] << endl;
}