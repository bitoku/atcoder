#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int mdigits[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> v;

string memo[10001];

string& max_string(string& a, string& b) {
    if (a.size() > b.size()) return a;
    else if (a.size() < b.size()) return b;
    for (int i = a.size()-1; i >= 0; --i) {
        if (a[i] > b[i]) return a;
        else if (a[i] < b[i]) return b;
    }
}

string dfs(int n) {
    if (n == 0) return "0";
    if (!memo[n].empty()) return memo[n];
    string s;
    for (const auto x : v) {
        if (n < mdigits[x]) continue;
        string ss = dfs(n - mdigits[x]);
        if (ss.empty()) continue;
        ss.push_back('0' + x);
        s = max_string(s, ss);
    }
    memo[n] = s;
    return s;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    string s = dfs(n);
    reverse(s.begin(), s.end());
    s.pop_back();
    cout << s << endl;
}
