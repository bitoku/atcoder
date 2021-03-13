#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        result += a[i] - 1;
    }
    cout << result << endl;
}
