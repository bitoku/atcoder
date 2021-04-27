#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string o, e;
    cin >> o >> e;
    for (int i = 0; i < o.size() + e.size(); ++i) {
        if (i % 2 == 0) {
            cout << o[i / 2];
        } else {
            cout << e[i / 2];
        }
    }
    cout << endl;
}