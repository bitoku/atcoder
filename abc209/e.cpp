#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 07/10

int main() {
    ll n;
    cin >> n;
    vector<string> s(n);
    map<string, vector<string>> revgraph;
    map<string, ll> head;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        revgraph[s[i].substr(s[i].size()-3, 3)].push_back(s[i].substr(0, 3));
        revgraph[s[i].substr(0, 3)];
        head[s[i].substr(0, 3)]++;
    }
    deque<string> dq;
    map<string, int> ans;
    for (auto& [t, _]: revgraph) {
        if (head[t] == 0) {
            dq.push_back(t);
            ans[t] = -1;
        }
    }
    while (!dq.empty()) {
        string t = dq.front(); dq.pop_front();
        for (string u: revgraph[t]) {
            if (ans[u] != 0) continue;
            head[u]--;
            if (ans[t] == -1) {
                ans[u] = 1;
                dq.push_back(u);
            } else if (head[u] == 0) {
                ans[u] = -1;
                dq.push_back(u);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int a = ans[s[i].substr(s[i].size()-3, 3)];
        if (a == 1) cout << "Aoki" << endl;
        else if (a == 0) cout << "Draw" << endl;
        else cout << "Takahashi" << endl;
    }
}