
// author: glaucoacassioc
// created on: September 18, 2021 2:33 PM

// Problem: Pontuação vencedora
// URL: https://neps.academy/br/competition/975/exercise/1733
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
	vector<int> v(6);
	for (int i = 0; i < 6; ++i) {
		cin >> v[i];
	}
	int apple = v[0] * 3 + v[1] * 2 + v[2];
	int banana = v[3] * 3 + v[4] * 2 + v[5];
	cout << (apple > banana ? 'A' : (apple < banana ? 'B' : 'T')) << '\n';
}
