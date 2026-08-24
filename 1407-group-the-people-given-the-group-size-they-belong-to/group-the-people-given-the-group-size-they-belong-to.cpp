class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int> > mp;
        vector<vector<int>> ans;
        for(int i =0; i<groupSizes.size(); i++){
            int curr = groupSizes[i];
            mp[curr].push_back(i);


            if (mp[curr].size() == curr) {
                ans.push_back(mp[curr]);
                mp[curr].clear();
            }
        }
        return ans;
    }
};