#include <bits/stdc++.h>
using namespace std;
struct edge {
    int from, to;
    int cost;
};

struct vert {
    vector<edge> edges;
};

void dijkstra(
        const vector<vert>& verts,
        int initPoint,
        vector<long long>& dist,
        vector<int>& prev
        ) {
    typedef pair<long long, int> P;
    priority_queue<P, vector<P>, greater<>> q;
    vector<bool> done(verts.size(), false);
    q.push(P(0, initPoint));
    dist[initPoint] = 0;
    prev[initPoint] = initPoint;
    while (!q.empty()) {
        auto info = q.top(); q.pop();
        int current = info.second;

        if (done[current]) continue;
        done[current] = true;
        for (const auto& e: verts[current].edges) {
            if (done[e.to]) continue;
            if (dist[e.to] > dist[current] + e.cost) {
                dist[e.to] = dist[current] + e.cost;
                prev[e.to] = current;
                q.push(P(dist[e.to], e.to));
            }
        }
    }
}
int main() {
    int H, W, K;
    cin >> H >> W >> K;
}
