// author: glaucoacassioc
// created on: January 12, 2022 5:27 PM

// Problem: Bolhas e Baldes
// URL: https://neps.academy/br/course/estruturas-de-dados-(codcad)/lesson/bolhas-e-baldes
// Time Limit: 2000 ms
// Memory Limit: 256 MB

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

struct FenwickTreeOneBasedIndexing {
	vector<int64_t> bit;  // binary indexed tree
	int n;

	FenwickTreeOneBasedIndexing(int n) {
		this->n = n + 1;
		bit.assign(n + 1, 0);
	}

	FenwickTreeOneBasedIndexing(vector<int> a) : FenwickTreeOneBasedIndexing(a.size()) {
		for (size_t i = 0; i < a.size(); i++) {
			add(i, a[i]);
		}
	}

	int64_t sum(int idx) {
		int64_t ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx) {
			ret += bit[idx];
		}
		return ret;
	}

	int64_t sum(int l, int r) {
		return sum(r) - (l == 1 ? 0 : sum(l - 1));
	}

	void add(int idx, int delta) {
		for (++idx; idx < n; idx += idx & -idx) {
			bit[idx] += delta;
		}
	}
};

void run_case() {
	int n;
	while (cin >> n && n != 0) {
		FenwickTreeOneBasedIndexing FT(n + 1);
		vector<int> v(n);
		int greater = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			greater = max(greater, v[i]);
		}
		int64_t ans = 0;
		for (int i = 0; i < n; ++i) {
			FT.add(v[i], 1);
			ans += FT.sum(greater) - FT.sum(v[i]);
		}
		cout << (ans % 2 == 0 ? "Carlos" : "Marcelo") << '\n';
	}
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
