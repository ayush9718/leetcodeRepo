class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool present_one = false;
        for(int i =0; i<n;i++){
            if(nums[i] == 1){
                present_one = true;
            }
             if(nums[i] >n || nums[i]<=0){
                nums[i] = 1;
            }
        }
        if(present_one == false){
            return 1;
        }


        for(int i =0; i<n; i++){
            int curr = abs(nums[i]);
            int index = curr-1;

            if(nums[index] >0){
                nums[index] = nums[index]*-1;
            }
        }

        int ans = n+1;
        for(int i =0;i<n; i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        for(int i =0; i<n; i++){
            int curr = nums[i];
            if(curr >0){
                return  i+1;
            }
        }
        return ans;
    }
};