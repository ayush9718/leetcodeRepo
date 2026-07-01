class Solution {
public:
    vector<int> dp;
    bool solve(int maxChoose,int total, int k){
        if(total<=0) return false;

        if(dp[k]!=-1){
            return dp[k];
        }
        for(int i= 0; i<maxChoose; i++){
            if( (k&(1<<i)) == false ){
                if( solve(maxChoose,total-(i+1),k|1<<i) == false){
                    return dp[k] = true;
                }
            }
        }

        return dp[k] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal == 0){
            return true;
        }
        int total = (maxChoosableInteger*(maxChoosableInteger+1))/2;
        if(total < desiredTotal){
            return false;
        }
        if(total == desiredTotal){
            return (maxChoosableInteger&1) == 1;
        }

        dp.assign(1 << maxChoosableInteger,-1);
        // 0 is bitmask here
        return solve(maxChoosableInteger,desiredTotal,0);
    }
};