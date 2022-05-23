
// author: glaucoacassioc
// created on: September 12, 2021 2:33 PM

// Problem: Soma Fácil
// URL: https://neps.academy/br/exercise/134
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
	int a, b;
	cin >> a >> b;
	cout << a + b << '\n';
}
