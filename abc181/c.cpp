#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    ll x;
    ll y;
};

int main() {
    int n;
    map<int, int> xs;
    map<int, int> ys;
    cin >> n;
    vector<point> ps(n);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i].x >> ps[i].y;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                auto p1 = ps[i];
                auto p2 = ps[j];
                auto p3 = ps[k];
                if (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x * p1.y - p3.x * p2.y == 0) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}
