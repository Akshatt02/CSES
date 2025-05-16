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
    ll n, t; cin >> n >> t;
    vll a(n); f(a);
    ll lo = 1, hi = 1e18;
    ll ans = -1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll prod = 0;
        rep(i, 0, n) {
            prod += (mid / a[i]);
            if (prod >= t) break;
        }
        if (prod >= t) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}