class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> indegree;

        for(int i =0 ; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[v]+=1;
            indegree[u]+=1;
        }

        int maxdegree = 0;
        int maxnode = 1;
        for(auto &it: indegree){
            int node = it.first;
            int degree = it.second;

            if(degree>maxdegree){
                maxdegree = degree;
                maxnode = node;
            }
        }

        return maxnode;
    }
};