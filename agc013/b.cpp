#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    ll n, m;
    cin >> n >> m;
    vector<set<int>> edges(n);
    deque<int> route(2);
    set<int> routeset;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].insert(b);
        edges[b].insert(a);
        if (i == 0) {
            route[0] = a;
            route[1] = b;
        }
    }
    routeset.insert(route[0]);
    routeset.insert(route[1]);
    while (true) {
        bool ok = false;
        for (auto x: edges[route.front()]) {
            if (routeset.find(x) != routeset.end()) continue;
            route.push_front(x);
            routeset.insert(x);
            ok = true;
            break;
        }
        if (ok) continue;
        for (auto x: edges[route.back()]) {
            if (routeset.find(x) != routeset.end()) continue;
            route.push_back(x);
            routeset.insert(x);
            ok = true;
            break;
        }
        if (ok) continue;
        break;
    }
    cout << route.size() << endl;
    cout << route[0] + 1;
    for (int i = 1; i < route.size(); ++i) {
        cout << ' ' << route[i] + 1;
    }
    cout << endl;
}