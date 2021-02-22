#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct P {
    ll x;
    ll y;
};

int main() {
    int n;
    cin >> n;
    vector<P> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        P a = points[i];
        for (int j = i+1; j < n; ++j) {
            P b = points[j];
            for (int k = j+1; k < n; ++k) {
                P c = points[k];
                ll cross = (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
                if (cross != 0 && cross % 2 == 0) result++;
            }
        }
    }
    cout << result << endl;
}
