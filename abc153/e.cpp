#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
void printIter(const T &a, string delimiter) {
    if (a.size() == 0) return;
    auto it = a.begin();
    cout << *it;
    it++;
    while (it != a.end()) {
        cout << delimiter << *it;
        it++;
    }
    cout << endl;
}

int main() {
    int H, N;
    cin >> H >> N;
    vector<pair<int, int>> spell(N);
    int mm = 0;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        mm = max(mm, a);
        spell[i] = make_pair(a, b);
    }
    vector<int> dp(H + mm + 1);
    for (int i = 0; i < H + mm + 1; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i + spell[j].first <= mm || H + mm + 1 <= i + spell[j].first) continue;
            else if (dp[i + spell[j].first] == 0) dp[i + spell[j].first] = dp[i] + spell[j].second;
            else dp[i + spell[j].first] = min(dp[i + spell[j].first], dp[i] + spell[j].second);
        }
    }
//    printIter(dp, " ");
    int m = 0;
    cout << dp[H+mm] << endl;
}
