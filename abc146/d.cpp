#include <bits/stdc++.h>
using namespace std;
struct edge {
    int from, to;
    int id;
};

struct vert {
    vector<edge> edges;
};

void rec(vector<vert>& verts, int v, int before, vector<bool>& visited, vector<int>& colors) {
    int color = 1;
    for ( auto& e : verts[v].edges ) {
        if (visited[e.to]) continue;
        visited[e.to] = true;
        if (color == before) color++;
        colors[e.id] = color;
        rec(verts, e.to, color, visited, colors);
        color++;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vert_count(n);
    vector<vert> verts(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        verts[a].edges.push_back(edge{from: a, to: b, id: i});
        verts[b].edges.push_back(edge{from: b, to: a, id: i});
        vert_count[a]++;
        vert_count[b]++;
    }
    auto it = max_element(vert_count.begin(), vert_count.end());
    int k = *it;
    cout << k << endl;

    int idx = (int)distance(vert_count.begin(), it);
    vector<bool> visited(n, false);
    visited[idx] = true;
    vector<int> colors(n-1);
    rec(verts, idx, 0, visited, colors);

    for (const auto c : colors) {
        cout << c << endl;
    }
}
