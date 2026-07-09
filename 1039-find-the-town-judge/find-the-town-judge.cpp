class Solution {
public:
    void BFS(int n, unordered_map<int,list<int>> &graph, vector<int>& indegree,vector<int> &outdegree,unordered_map<int,bool>& visited, int src){
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int frontnode = q.front();
            q.pop();

            for(auto &nbr: graph[frontnode]){
                outdegree[frontnode-1]++;
                indegree[nbr-1]++;

                if(!visited[frontnode]){
                    q.push(nbr);
                }
            }            
        }
        return ;
        
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,list<int>> graph;

        for(int i =0; i<trust.size(); i++){
            int u = trust[i][0];
            int v = trust[i][1];

            graph[u].push_back(v);
        }

        // find outdegre and indegere then check 

        vector<int> indegree(n);
        vector<int> outdegree(n);

        unordered_map<int,bool> visited;

        for(int i= 1;i<=n; i++){
            if(!visited[i]){
                BFS(n,graph,indegree,outdegree,visited,i);
            }
        }


        for(int i= 0; i<n; i++){
            if(indegree[i] == n-1 && outdegree[i] == 0){
                return i+1;
            }
        }

        return -1;


    }
};