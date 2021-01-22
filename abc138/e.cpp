#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
#define repeat(i,n) forloop(i, 0, n)
#define forloop(i, a, b) for(int i=(a);i<(b);++i)
#define debug(x) cerr << #x << ": " << x << " " << "(L:" << __LINE__ << ")" << '\n'
template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; };
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; };
const int MOD = 1e9 + 7;
const int64 INF64 = (1LL << 62) - 1;
const int INF = (1 << 30) - 1;

struct point {
    int x;
    int y;
};
