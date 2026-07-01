class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int maxChoose, int total, int mask, bool turn) {

        if (total <= 0)
            return !turn;

        if (dp[mask][turn] != -1)
            return dp[mask][turn];

        if (turn) { // Alice

            for (int i = 0; i < maxChoose; i++) {
                if ((mask & (1 << i)) == 0) {

                    if (solve(maxChoose,
                              total - (i + 1),
                              mask | (1 << i),
                              false))
                        return dp[mask][turn] = true;
                }
            }

            return dp[mask][turn] = false;
        }
        else { // Bob

            for (int i = 0; i < maxChoose; i++) {
                if ((mask & (1 << i)) == 0) {

                    if (!solve(maxChoose,
                               total - (i + 1),
                               mask | (1 << i),
                               true))
                        return dp[mask][turn] = false;
                }
            }

            return dp[mask][turn] = true;
        }
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if (desiredTotal == 0)
            return true;

        int total = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if (total < desiredTotal)
            return false;

        if (total == desiredTotal)
            return (maxChoosableInteger & 1);

        dp.assign(1 << maxChoosableInteger, vector<int>(2, -1));

        return solve(maxChoosableInteger, desiredTotal, 0, true);
    }
};