class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int,vector<int>> maxheap;
        int n = nums.size();

        int mini = INT_MAX;

        for(auto &num : nums){
            if(num%2 == 1) num*=2;
            mini = min(mini,num);
            maxheap.push(num);
        }


        int diff = INT_MAX;
        while(!maxheap.empty()){
            int maxi = maxheap.top();
            maxheap.pop();

            diff = min(diff, maxi - mini);

            if(maxi%2 == 1){
                break ;
            }

            maxi = maxi/2;
            mini = min(mini,maxi);
            maxheap.push(maxi);
        }

        return diff;
    }
};