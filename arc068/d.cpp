#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

//int main() {
//    int n;
//    cin >> n;
//    map<int, int> cnt;
//    priority_queue<int> pq;
//    for (int i = 0; i < n; ++i) {
//        int a;
//        cin >> a;
//        cnt[a]++;
//    }
//    for (auto c: cnt) {
//        pq.push(c.second);
//    }
//    while (pq.top() > 1) {
//        int first = pq.top(); pq.pop();
//        if (first >= 3) {
//            pq.push(first - 2);
//            continue;
//        }
//        int second = pq.top(); pq.pop();
//        pq.push(first - 1);
//        if (second > 1) {
//            pq.push(second - 1);
//        }
//    }
//    cout << pq.size() << endl;
//}

int main() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    if (cnt.size() % 2 == 1) {
        cout << cnt.size() << endl;
    } else {
        cout << cnt.size()-1 << endl;
    }
}
