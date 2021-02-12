#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template <class T>
class Edge {
public:
    int rev, from, to;
    T cap, original_cap;
    Edge(int rev_, int from_, int to_, T cap_) :
            rev(rev_),
            from(from_),
            to(to_),
            cap(cap_),
            original_cap(cap_) {}
};

template <class T>
class Graph {
public:
    vector<vector<Edge<T>>> G;
    explicit Graph(int n = 0) : G(n) {}
    vector<Edge<T>>& operator[](int i) { return G[i]; }
    size_t size() const { return G.size(); }
    Edge<T>& redge(Edge<T> e) {
        return G[e.to][e.rev];
    }
    void add_edge(int from, int to, T cap) {
        G[from].push_back(Edge<T>((int)G[to].size(), from, to, cap));
        G[to].push_back(Edge<T>((int)G[from].size()-1, to, from, 0));
    }
};

template <class T>
struct FordFulkerson {
    const T INF = 1e9;
    vector<int> used;

    FordFulkerson()= default;
    T dfs(Graph<T>& G, int v, int t, T f) {
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                T d = dfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G.redge(e).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(Graph<T>& G, int s, int t) {
        T flow = 0;
        while (true) {
            used.assign(G.size(), 0);
            T f = dfs(G, s, t, INF);
            if (f == 0) {
                return flow;
            } else {
                flow += f;
            }
        }
        return 0;
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> reds(n);
    vector<pair<int, int>> blues(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        reds[i] = make_pair(x, y);
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        blues[i] = make_pair(x, y);
    }
    Graph<int> g(2 * n + 2);
    for (int i = 0; i < n; ++i) {
        g.add_edge(0, 1 + i, 1);
    }
    for (int i = 0; i < n; ++i) {
        g.add_edge(1 + n + i, 2 * n + 1, 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (reds[i].first < blues[j].first && reds[i].second < blues[j].second) {
                g.add_edge(1 + i, 1 + n + j, 1);
            }
        }
    }
    FordFulkerson<int> ff;
    cout << ff.max_flow(g, 0, 2 * n + 1) << endl;
}
