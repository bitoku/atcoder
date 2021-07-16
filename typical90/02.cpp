#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

vector<string> dfs(int n, int x) {
    vector<string> s;
    if (n == 0) {
        return s;
    }
    if (n == x) {
        s.emplace_back(x, ')');
        return s;
    }
    if (x == 0) {
        vector<string> ss = dfs(n - 1, 1);
        for (auto& t: ss) {
            s.push_back("(" + t);
        }
    } else {
        vector<string> ss = dfs(n - 1, x + 1);
        for (auto& t: ss) {
            s.push_back("(" + t);
        }
        vector<string> tt = dfs(n - 1, x - 1);
        for (auto& t: tt) {
            s.push_back(")" + t);
        }
    }
    return s;
}

int main() {
    ll n;
    cin >> n;
    if (n % 2 == 1) return 0;
    vector<string> s = dfs(n, 0);
    for (auto& t: s) {
        cout << t << endl;
    }
}