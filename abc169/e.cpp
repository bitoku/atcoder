#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> aa, bb;
    vector<pair<int, int>> cc;
    for (int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        aa.push_back(a);
        bb.push_back(b);
        cc.push_back(make_pair(a, b));
    }
    int minmed, maxmed;
    sort(aa.begin(), aa.end());
    if (n % 2 == 0) {
        minmed = (aa[n/2] + aa[n/2-1]);
    } else {
        minmed = 2 * aa[n/2-1];
    }
    sort(bb.begin(), bb.end());
    if (n % 2 == 0) {
        maxmed = (aa[n/2] + aa[n/2-1]);
    } else {
        maxmed = 2 * aa[n/2-1];
    }

    int cnt = 0;
    cout << minmed << endl;
    cout << maxmed << endl;
    for (int i=minmed+1;i<maxmed; i++) {
        auto it = lower_bound(aa.begin(), aa.end(), i/2);
        if (*it == i) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}