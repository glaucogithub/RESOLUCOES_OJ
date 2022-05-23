
// author: glaucoacassioc
// created on: September 17, 2021 2:00 AM

// Problem: Repetitions
// URL: https://cses.fi/problemset/task/1069
// Time Limit: 1000 ms
// Memory Limit: 512 MB

#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int ans, cnt;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	getline(cin, s);
	for (size_t i = 1; i < s.length(); ++i) {
		if (s[i] == s[i - 1]) {
			++cnt;
			ans = max(ans, cnt);
		} else {
			cnt = 0;
		}
	}
	cout << ans + 1 << '\n';
}
