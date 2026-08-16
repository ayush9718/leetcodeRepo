class Solution {
public:
    int dp[11][2][1024][2][2];
    int solve(string &s, int index, bool tight,int mask, bool duplicate , bool leadingzeroes){
        if(index>=s.size()){
            if(duplicate && leadingzeroes){
                return 1;
            }
            return 0;
        }

        if (dp[index][tight][mask][duplicate][leadingzeroes] != -1) {
            return dp[index][tight][mask][duplicate][leadingzeroes];
        }

        int lb = 0;
        int ub = tight == true ? s[index]-'0' : 9;
        long long ans = 0;
        for(int i =lb; i<=ub; i++){
            
            bool newtight = tight && (i == s[index] - '0');

            bool newduplicate = duplicate;
            bool newleadingzeroes = leadingzeroes;
            int newmask = mask; 

             if (!leadingzeroes && i == 0) {
                newleadingzeroes = false;
            }
            else {
                newleadingzeroes = true;

                if (mask & (1 << i)) {
                    newduplicate = true;
                }

                newmask |= (1 << i);
            }

            ans+= solve(s,index+1, newtight,newmask,newduplicate,newleadingzeroes);
        }
        
        return dp[index][tight][mask][duplicate][leadingzeroes] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s,0,true, 0, false,false);
    }
};