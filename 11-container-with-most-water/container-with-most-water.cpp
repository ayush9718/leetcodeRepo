class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        int left = 0;
        int right = n-1;

        while(left<right){
            int width = right - left;
            int height = min(heights[right],heights[left]);

            int area = width*height;
            ans = max(ans,area);

            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return ans;
    }
};