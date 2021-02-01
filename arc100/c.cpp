#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll sorrow(const vector<int>& a, int b) {
    ll result = 0;
    for (int i = 0; i < a.size(); ++i) {
        result += abs(a[i] - b);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a.begin(), a.end());
    int b = 0;
    if (n % 2 == 1) {
        b = a[n / 2];
    } else {
        b = (a[n / 2] + a[n / 2 - 1]) / 2;
    }
    cout << sorrow(a, b) << endl;
}
