#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> stair(n+1);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        stair[a] = -1;
    }
    stair[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (stair[i] == -1) continue;
        if (i + 1 <= n && stair[i+1] != -1) {
            stair[i+1] = (stair[i+1] + stair[i]) % mod;
        }
        if (i + 2 <= n && stair[i+2] != -1) {
            stair[i+2] = (stair[i+2] + stair[i]) % mod;
        }
    }
    cout << stair[n] << endl;
}
