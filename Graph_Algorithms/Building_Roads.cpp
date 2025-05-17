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
vector<bool> vis;
vector<vi> g;

void solve(int testcase) {
    int n, m; cin >> n >> m;
    g.assign(n + 1, {}); vis.assign(n + 1, false);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ii> ans;
    function<void(int)> dfs = [&] (int node) {
        vis[node] = true;
        for(auto neigh:g[node]) {
            if (!vis[neigh]) dfs(neigh);
        }
    };
    dfs(1);
    rep(i, 2, n + 1) {
        if (!vis[i]) {
            dfs(i);
            ans.push_back({i, 1});
        }
    }
    cout << ans.size() << "\n";
    for (auto& [u, v]:ans) cout << u << " " << v << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}