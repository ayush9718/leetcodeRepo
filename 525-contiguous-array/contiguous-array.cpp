class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        //           sum,index
        unordered_map<int,int> mp;
        mp[0] = -1;
        int currsum = 0;
        int ans =0;
        for(int i =0; i<n;i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
            currsum += nums[i];
            if(mp.find(currsum) != mp.end()){
                ans = max(ans,i - mp[currsum]);
            }
            else{
                mp[currsum] = i;
            }
        }

        return ans;
    }
};