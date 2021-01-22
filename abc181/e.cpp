#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> students(n);
    vector<ll> teacher(m);
    vector<ll> diff(n - 1);
    vector<ll> prebase(n);
    vector<ll> postbase(n);
    ll ans = 1000000000000000;
    for (int i = 0; i < n; ++i) {
        cin >> students[i];
    }
    sort(students.begin(), students.end());
    for (int i = 0; i < m; ++i) {
        cin >> teacher[i];
    }
    for (int i = 1; i < n; i++) {
        diff[i-1] = students[i] - students[i - 1];
    }
    prebase[0] = 0;
    for (int i = 1; i*2 < n; i++) {
         prebase[i] = diff[i*2-2] + prebase[i-1];
//         cout << prebase[i] << endl;
    }
    postbase[0] = 0;
    for (int i = 1; i*2-1 < n; i++) {
        postbase[i] = diff[i*2-1] + postbase[i-1];
//        cout << postbase[i] << endl;
    }
    for (int i = 0; i < m; ++i) {
        auto it = lower_bound(students.begin(), students.end(), teacher[i]);
        long idx = distance(students.begin(), it);
        ll ret = prebase[idx / 2];
        ret += postbase[n / 2] - postbase[idx / 2];
        ret += abs(teacher[i] - students[(idx / 2) * 2]);
//        cout << teacher[i] << ' ' << idx << ' ' << idx / 2 << ' ' << ret << endl;
        ans = min(ans, ret);
    }
    cout << ans << endl;
}
