
// author: glaucoacassioc
// created on: September 22, 2021 1:04 AM

// Problem: Dynamic Range Sum Queries
// URL: https://cses.fi/problemset/task/1648/
// Time Limit: 1000 ms
// Memory Limit: 512 MB

#include <bits/stdc++.h>
using namespace std;

#define LSONE(S) ((S & (-S)))

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int64_t> ft, v;

void update(int k, int val) {
	for (; k < (int)ft.size(); k += LSONE(k)) {
		ft[k] += val;
	}
}

void build(int n) {
	ft.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		update(i, v[i]);
	}
}

int64_t query(int b) {
	int64_t sum = 0;
	for (; b; b -= LSONE(b)) {
		sum += ft[b];
	}
	return sum;
}

int64_t query(int l, int r) {
	return query(r) - (l == 1 ? 0 : query(l - 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	v.assign(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	build(n);
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int k, u;
			cin >> k >> u;
			update(k, u - v[k]);
			v[k] = u;
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << '\n';
		}
	}
}
