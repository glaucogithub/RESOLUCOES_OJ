#define MAXN 1000
int n, m, memo[MAXN][MAXN];

int get_answer(int n, int m, string s, string t) {
    if (n < 0 || m < 0) {
        return 0;
    }
    if (memo[n][m] != -1) {
        return memo[n][m];
    }
    if (s[n - 1] == t[m - 1]) {
        memo[n][m] = 1 + get_answer(n - 1, m - 1, s, t);
    } else {
        memo[n][m] = max(get_answer(n - 1, m, s, t), get_answer(n, m - 1, s, t));
    }
    return memo[n][m];
}

int lcs(string s, string t) {
    n = (int)s.size();
    m = (int)t.size();
    memset(memo, -1, sizeof memo);
    int ans = get_answer(n, m, s, t);
    return ans - 1;
}
