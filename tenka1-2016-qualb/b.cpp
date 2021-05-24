#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

vector<vector<vector<ll>>> dp;

ll dfs(string& s, int i, int mx, int cnt) {
    if (cnt < 0) return LONG_LONG_MAX / 2;
    if (i == s.size()) {
        if (cnt == 0) return mx;
        else return LONG_LONG_MAX / 2;
    }
    if (dp[i][cnt][mx] > 0) return dp[i][cnt][mx];
    ll result = 0;
    if (s[i] == '(') {
        result = min(
                dfs(s, i+1, mx, cnt+1),
                dfs(s, i+1, i, cnt-1) + 1
        );
    } else {
        result = min(
                dfs(s, i+1, i, cnt+1)+1,
                dfs(s, i+1, mx, cnt-1)
        );
    }
    dp[i][cnt][mx] = result;
    return result;
}

int main() {
    string s;
    cin >> s;
    dp.resize(s.size()+1, vector<vector<ll>>(s.size()+1, vector<ll>(s.size()+1, -1)));
    cout << dfs(s, 0, 0, 0) << endl;
}

//int main() {
//    string s;
//    cin >> s;
//    ll cnt = 0;
//    ll result = 0;
//    int cursor = 0;
//    for (int i = 0; i < s.size(); ++i) {
//        if (cnt == s.size() - i) {
//            if (s[i] == '(') {
//                result++;
//                cursor = i;
//            }
//            cnt--;
//            continue;
//        }
//        if (s[i] == '(') cnt++;
//        else cnt--;
//        if (cnt < 0) {
//            cnt += 2;
//            result++;
//            cursor = i;
//        }
//
//    }
//    result += cursor;
//    cnt = 0;
//    cursor = 0;
//    ll temp = 0;
//    for (int i = s.size()-1; i >= 0; --i) {
//        if (cnt == i + 1) {
//            if (s[i] == ')') {
//                temp++;
//                cursor = max(cursor, i);
//            }
//            cnt--;
//            continue;
//        }
//        if (s[i] == ')') cnt++;
//        else cnt--;
//        if (cnt < 0) {
//            cnt += 2;
//            temp++;
//            cursor = max(cursor, i);
//        }
//    }
//    temp += cursor;
//    cout << min(result, temp) << endl;
//
//}