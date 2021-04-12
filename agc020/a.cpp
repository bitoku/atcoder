#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    set<pair<int, int>> s;
    while (s.find(make_pair(a, b)) == s.end()) {
        s.insert(make_pair(a, b));
        if (a + 1 == b) {
            if (a - 1 == 0) {
                cout << "Borys" << endl;
                return 0;
            } else {
                a--;
            }
        } else {
            a++;
        }
        if (b - 1 == a) {
            if (b + 1 == n + 1) {
                cout << "Alice" << endl;
                return 0;
            } else {
                b++;
            }
        } else {
            b--;
        }
    }
    cout << "Draw" << endl;
}
