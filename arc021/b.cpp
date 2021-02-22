#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int l;
    cin >> l;
    vector<int> b(l);
    for (int i = 0; i < l; ++i) {
        cin >> b[i];
    }
    vector<int> a(l);
    a[0] = 0;
    for (int i = 0; i < l-1; ++i) {
        a[i+1] = b[i] ^ a[i];
    }
    if ((a[0] ^ a[l-1]) != b[l-1]) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < l; ++i) {
            cout << a[i] << endl;
        }
    }
}
