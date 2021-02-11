#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> cnt(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        cnt[p[i]] = cnt[p[i]-1] + 1;
    }
    int m = *max_element(cnt.begin(), cnt.end());
    cout << n - m << endl;
}
