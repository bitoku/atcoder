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

int main(){
    int n, m;
    cin >> n >> m;
    vector<bool> reached[3];
    vector<int> dist[3];
    unordered_map<int, set<int>> linked_nodes;

    repeat(i, 3){
        reached[i].resize(n, false);
        dist[i].resize(n, INF);
    }

    repeat(i, m){
        int a, b; cin >> a >> b;
        linked_nodes[a-1].insert(b-1);
    }

    int s, t; cin >> s >> t;
    s--; t--;
    dist[0][s] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(0, s));
    while(not q.empty()){
        int step = q.front().first;
        int node = q.front().second;
        int next_step = (step + 1) % 3;
        q.pop();
        for(auto next_node: linked_nodes[node]){
            if(reached[next_step][next_node]) continue;
            q.push(make_pair(next_step, next_node));
            reached[next_step][next_node] = true;
            if(step == 2){
                chmin(dist[next_step][next_node], dist[step][node]+1);
            }else{
                chmin(dist[next_step][next_node], dist[step][node]);
            }
        }
    }

    if(dist[0][t] == INF) cout << -1 << endl;
    else cout << dist[0][t] << endl;
    return 0;
}