#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using ii = pair<int, int>;
 
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else  
#define dbg(x...) 42
#endif
 
// Global Variable Declaration
int n, m;
vector<string> g;
 
void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] == '#') return;
    g[i][j] = '#';
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

void solve() {
    cin >> n >> m;
    g.resize(n);
    for (auto& x:g) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    //int _t; cin >> _t; while(_t--)
    solve();
}