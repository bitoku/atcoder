#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    typedef pair<int, int> P;
    vector<P> points;
    map<P, int> cnt;
    map<P, int> dist;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        for (auto & point : points) {
            P diff1 = make_pair(x - point.first, y - point.second);
            P diff2 = make_pair(point.first - x, point.second - y);
            cnt[diff1]++;
            cnt[diff2]++;
        }
        points.emplace_back(x, y);
    }

    int m = 0;
    for (auto k : cnt) {
        int c = k.second;
        m = max(m, c);
    }
    cout << n - m << endl;
}
