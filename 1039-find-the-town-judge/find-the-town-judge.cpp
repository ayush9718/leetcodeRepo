class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> degree(n+1,0);

        for(auto &node : trust){
            int u = node[0];
            int v = node[1];
            degree[u]--;   
            degree[v]++;   
        }

        for(int i=1; i<=n; i++){
            if(degree[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};