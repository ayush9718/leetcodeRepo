class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n== 1|| n == 0){
            return 0;
        }

        set<pair<int,int>> visited;
        queue<pair<int,int>> q;

        for(int i =0;i<n; i++){
            int mask = 1<<i;

            q.push({i,mask});
            visited.insert({i,mask});
        }


        int allvisited = (1<<n) -1;
        int ans = 0;

        while(!q.empty()){
            int N = q.size();
            ans++;
            while(N--){
                auto [currnode, currmask] = q.front();
                q.pop();

                for(auto &nbr: graph[currnode]){
                    int newmask = currmask | (1<<nbr);

                    if(newmask == allvisited){
                        return ans;
                    }

                    if(visited.find({nbr,newmask}) != visited.end()){
                        continue;
                    }

                    q.push({nbr,newmask});
                    visited.insert({nbr,newmask});
                }
            }

        }
        
        return -1;
    }
};