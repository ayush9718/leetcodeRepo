class Solution {
public:
    unordered_map<string, int> mp;
    int n;
    int allvisited;
    vector<vector<long long>> dp;

    long long solve(vector<vector<string>>& ppl, int index, int mask){

        if (mask == allvisited){
            return 0;
        }

        if (index == n){
            return LLONG_MAX;
        }

        if (dp[index][mask] != -1){
            return dp[index][mask];
        }

        // include
        int newmask = mask;

        for (auto skill : ppl[index]){
            int idx = mp[skill];
            newmask |= (1 << idx);
        }

        long long include = solve(ppl, index + 1, newmask);

        if (include != LLONG_MAX){
            include |= (1LL << index);
        }

        // exclude
        long long exclude = solve(ppl, index + 1, mask);


        if (__builtin_popcountll(include) < __builtin_popcountll(exclude)){
            return dp[index][mask] = include;
        }

        return dp[index][mask] = exclude;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills,vector<vector<string>>& people) {

        for(int i = 0;i < req_skills.size();i++){
            mp[req_skills[i]] = i;
        }

        allvisited = (1 << req_skills.size()) - 1;
        n = people.size();

        dp.assign(n, vector<long long>(1<<req_skills.size(),-1));

        long long mask = solve(people, 0, 0);

        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(mask & (1LL << i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};