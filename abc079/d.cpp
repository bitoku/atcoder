#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

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
    int h, w;
    int cost[10][10];
    cin >> h >> w;
    vector<int> a(h * w);
    for (auto & i : cost) {
        for (int & j : i) {
            cin >> j;
        }
    }
    for (int i = 0; i < h * w; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 10; ++i) {
        if (i == 1) continue;
        typedef pair<int, int> P;
        priority_queue<P, vector<P>, greater<>> pq;
        bool done[10] = {false};
        pq.push(make_pair(0, i));
        while (!pq.empty()) {
            auto info = pq.top(); pq.pop();
            int c = info.first;
            int curr = info.second;
            if (done[curr]) continue;
            done[curr] = true;
            if (curr == 1) {
                cost[i][1] = c;
                break;
            }

            for (int j = 0; j < 10; ++j) {
                if (done[j]) continue;
                pq.push(make_pair(c + cost[curr][j], j));
            }
        }
    }
    ll result = 0;
    for (int i = 0; i < h * w; ++i) {
        if (a[i] == -1) continue;
        result += cost[a[i]][1];
    }
    cout << result << endl;
}
