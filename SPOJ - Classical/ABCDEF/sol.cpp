
// author: glaucoacassioc
// created on: January 14, 2022 11:11 AM

// Problem: ABCDEF
// URL: https://www.spoj.com/problems/ABCDEF/
// Time Limit: 1000 ms
// Memory Limit: 1536 MB

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
	Fun fun_;
public:
	template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

map<int, int> mp;
//a * b + c == (f + e) * d
void run_case() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int f = 0; f < n; ++f) {
		for (int e = 0; e < n; ++e) {
			for (int d = 0; d < n; ++d) {
				if (arr[d] == 0) {
					continue;
				}
				mp[(arr[f] + arr[e]) * arr[d]]++;
				// dbg(mp[(arr[f] + arr[e]) * arr[d]], (arr[f] + arr[e]) * arr[d]);
			}
		}
	}
	int ans = 0;
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			for (int c = 0; c < n; ++c) {
				ans += mp[arr[a] * arr[b] + arr[c]];
				// dbg(ans, mp[arr[a] * arr[b] + arr[c]], arr[a] * arr[b] + arr[c]);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	cin.tie(nullptr);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	int T = 1;
	// cin >> T;
	while (T-- > 0) {
		run_case();
	}
}
