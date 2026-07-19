class Solution {
public:
    int atmost(vector<int>&nums,int k){
        int left =0;
        int n = nums.size();
        int oddcount = 0;
        int ans =0;

        for(int right = 0; right<n; right++){
            int curr = nums[right];
            if(curr&1){
                oddcount++;
            }
            while(oddcount>k){
                if(nums[left]&1){
                    oddcount--;
                }
                left++;
            }

            ans+= right-left+1;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};