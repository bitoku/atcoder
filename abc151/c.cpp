#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> wa(n);
    vector<bool> ac(n);
    for (int i = 0; i < m; ++i) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (s == "AC") ac[p] = true;
        else if (!ac[p]) wa[p]++;
    }
    ll penalty = 0;
    ll accnt = 0;
    for (int i = 0; i < n; ++i) {
        if (ac[i]) {
            accnt++;
            penalty += wa[i];
        }
    }
    cout << accnt << ' ' << penalty << endl;
}
