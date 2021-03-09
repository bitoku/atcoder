#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> red(n);
    red[0] = true;
    vector<int> ball(n, 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        ball[x]--;
        ball[y]++;
        if (red[x]) {
            if (ball[x] == 0) {
                red[x] = false;
            }
            red[y] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (red[i]) cnt++;
    }
    cout << cnt << endl;
}
