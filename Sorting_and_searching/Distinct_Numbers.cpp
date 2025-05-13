#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
 
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
 
void solve() {
    ll n; cin >> n;
    unordered_set<int, custom_hash> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
}
 
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int _t; cin >> _t; while(_t--)
    solve();
}