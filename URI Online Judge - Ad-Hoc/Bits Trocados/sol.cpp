
// author: glaucoacassioc
// created on: September 22, 2021 1:00 PM

// Problem: Bits Trocados
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2187
// Time Limit: 1000 ms
// Memory Limit: 1024 MB

#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, cnt;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	vector<int> a = {50, 10, 5, 1};
	while (cin >> n && n > 0) {
		cout << "Teste " << ++cnt << '\n';
		for (int i = 0; i < 4; ++i) {
			if (i < 3) {
				cout << n / a[i] << " ";
				n %= a[i];
			} else {
				cout << n / a[i];
			}
		}
		cout << "\n\n";
	}
}
