#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int m = 0;
    int amax = 0;
    int amax2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > amax) {
            amax2 = amax;
            amax = a[i];
            m = i;
        } else if (a[i] > amax2) {
            amax2 = a[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (m == i) {
            cout << amax2 << endl;
        } else {
            cout << amax << endl;
        }
    }
}
