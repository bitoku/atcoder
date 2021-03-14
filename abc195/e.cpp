#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int dp[200000][7];
string s;
string x;
int n;

int dfs(int i, int mod7) {
    if (dp[i][mod7] > 0) return dp[i][mod7];
    if (i == n && mod7 == 0) return 1;
    if (i == n && mod7 != 0) return 2;
    int ret = 0;
    if (x[i] == 'T') {
        if (dfs(i+1, mod7 * 10 % 7) == 1) ret = 1;
        else if (dfs(i+1, (mod7 * 10 + s[i] - '0') % 7) == 1) ret = 1;
        else ret = 2;
    } else {
        if (dfs(i+1, mod7 * 10 % 7) == 2) ret = 2;
        else if (dfs(i+1, (mod7 * 10 + s[i] - '0') % 7) == 2) ret = 2;
        else ret = 1;
    }
    dp[i][mod7] = ret;
    return ret;
}

int main() {
    cin >> n;
    cin >> s;
    cin >> x;
    if (dfs(0, 0) == 1) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
