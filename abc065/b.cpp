#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n+1);
    int c = 1;
    int cnt = 0;
    while (b[c] == 0) {
        b[c] = 1;
        c = a[c];
        cnt++;
        if (c == 2) {
            cout << cnt << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
