#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    auto ita = min_element(a.begin(), a.end());
    auto itb = min_element(b.begin(), b.end());
    if (distance(a.begin(), ita) != distance(b.begin(), itb)) {
        cout << max(*ita, *itb) << endl;
    } else {
        int result = *ita + *itb;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        result = min({result, max(a[0], b[1]), max(a[1], b[0])});
        cout << result << endl;
    }
}
