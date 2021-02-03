#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> ab(n);
    ll bsum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        bsum += b[i];
        ab[i] = a[i] + b[i];
    }
    ll result = -bsum;
    sort(ab.begin(), ab.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 1) continue;
        result += ab[i];
    }
    cout << result << endl;
}

//int main() {
//    int n;
//    cin >> n;
//    vector<ll> a(n);
//    vector<ll> b(n);
//    ll asum = 0;
//    ll bsum = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i] >> b[i];
//        asum += a[i];
//        bsum += b[i];
//    }
//    vector<ll> suba(n);
//    vector<ll> subb(n);
//    vector<int> indices_a(n);
//    vector<int> indices_b(n);
//    iota(indices_a.begin(), indices_a.end(), 0);
//    iota(indices_b.begin(), indices_b.end(), 0);
//    for (int i = 0; i < n; ++i) {
//        suba[i] = asum - a[i] - b[i];
//        subb[i] = bsum - a[i] - b[i];
//    }
//    ll happiness_a = 0;
//    ll happiness_b = 0;
//    sort(indices_a.begin(), indices_a.end(), [&suba](int x, int y) {
//        return suba[x] < suba[y];
//    });
//    sort(indices_b.begin(), indices_b.end(), [&subb](int x, int y) {
//        return subb[x] < subb[y];
//    });
//    vector<bool> done(n);
//    int ia = 0;
//    int ib = 0;
//    int i = 0;
//    while (ia < n && ib < n) {
//        if (i % 2 == 0) {
//            int idx = indices_a[ia];
//            if (done[idx]) {
//                ia++;
//                continue;
//            }
//            happiness_a += a[idx];
//            done[idx] = true;
//        } else {
//            int idx = indices_b[ib];
//            if (done[idx]) {
//                ib++;
//                continue;
//            }
//            happiness_b += b[idx];
//            done[idx] = true;
//        }
//        i++;
//    }
//    cout << happiness_a - happiness_b << endl;
//}
