
// author: glaucoacassioc
// created on: September 22, 2021 2:14 PM

// Problem: Gravel
// URL: https://www.codechef.com/problems/SPREAD
// Time Limit: 268 ms
// Memory Limit: 256 MB

#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

const int MAXN = (int)2e6 + 10;
vector<int64_t> ft(MAXN);

int64_t query(int pos) {
	int64_t sum = 0;
	for (; pos > 0; pos -= pos & (-pos)) {
		sum += ft[pos];
	}
	return sum;
}

int64_t query(int l, int r) {
	return query(r) - (l == 1 ? 0 : query(l - 1));
}

void update(int pos, int val) {
	for (; pos < (int)ft.size(); pos += pos & (-pos)) {
		ft[pos] += val;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n, m, c;
	char op;
	cin >> n >> m >> c;
	update(1, c);
	for (int i = 1; i <= m; ++i) {
		cin >> op;
		if (op == 'S') {
			int l, r, k;
			cin >> l >> r >> k;
			update(l, k);
			update(r + 1, -k);
		} else {
			int p;
			cin >> p;
			cout << query(p) << '\n';
		}
	}
}
