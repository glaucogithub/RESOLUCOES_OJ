
// author: glaucoacassioc
// created on: January 13, 2022 7:11 PM

// Problem: Two Sets
// URL: https://cses.fi/problemset/task/1092/
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


void display(vector<int64_t> &A) {
	cout << (int)A.size() << '\n';
	for (auto a : A) {
		cout << a << " ";
	}
	cout << '\n';
}

void run_case() {
	int64_t n, sum, ans;
	cin >> n;
	sum = n * (n + 1) / 2;
	if (sum % 2 == 1) {
		cout << "NO" << '\n';
		return;
	} else {
		cout << "YES" << '\n';
		vector<int64_t> A, B;
		ans = sum / 2;
		for (int64_t i = n; i >= 1; i--) {
			if (i <= ans) {
				A.emplace_back(i);
				ans -= i;
			} else {
				B.emplace_back(i);
			}
		}
		display(A);
		display(B);
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
