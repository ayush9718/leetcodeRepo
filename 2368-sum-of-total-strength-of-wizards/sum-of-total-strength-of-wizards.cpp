class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const long long MOD = 1e9 + 7;
        int n = strength.size();

        vector<int> left(n), right(n);
        stack<int> st;

        for (int i=0; i<n; i++){
            while (!st.empty() && strength[st.top()] >= strength[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && strength[st.top()] > strength[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i< n; i++) {
            prefix[i+1] = (prefix[i] + strength[i]) % MOD;
        }

        vector<long long> prefixPrefix(n + 2, 0);

        for (int i = 0; i<=n; i++){
            prefixPrefix[i + 1] = (prefixPrefix[i] + prefix[i]) % MOD;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int L = left[i];
            int R = right[i];

            long long leftCount = i - L;
            long long rightCount = R - i;


            long long rightSum = (prefixPrefix[R + 1] - prefixPrefix[i + 1] + MOD) % MOD;

            long long leftSum = (prefixPrefix[i + 1] - prefixPrefix[L + 1] + MOD) % MOD;

            long long contribution = (rightSum * leftCount % MOD - leftSum * rightCount % MOD + MOD) % MOD;

            contribution =  contribution * strength[i] % MOD;
            ans = (ans + contribution) % MOD;
        }
        
        return ans;
    }
};