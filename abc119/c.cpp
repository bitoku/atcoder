#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial
int a, b, c;

ll dfs(int aa, int bb, int cc, const vector<int>& l, int i) {
    if (i == l.size()) {
        if (min({aa, bb, cc}) == 0) return INT_MAX;
        return abs(aa - a) + abs(bb - b) + abs(cc - c) - 30;
    }
    return min({
                       dfs(aa + l[i], bb, cc, l, i + 1) + 10,
                       dfs(aa, bb + l[i], cc, l, i + 1) + 10,
                       dfs(aa, bb, cc + l[i], l, i + 1) + 10,
                       dfs(aa, bb, cc, l, i + 1),
    });
}

int main() {
    int n;
    cin >> n;
    cin >> a >> b >> c;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    cout << dfs(0, 0, 0, l, 0) << endl;
}
