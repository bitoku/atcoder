#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    multiset<pair<int, int>> costs;
    ll C;
    cin >> C;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        costs.insert(make_pair(a, c));
        costs.insert(make_pair(b+1, -c));
    }
    ll current = 0;
    ll total = 0;
    int before_day = 0;
    for (auto p: costs) {
        if (before_day < p.first) {
            total += (p.first - before_day) * min(C, current);
        }
        current += p.second;
        before_day = p.first;
    }
    cout << total << endl;
}
