#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<string> ss(n);
    int cnt = 0;
    int head_b = 0;
    int tail_a = 0;
    int head_tail_ab = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ss[i];
        for (int j = 0; j < ss[i].size(); ++j) {
            if (ss[i][j] == 'A' && ss[i][j+1] == 'B') {
                cnt++;
            }
        }
        if (ss[i][0] == 'B' && ss[i][ss[i].size()-1] == 'A') {
            head_tail_ab++;
        } else if (ss[i][0] == 'B') {
            head_b++;
        }
        else if (ss[i][ss[i].size()-1] == 'A') {
            tail_a++;
        }
    }
    if (head_tail_ab > 0) {
        cnt += head_tail_ab - 1;
        if (tail_a > 0) {
            tail_a--;
            cnt++;
        }
        if (head_b > 0){
            head_b--;
            cnt++;
        }
    }
    cout << cnt + min(head_b, tail_a) << endl;
}
