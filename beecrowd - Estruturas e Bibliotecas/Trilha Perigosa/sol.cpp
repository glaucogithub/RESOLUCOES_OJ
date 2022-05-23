
// author: glaucoacassioc
// created on: February 03, 2022 10:09 PM

// Problem: Trilha Perigosa
// URL: https://www.beecrowd.com.br/judge/pt/problems/view/2655
// Time Limit: 1000 ms
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

const int MAXN = 100010, MAXM = 60;

class FenwickTree {
public:
	void update(int pos, int val) {
		for (; pos < MAXN; pos += pos & (-pos)) {
			BIT[pos] += val;
		}
	}

	int64_t query(int pos) {
		int64_t sum = 0;
		for (; pos > 0; pos -= pos & (-pos)) {
			sum += BIT[pos];
		}
		return sum;
	}

	int64_t query(int l, int r) {
		return query(r) - query(l - 1);
	}

protected:
	int BIT[MAXN];
};

int n, q, m, v[MAXN];
FenwickTree BIT[MAXM];

int get_answer(int l, int r) {
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (BIT[i].query(l, r) > 0) {
			ans++;
		}
	}
	return ans;
}

void run_case() {
	cin >> n >> q >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		BIT[ v[i] ].update(i, 1);
	}
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			cout << get_answer(l, r) << endl;
		} else {
			int id, tipo;
			cin >> id >> tipo;
			BIT[ v[id] ].update(id, -1);
			v[ id ] = tipo;
			BIT[ v[id] ].update(id, 1);
		}
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


