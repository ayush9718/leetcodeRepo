class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    vector<vector<int>> dp;

    int solve(string &s, int index, int prev) {
        if (index == n) {
            return 1;
        }

        if (dp[index][prev] != -1) {
            return dp[index][prev];
        }

        long long ans = 0;

        int remaining = n - index;

        if (s[index] == 'I') {
            for (int next = prev; next < remaining; next++) {
                ans += solve(s, index + 1, next);
                ans %= MOD;
            }
        } else {
            for (int next = 0; next < prev; next++) {
                ans += solve(s, index + 1, next);
                ans %= MOD;
            }
        }

        return dp[index][prev] = ans;
    }

    int numPermsDISequence(string s) {

        n = s.length();

        dp.assign(n, vector<int>(n + 1, -1));

        long long ans = 0;
        for (int first = 0; first <= n; first++) {
            ans += solve(s, 0, first);
            ans %= MOD;
        }
        return ans;
    }
};