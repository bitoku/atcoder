#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        vector<int> b(n+1);
        for (int j = 0; j < n; ++j) {
            b[max(0, j - a[j])]++;
            b[min(n, j + a[j] + 1)]--;
        }
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            cnt += b[j];
            a[j] = cnt;
            if (a[j] == 0) {
                a[j]++;
            }
        }
        bool end = true;
        for (int j = 0; j < n; ++j) {
            if (a[j] != n) {
                end = false;
                break;
            }
        }
        if (end) {
            cout << n;
            for (int j = 1; j < n; ++j) {
                cout << ' ' << n;
            }
            cout << endl;
            return 0;
        }
    }
    cout << a[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << a[i];
    }
    cout << endl;

}
