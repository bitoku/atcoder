#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    set<string> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        m.insert(s);
    }
    cout << m.size() << endl;
}
