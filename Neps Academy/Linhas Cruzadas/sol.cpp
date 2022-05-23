
// author: glaucoacassioc
// created on: October 05, 2021 12:12 AM

// Problem: Linhas Cruzadas
// URL: https://neps.academy/br/exercise/63
// Time Limit: 1000 ms
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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

vector<int64_t> v, ft;
int64_t ans;

int64_t query(int64_t pos) {
	int64_t sum = 0;
	for (; pos > 0; pos -= pos & (-pos)) {
		sum += ft[pos];
	}
	return sum;
}

void update(int64_t pos, int val) {
	for (; pos < (int)ft.size(); pos += pos & (-pos)) {
		ft[pos] += val;
	}
}

void build(int n) {
	ft.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		ans += (i - 1) - query(v[i] - 1);
		update(v[i], 1);
	}
}

void run_case() {
	int n;
	cin >> n;
	v.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	build(n);
	cout << ans << '\n';
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
