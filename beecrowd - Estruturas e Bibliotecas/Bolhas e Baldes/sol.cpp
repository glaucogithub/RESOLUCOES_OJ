
// author: glaucoacassioc
// created on: January 12, 2022 7:29 PM

// Problem: Bolhas e Baldes
// URL: https://www.beecrowd.com.br/judge/pt/problems/view/1088
// Time Limit: 3000 ms
// Memory Limit: 1024 MB

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


// The following implementation can be used like the other implementations, however it uses one-based indexing internally.
struct FenwickTreeOneBasedIndexing {
	vector<int64_t> bit;  // binary indexed tree
	int n;

	FenwickTreeOneBasedIndexing(int n) {
		this->n = n + 1;
		bit.assign(n + 1, 0);
	}

	FenwickTreeOneBasedIndexing(vector<int> a)
		: FenwickTreeOneBasedIndexing(a.size()) {
		for (size_t i = 0; i < a.size(); i++) {
			add(i, a[i]);
		}
	}

	int64_t sum(int pos) {
		int64_t ret = 0;
		for (; pos > 0; pos -= pos & (-pos)) {
			ret += bit[pos];
		}
		return ret;
	}

	int64_t sum(int l, int r) {
		return sum(r) - (l == 1 ? 0 : sum(l - 1));
	}

	void add(int pos, int val) {
		for (; pos < (int)bit.size(); pos += pos & (-pos)) {
			bit[pos] += val;
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
		for (int j = 0; j < n; ++j) {
			FT.add(v[j], 1);
			ans += FT.sum(greater) - FT.sum(v[j]);
		}
		cout << (ans & 1 ? "Marcelo" : "Carlos") << '\n';
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
