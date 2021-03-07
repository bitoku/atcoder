#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> calendar(13);
    calendar[1] = vector<bool>(32);
    calendar[2] = vector<bool>(30);
    calendar[3] = vector<bool>(32);
    calendar[4] = vector<bool>(31);
    calendar[5] = vector<bool>(32);
    calendar[6] = vector<bool>(31);
    calendar[7] = vector<bool>(32);
    calendar[8] = vector<bool>(32);
    calendar[9] = vector<bool>(31);
    calendar[10] = vector<bool>(32);
    calendar[11] = vector<bool>(31);
    calendar[12] = vector<bool>(32);
    int day_week = 0;
    for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j < calendar[i].size(); ++j) {
            if (day_week == 0 || day_week == 6) calendar[i][j] = true;
            day_week = (day_week + 1) % 7;
        }
    }
    for (int i = 0; i < n; ++i) {
        string md;
        cin >> md;
        auto idx = md.find('/');
        int month = stoi(md.substr(0, idx));
        int day = stoi(md.substr(idx+1, md.size() - idx - 1));
        while (calendar[month][day]) {
            if (++day >= calendar[month].size()) {
                day = 1;
                month++;
            }
            if (month > 12) {
                break;
            }
        }
        if (month > 12) continue;
        calendar[month][day] = true;
    }
    int result = 0;
    int cnt = 0;
    for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j < calendar[i].size(); ++j) {
            if (calendar[i][j]) {
                cnt++;
            }
            else {
                result = max(cnt, result);
                cnt = 0;
            }
        }
    }
    result = max(cnt, result);
    cout << result << endl;
}
