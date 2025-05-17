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
string s, t;
vector<vi> dp;

int help(int i, int j) {
    if (i == 0) return dp[i][j] = j;
    if (j == 0) return dp[i][j] = i;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i - 1] == t[j - 1]) dp[i][j] = help(i - 1, j - 1);
    else dp[i][j] = min({help(i, j - 1), help(i - 1, j), help(i - 1, j - 1)}) + 1;
    return dp[i][j];
}

void solve(int testcase) {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    dp.assign(n + 1, vi (m + 1, - 1));
    help(n, m);
    cout << dp[n][m] << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}