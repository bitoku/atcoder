#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        s.insert(make_pair(a, b));
    }
    cout << s.size() << endl;
}
