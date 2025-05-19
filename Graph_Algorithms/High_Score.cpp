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
    vector<tuple<int, int, ll>> edge;
    vector<vi> g(n + 1);
    rep(i, 0, m) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edge.push_back({u, v, -w});
        g[u].push_back(v);
    }
    vll dis(n + 1, LLONG_MAX);
    dis[1] = 0;
    rep(i, 1, n) {
        for (auto& [u, v, w]:edge) {
            if (dis[u] < LLONG_MAX and dis[u] + w < dis[v]) dis[v] = dis[u] + w;
        }
    }
    vector<bool> cyc(n + 1, false);
    for (auto [u, v, w] : edge) {
        if (dis[u] < LLONG_MAX and dis[u] + w < dis[v]) {
            cyc[v] = true;
        }
    }
    vector<bool> vis(n + 1, false);
    bool ok = true;
    function<void(int)> dfs = [&] (int node) {
        vis[node] = true;
        if (node == n) {
            ok = false;
            return;
        }
        for (auto neigh:g[node]) {
            if (!vis[neigh]) dfs(neigh);
        }
    };
    rep(i, 1, n + 1){
        if (cyc[i] and !vis[i]) dfs(i);
    }
    if (!ok) cout << -1 << "\n";
    else cout << -dis[n] << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}