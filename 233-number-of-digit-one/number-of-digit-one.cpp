class Solution {
    vector<vector<vector<int>>>dp;
public:
    int solve(string& s, int index, bool tight, int count1){
        if(index==s.size()){
            return count1;
        }

        if(dp[index][tight][count1]!=-1){
            return dp[index][tight][count1];
        }
        int upperbound = tight == 1 ? s[index] - '0' : 9;
        
        int ans = 0;
        for(int digi = 0 ;digi<= upperbound; digi++){
            bool newtight = (tight && (digi == upperbound));
            int newcount1 = digi == 1? count1+1 : count1; 
            ans+= solve(s,index+1,newtight,newcount1);
        }

        return dp[index][tight][count1] = ans;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        dp.assign(s.length()+1,vector<vector<int>>(2,vector<int>(s.length()+1,-1)));
        return solve(s,0,true,0);
    }
};