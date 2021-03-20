#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int memo[1 << 16][20][20];
int h, w;

ll dfs(ll s, ll a, ll b) {
    if (memo[s][a][b]) return memo[s][a][b];
    int t = -1;
    for (int i = 0; i < h * w; ++i) {
        if (!(s & (1 << i))) {
            t = i;
            break;
        }
    }
    if (t == -1 && a == 0 && b == 0) return 1;
    ll ret = 0;
    if (a > 0 && t % w != w - 1) {
        ret += dfs(s | (1 << t) | (1 << (t+1)), a-1, b);
    }
    if (a > 0 && t / w != h - 1) {
        ret += dfs(s | (1 << t) | (1 << (t + w)), a-1, b);
    }
    if (b > 0) {
        ret += dfs(s | (1 << t), a, b-1);
    }
    memo[s][a][b] = ret;
    return ret;
}

int main() {
    cin >> h >> w;
    int a, b;
    cin >> a >> b;
    cout << dfs(0, a, b) << endl;
}
