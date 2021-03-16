#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = i+1;
    }
    cout << a[1];
    for (int i = 2; i <= n; ++i) {
        cout << ' ' << a[i];
    }
    cout << endl;
}
