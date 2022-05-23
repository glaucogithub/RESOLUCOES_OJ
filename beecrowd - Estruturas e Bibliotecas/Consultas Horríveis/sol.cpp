
// author: glaucoacassioc
// created on: February 17, 2022 11:57 AM

// Problem: Consultas Horríveis
// URL: https://www.beecrowd.com.br/judge/pt/problems/view/1500
// Time Limit: 4000 ms
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

#define MAXN 100100 //10^6
int64_t a[MAXN], t[4 * MAXN], lazy[4 * MAXN];

// In the main program this function will be called with the parameters of the root vertex: v=1, tl=0, and tr=n−1.
void build(int64_t v, int64_t tl, int64_t tr) {
	if (tl == tr) {
		t[v] = a[tl];
	} else {
		int64_t tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

void push(int64_t v, int64_t tl, int64_t tr) {
	// Tomar cuidado porque tem problema que atualiza pra zero, mas é so tratar isso...
	// Se o problema pedir o incremento do intervalo [l, r] entao coloca um + no t[v] e nos dois lazy de tl != tr.
	if (lazy[v]) {
		t[v] += (tr - tl + 1) * lazy[v];
		// se nao sou uma folha entao atualizo pros meus filhos
		if (tl != tr) {
			lazy[v * 2] += lazy[v];
			lazy[v * 2 + 1] += lazy[v];
		}
		// Quando nao tem lazy eu seto pra 0
		lazy[v] = 0LL;
	}
}

int64_t query(int64_t v, int64_t tl, int64_t tr, int64_t l, int64_t r) {
	// Toda vez que eu chegar no nó eu preciso ver se tem alguma atualizacao nele entao eu verifico chamando o push()
	push(v, tl, tr);
	if (tl > r || tr < l) {
		return 0LL;
	}
	if (tl >= l && tr <= r) {
		return t[v];
	}
	int64_t tm = (tl + tr) / 2;
	return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
}

void update(int64_t v, int64_t tl, int64_t tr, int64_t l, int64_t r, int64_t new_val) {
	push(v, tl, tr);
	if (tl > r || tr < l) {
		return;
	}
	if (tl >= l && tr <= r) {
		lazy[v] += new_val;
		push(v, tl, tr);
		return;
	} else {
		int64_t tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, r, new_val);
		update(v * 2 + 1, tm + 1, tr, l, r, new_val);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

void run_case() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= 4 * MAXN; i++) {
		t[i] = lazy[i] = 0LL;
	}
	while (q--) {
		int64_t op, l, r;
		cin >> op >> l >> r;
		if (l > r) {
			swap(l, r);
		}
		if (op == 0) {
			int64_t val;
			cin >> val;
			update(1, 1, n, l, r, val);
		} else {
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
#ifndef DEBUG
	cin.tie(nullptr);
#endif
	int T = 1;
	cin >> T;
	while (T-- > 0) {
		run_case();
	}
}


