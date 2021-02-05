#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cout << 0 << endl;
    cin >> s;
    if (s == "Vacant") return 0;
    string before = s;
    int before_idx = 0;
    int left = 0;
    int right = n-1;
    for (int i = 0; i < 20; ++i) {
        int mid = (left + right) / 2;
        if (mid == before_idx) {
            cout << right << endl;
        } else {
            cout << mid << endl;
        }
        cin >> s;
        if (
          ((mid - before_idx) % 2 == 0 && before != s) ||
          ((mid - before_idx) % 2 == 1 && before == s)
          ) {
            right = mid - 1;
        } else {
            left = mid + 1;
            before = s;
            before_idx = mid;
        }
        if (s == "Vacant") {
            return 0;
        }
    }
}
