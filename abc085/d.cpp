#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> swing(n);
    vector<int> throwing(n);
    for (int i = 0; i < n; ++i) {
        cin >> swing[i] >> throwing[i];
    }
    sort(swing.begin(), swing.end());
    sort(throwing.begin(), throwing.end());
    ll result = 0;
    while (h > 0) {
        if (throwing.back() > swing.back()) {
            h -= throwing.back();
            throwing.pop_back();
            result++;
        } else {
            if (h % swing.back() == 0) {
                result += h / swing.back();
            } else {
                result += h / swing.back() + 1;
            }
            break;
        }
    }
    cout << result << endl;
}
