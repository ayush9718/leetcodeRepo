class Solution {
public:

    void solve(unordered_map<int,list<int>>& graph, unordered_map<int,bool>&visited, int source){
        visited[source] = true;

        for(auto &nbr: graph[source]){
            if(visited[nbr] == true){
                continue ;
            }

            solve(graph,visited,nbr);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        unordered_map<int,list<int>> graph;

        for(int i = 0; i<n; i++){
            for(int j = 0;j<rooms[i].size(); j++){
                graph[i].push_back(rooms[i][j]);
            }
        }

        unordered_map<int,bool> visited;

        solve(graph,visited,0);

        if(visited.size() == n){
            return true;
        }

        return false;

    }
};