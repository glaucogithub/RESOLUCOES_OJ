
// author: glaucoacassioc
// created on: January 13, 2022 8:17 PM

// Problem: Sum of Two Values
// URL: https://cses.fi/problemset/task/1640
// Time Limit: 1000 ms
// Memory Limit: 512 MB

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

int esq, dir;

bool is_possible(vector<pair<int, int> > v, int n, int x) {
	esq = 0, dir = n - 1;
	while (esq < dir) {
		int64_t sum = v[esq].first + v[dir].first;
		if (sum == x) {
			return true;
		} else if (sum < x) {
			esq++;
		} else {
			dir--;
		}
	}
	return false;
}

void run_case() {
	int n, x;
	cin >> n >> x;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		v.push_back(make_pair(t, i + 1));
	}
	sort(v.begin(), v.end());
	if (is_possible(v, n, x)) {
		if (v[esq].second > v[dir].second) {
			swap(v[esq].second, v[dir].second);
		}
		cout << v[esq].second << " " << v[dir].second << '\n';
	} else {
		cout << "IMPOSSIBLE" << '\n';
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
