class Solution {
public:

    double dfs(unordered_map<string,list<pair<string,double>>> &adjlist,unordered_map<string,bool> & visited,string source, string des){
        visited[source] = true;

        if(source == des){
            return 1;
        }

        for(auto &nbr: adjlist[source]){
            string nbrnode = nbr.first;
            double nbrweight = nbr.second;

            if(visited[nbrnode] == false){
            double ans = dfs(adjlist,visited,nbrnode,des);
            if(ans != -1.0){
                return ans*nbrweight;
            }
            }
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string,list<pair<string,double>>> adjlist;

        for(int i =0; i< equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double wt = values[i];

            adjlist[u].push_back({v,wt});
            adjlist[v].push_back({u, 1.0 / wt});
        }
        vector<double> ans(queries.size());
        for(int i =0; i< queries.size(); i++){
            string source = queries[i][0];
            string des = queries[i][1];

            if(adjlist.find(source) == adjlist.end() ||
               adjlist.find(des) == adjlist.end()){

                ans[i] = -1.0;
                continue;
            }

            unordered_map<string,bool> visited;

            ans[i] = dfs(adjlist,visited,source,des);
        }

        return ans;
    }
};