#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    f(a); f(b);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0, j = 0;
    rep(i, 0, n) {
        int desired = a[i];
        while (j < m and b[j] < desired - k) j++;
        if (j < m and b[j] <= desired + k) {
            ans++;
            j++;
        }
    }
    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}