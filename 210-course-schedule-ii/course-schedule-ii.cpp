class Solution {
public:
    void solve(int n, vector<int>& toposort, unordered_map<int,list<int>> adjlist){
        queue<int> q;
        map<int,int> indegree;

        for(int i =0; i< n; i++){
            for(auto nbr: adjlist[i]){
                indegree[nbr]++;
            }
        }
        
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int frontnode = q.front();
            q.pop();

            toposort.push_back(frontnode);

			for(auto nbr: adjlist[frontnode]) {
				indegree[nbr]--;

				if(indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
        }

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adjlist;
        vector<int> toposort;

        for( int i =0 ; i< prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adjlist[u].push_back(v);
        }

        solve(numCourses,toposort, adjlist);

        // reverse(toposort.begin(),toposort.end());
        if(toposort.size()!=numCourses){
            return {};
        }
        return toposort;
    }
};