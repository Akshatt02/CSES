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
    vi vis(n + 1, 0);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool ok = true;
    function<void(int, int)> dfs = [&] (int node, int color) {
        vis[node] = color;
        for (auto& neigh:g[node]) {
            if (vis[neigh] == color) ok = false;
            if (!vis[neigh]) dfs(neigh, 3 - color);
        }
    };
    rep(i, 1, n + 1) {
        if (!vis[i]) dfs(i, 1);
    }
    if (!ok) cout << "IMPOSSIBLE\n";
    else {
        rep(i, 1, n + 1) cout << vis[i] << " ";
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