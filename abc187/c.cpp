#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    map<string, ll> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        m[s]++;
    }
    for (const auto& [s, _] : m) {
        if (m["!" + s] > 0) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}
