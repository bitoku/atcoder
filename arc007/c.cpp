#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int dp[2000];

int dfs(const bitset<10>& bit, const string& s) {
    if (bit.all()) return 1;
    if (dp[bit.to_ulong()] > 0) return dp[bit.to_ulong()];
    int result = 10;
    for (int i = 1; i < 10; ++i) {
        bitset<10> t;
        for (int j = 0; j < 10; ++j) {
            t[j] = s[(j - i + s.size()) % s.size()] == 'o';
        }
        bitset<10> nbit = bit | t;
        if (nbit.count() == bit.count()) continue;
        result = min(result, dfs(nbit, s) + 1);
    }
    dp[bit.to_ulong()] = result;
    return result;
}

int main() {
    string s;
    cin >> s;
    bitset<10> t;
    for (int i = 0; i < 10; ++i) {
        if (s[i % s.size()] == 'o') t[i] = true;
    }
    cout << dfs(t, s) << endl;
}
