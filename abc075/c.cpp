#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

bool warshallfloyd(
        vector<vector<long long>>& dist
        ) {
    for (int k = 0; k < dist.size(); ++k) {
        for (int i = 0; i < dist.size(); ++i) {
            for (int j = 0; j < dist.size(); ++j) {
                if (dist[i][k] == LONG_LONG_MAX || dist[k][j] == LONG_LONG_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < dist.size(); ++i) {
        if (dist[i][i] < 0) return false;
    }
    return true;
}

struct vert {
    int from;
    int to;
};

template<class T>
void printVector(vector<T> &a, string delimiter) {
    if (a.size() == 0) return;
    cout << a[0];
    for (int i = 1; i < a.size(); ++i) {
        cout << delimiter << a[i];
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, LONG_LONG_MAX));
    vector<vert> bridge_cands(m);
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        dist[a][b] = 1;
        dist[b][a] = 1;
        bridge_cands[i] = {a, b};
    }
    int result = 0;
    for (int i = 0; i < m; ++i) {
        vector<vector<ll>> temp = dist;
        temp[bridge_cands[i].from][bridge_cands[i].to] = LONG_LONG_MAX;
        temp[bridge_cands[i].to][bridge_cands[i].from] = LONG_LONG_MAX;
        warshallfloyd(temp);
        bool success = true;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (temp[j][k] == LONG_LONG_MAX) {
                   success = false;
                   break;
                }
            }
            if (!success) {
                break;
            }
        }
        if (success) {
            result++;
        }
    }
    cout << m - result << endl;
}
