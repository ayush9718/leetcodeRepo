class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixM(n,1);
        vector<int> suffixM(n,1);

        for(int i = 1; i<n; i++){
            prefixM[i] = nums[i-1]*prefixM[i-1];
        }
        for(int i = n-2; i>=0; i--){
            suffixM[i] = nums[i+1]*suffixM[i+1];
        }
        vector<int> ans(n);
        for(int i =0; i<n; i++){
            ans[i] = prefixM[i]*suffixM[i];
        }

        return ans;
    }
};