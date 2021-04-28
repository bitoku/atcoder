#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }
    cout << string(w + 2, '#') << endl;
    for (int i = 0; i < h; ++i) {
        cout << '#' << a[i] << '#' << endl;
    }
    cout << string(w + 2, '#') << endl;
}