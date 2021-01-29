#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int digit(int n) {
    int result = 0;
    while(n > 0) {
        result++;
        n /= 10;
    }
    return result;
}

//int main() {
//    int n;
//    cin >> n;
//    int x[3] = {3, 5, 7};
//    int d = digit(n);
//    int result = 0;
//    for (int lim = 3; lim <= d; ++lim) {
//        int limlim = pow(3, lim);
//        for (int k = 0; k < limlim; ++k) {
//            vector<int> stack(lim);
//            int tempk = k;
//            for (int i = 0; i < lim; ++i) {
//                stack[stack.size() - i - 1] = tempk % 3;
//                tempk /= 3;
//            }
//            int current = 0;
//            for (int i : stack) {
//                current *= 10;
//                current += x[i];
//            }
//            if (current > n) {
//                cout << result << endl;
//                return 0;
//            }
//            bool numbers[3] = {false};
//            for (int & i : stack) {
//                numbers[i] = true;
//            }
//            if (numbers[0] && numbers[1] && numbers[2]) {
//                result++;
//            }
//        }
//    }
//    cout << result << endl;
//}

int n;

int dfs(ll k) {
    if (k > n) return 0;
    int tempk = k;
    array<int, 3> numbers = {false};
    while (tempk > 0) {
        if (tempk % 10 == 3) numbers[0] = true;
        else if (tempk % 10 == 5) numbers[1] = true;
        else if (tempk % 10 == 7) numbers[2] = true;
        tempk /= 10;
    }
    int ret = 0;
    if (all_of(numbers.begin(), numbers.end(), [](bool x){return x;})) {
        ret++;
    }
    ret += dfs(k * 10 + 3);
    ret += dfs(k * 10 + 5);
    ret += dfs(k * 10 + 7);
    return ret;
}

int main() {
    cin >> n;
    cout << dfs(0) << endl;
}
