class Solution {
public:
    bool dfs(unordered_map<int,list<int>> &graph, int source ,int &destination,unordered_map<int,bool> &visited){
        visited[source] = true;
        if(source == destination){
            return true;
        }

        for(auto nbr: graph[source]){
            if(visited[nbr] == false){
                bool ans = dfs(graph,nbr,destination, visited);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>> graph;
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_map<int,bool> visited;

        return dfs(graph,source,destination,visited);
    }
};