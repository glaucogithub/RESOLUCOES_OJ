
// author: glaucoacassioc
// created on: May 22, 2022 11:57 PM

// Problem: Static Range Sum
// URL: https://judge.yosupo.jp/problem/static_range_sum
// Time Limit: 5000 ms
// Memory Limit: 1024 MB

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")

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

vector<int64_t> pref;

void run_case() {
	int N, Q;
	cin >> N >> Q;
	vector<int64_t> v(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	pref.assign(N + 1, 0);
	for (int i = 0; i < N; ++i) {
		pref[i + 1] = pref[i] + v[i];
	}
	// ou -> partial_sum(begin(v), end(v), begin(pref) + 1);
	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << pref[b] - pref[a] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	cin.tie(nullptr);
#endif
	int T = 1;
	// cin >> T;
	while (T-- > 0) {
		run_case();
	}
}


