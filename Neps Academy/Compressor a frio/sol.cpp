
// author: glaucoacassioc
// created on: September 18, 2021 2:44 PM

// Problem: Compressor a frio
// URL: https://neps.academy/br/competition/975/exercise/1735
// Time Limit: 1000 ms
// Memory Limit: 256 MB

#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n;
	string s;
	char ant;
	cin >> n;
	cin.ignore();
	while (n--) {
		int cnt = 0;
		getline(cin, s);
		for (char ch : s) {
			if (cnt > 0 && ch != ant) {
				cout << cnt << " " << ant << " ";
				cnt = 0;
			}
			cnt++;
			ant = ch;
		}
		cout << cnt << " " << ant << '\n';
	}
}
