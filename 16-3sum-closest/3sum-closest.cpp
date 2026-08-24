class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = 1e8;
        
        for(int i=0;i<n-2;i++) {

            int l=i+1, r= n-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                
                if(abs(target-sum) < abs(target-ans)) {
                    ans = sum;
                }
                
                if(sum > target) r--;
                else l++;
            }
        }
        return ans; 
    }
};