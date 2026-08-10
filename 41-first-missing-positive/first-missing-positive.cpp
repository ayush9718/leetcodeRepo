class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,bool> mp;

        for(int i=0; i<n; i++){
            if(nums[i]<=0){
                continue ;
            }
            mp[nums[i]] = true;
        }

        for(int i =1; i<=n+1; i++){
            if(mp[i] == false){
                return i;
            }
        }

        return 1;
    }
};