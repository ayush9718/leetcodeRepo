class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n, 0);

        // unordered_set allows average O(1) edge lookup
        vector<unordered_set<int>> adj(n + 1);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].insert(v);
            adj[v].insert(u);

            indegree[u - 1]++;
            indegree[v - 1]++;
        }

        vector<int> odd;

        for (int i = 0; i < n; i++) {
            if (indegree[i] % 2 == 1) {
                odd.push_back(i + 1);
            }
        }

        // Already all degrees are even
        if (odd.size() == 0) {
            return true;
        }

        // Two edges can fix at most 4 odd nodes
        if (odd.size() > 4) {
            return false;
        }

        // Exactly 2 odd-degree nodes
        if (odd.size() == 2) {
            int a = odd[0];
            int b = odd[1];

            // Option 1: directly connect a and b
            if (adj[a].find(b) == adj[a].end()) {
                return true;
            }

            // Option 2: a -- x -- b
            for (int x = 1; x <= n; x++) {
                if (x == a || x == b) {
                    continue;
                }

                if (adj[a].find(x) == adj[a].end() &&
                    adj[b].find(x) == adj[b].end()) {
                    return true;
                }
            }

            return false;
        }

        // Exactly 4 odd-degree nodes
        if (odd.size() == 4) {
            int a = odd[0];
            int b = odd[1];
            int c = odd[2];
            int d = odd[3];

            // (a,b) and (c,d)
            if (adj[a].find(b) == adj[a].end() &&
                adj[c].find(d) == adj[c].end()) {
                return true;
            }

            // (a,c) and (b,d)
            if (adj[a].find(c) == adj[a].end() &&
                adj[b].find(d) == adj[b].end()) {
                return true;
            }

            // (a,d) and (b,c)
            if (adj[a].find(d) == adj[a].end() &&
                adj[b].find(c) == adj[b].end()) {
                return true;
            }

            return false;
        }

        return false;
    }
};