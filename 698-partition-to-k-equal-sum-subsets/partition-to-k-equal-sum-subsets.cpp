class Solution {
public:
    int n;
    // using bitmasking for visited because nums.length is small
    bool solve(vector<int>& nums, int mask, int index, int currsum, int target, int k){
        if(k == 1){
            return true;
        }

        if(currsum == target){
            return solve(nums,mask,0,0,target,k-1);
        }

        for(int i =index; i<n; i++){
            if(mask&(1<<i)){
                continue ;
            }
            if(currsum + nums[i] >target){
                continue ;
            }

            bool recans = solve(nums, mask|(1<<i) ,i+1,currsum+nums[i],target,k);

            if(recans == true){
                return true;
            }

        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int sum = 0;
        for(int i =0; i<n; i++){
            sum += nums[i];
        }
        if(sum%k != 0){
            return false ;
        }

        return solve(nums,0,0,0,sum/k,k);
    }
};