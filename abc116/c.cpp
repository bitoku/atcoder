#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> h(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    ll result = 0;
    vector<int> x(n+1);
    for (int i = 1; i <= n; ++i) {
        while (x[i] < h[i]) {
            for (int j = i; j <= n && x[j] < h[j]; ++j) {
                x[j]++;
            }
            result++;
        }
    }
    cout << result << endl;
}
