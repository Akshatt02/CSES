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
const int MOD = 1e9 + 7;

int n, m;
vi a;
vector<vi> dp;

int help(int i, int j) {
    if (j < 0 or j > m) return 0;
    if (i == 0) {
        if (a[i] == 0 or a[i] == j) return 1;
        else return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] != 0 and a[i] != j) return 0;
    dp[i][j] = help(i - 1, j) + help(i - 1, j - 1) + help(i - 1, j + 1);
    return dp[i][j];
}

void solve(int testcase) {
    cin >> n >> m;
    a.resize(n); f(a);
    dp.assign(n, vi (m + 2, -1));
    ll ans = 0;
    if (a[n - 1] == 0) {
        rep(i, 1, m + 1) ans += help(n - 1, i);
    }
    else ans = help(n - 1, a[n - 1]);
    cout << ans << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}