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
    int n, m, q; cin >> n >> m >> q;
    vector<vll> dist(n + 1, vll (n + 1, LLONG_MAX));
    rep(i, 0, m) {
        int u, v; ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    rep(i, 1, n + 1) dist[i][i] = 0;
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            rep(k, 1, n + 1) {
                if (dist[j][i] != LLONG_MAX and dist[i][k] != LLONG_MAX) {
                    if (dist[j][i] + dist[i][k] < dist[j][k]) {
                        dist[j][k] = dist[j][i] + dist[i][k];
                    }
                }
            }
        }
    }
    rep(i, 0, q) {
        int u, v; cin >> u >> v;
        if (dist[u][v] == LLONG_MAX) cout << -1 << "\n";
        else cout << dist[u][v] << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}