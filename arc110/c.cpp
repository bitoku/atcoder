#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> result;
    int before = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p[i] = x;
        if (x < i + 1) {
            if (x < before) {
                cout << -1 << endl;
                return 0;
            }
            for (int j = i; j >= x; --j) {
                result.push_back(j);
                swap(p[j], p[j-1]);
            }
            before = i + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (p[i] != i+1) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (result.size() != n-1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << result[i] << endl;
    }
}
