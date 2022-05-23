
// author: glaucoacassioc
// created on: September 14, 2021 12:24 AM

// Problem: Cumulative Sum Query
// URL: https://www.spoj.com/problems/CSUMQ/
// Time Limit: 7000 ms
// Memory Limit: 1536 MB

#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int64_t> pref, v;
int n, q;

void build(int n) {
	pref.emplace_back(v[0]);
	for (int i = 1; i <= n; ++i) {
		pref.emplace_back(pref[i - 1] + v[i]);
	}
}

int64_t query(int l, int r) {
	return pref[r] - pref[l - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	build(n);
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == 0) {
			cout << pref[r] << '\n';
		} else {
			cout << query(l, r) << '\n';
		}
	}
}
