#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<long long>;
using vi = vector<int>;
using ii = pair<int, int>;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define f(a) for (auto& x:a) cin >> x;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(x...) 42
#endif

// Global Variable Declaration


void solve(int testcase) {
    int n, m; cin >> n >> m;
    vector<vi> g(n + 1);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    vi parent(n + 1, -1);
    bool cycle = 0;
    int start = 0, end = 0;
    function<void(int, int)> dfs = [&] (int node, int p) {
        vis[node] = true;
        parent[node] = p;
        for (auto neigh:g[node]) {
            if (neigh != p) {
                if (vis[neigh]) {
                    cycle = true;
                    start = neigh;
                    end = node;
                    return;
                }
                else dfs(neigh, node);
            }
        }
    };
    rep(i, 1, n + 1) {
        if (cycle) break;
        if (!vis[i]) dfs(i, -1);
    }
    if (!cycle) cout << "IMPOSSIBLE\n";
    else {
        vi path;
        int curr = start;
        while (curr != parent[end]) {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (auto x:path) cout << x << " ";
        cout << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}