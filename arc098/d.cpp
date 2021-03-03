#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int n;
    cin >> n;
    vector<int> bit(20);
    int l = 0;
    ll result = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 20; ++j) {
            if (a[i] & (1 << j)) bit[j]++;
        }
        while (any_of(bit.begin(), bit.end(), [](int x) {return x >= 2;})) {
            result += i - l;
            for (int j = 0; j < 20; ++j) {
                if (a[l] & (1 << j)) bit[j]--;
            }
            l++;
        }
    }
    for (; l < n; ++l) {
        result += n - l;
    }
    cout << result << endl;
}
