
// author: glaucoacassioc
// created on: October 26, 2021 3:45 PM

// Problem: Union-Find
// URL: https://open.kattis.com/problems/unionfind
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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

class UnionFind {
private:
	vector<int> p, rank, set_size;
	int numsets;
public:
	UnionFind(int n) {
		p.assign(n + 1, 0);
		// 1-indexed the parent
		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}
		rank.assign(n + 1, 0);
		set_size.assign(n + 1, 1);
		numsets = n;
	}

	int find_set(int i) {
		return (p[i] == i) ? i : (p[i] = find_set(p[i]));
	}

	bool isSameSet(int i, int j) {
		return find_set(i) == find_set(j);
	}

	void union_set(int i, int j) {
		if (isSameSet(i, j)) {
			return;
		}
		int x = find_set(i), y = find_set(j);
		if (rank[x] > rank[y]) {
			swap(x, y);
		}
		p[x] = y;
		if (rank[x] == rank[y]) {
			++rank[y];
		}
		set_size[y] += set_size[x];
		--numsets;
	}

	int numSet() {
		return numsets;
	}

	int sizeOfSet(int i) {
		return set_size[find_set(i)];
	}
};

void run_case() {
	int n, q, a, b;
	char op;
	cin >> n >> q;
	UnionFind UF(n + 1);
	for (int i = 0; i < q; ++i) {
		cin >> op >> a >> b;
		if (op == '=') {
			UF.union_set(a, b);
		} else {
			cout << (UF.isSameSet(a, b) ? "yes" : "no") << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	int T = 1;
	// cin >> T;
	while (T-- > 0) {
		run_case();
	}
}
