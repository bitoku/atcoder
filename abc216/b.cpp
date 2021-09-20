#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    set<string> ss;
    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        if (ss.find(s + " " + t) != ss.end()) {
            cout << "Yes" << endl;
            return 0;
        }
        ss.insert(s + " " + t);
    }
    cout << "No" << endl;
}