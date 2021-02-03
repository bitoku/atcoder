#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct point {
    int h;
    int x;
    int y;
};

int main() {
    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].h;
    }
    sort(p.begin(), p.end(), [](point a, point b){
        return a.h > b.h;
    });
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {
            bool ok = true;
            ll H = -1;
            for (int i = 0; i < n; ++i) {
                if (H == -1) {
                    H = p[i].h + abs(p[i].x - x) + abs(p[i].y - y);
                    continue;
                }
                if (p[i].h != max(H - abs(p[i].x - x) - abs(p[i].y - y), 0ll)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << x << ' ' << y << ' ' << H << endl;
            }
        }
    }
}
