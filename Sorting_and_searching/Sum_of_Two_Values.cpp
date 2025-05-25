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
struct custom_hash { // custom hash function for unordered_map and unordered_set
    static uint64_t splitmix64(uint64_t x) {
    // Usage: unordered_map<long long, int, custom_hash> safe_map;
    // Usage: unordered_set<long long, custom_hash> safe_set;
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve(int testcase) {
    int n, x; cin >> n >> x;
    unordered_map<int, int, custom_hash> mp;
    rep(i, 0, n) {
        int el; cin >> el;
        if (mp.find(x - el) != mp.end()) {
            cout << i + 1 << " " << mp[x - el] + 1 << "\n";
            return;
        }
        else mp[el] = i;
    }
    cout << "IMPOSSIBLE\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    int _t = 1;
    //cin >> _t;
    while(_t--) solve(_t);
}