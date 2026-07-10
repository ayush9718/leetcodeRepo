class Solution {
public:
   static bool cmp(const int& a, const int& b) {
        return a>b;
    }

    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();

        vector<vector<int>> adjlist(n);

        for (auto& edge :edges) {
            int u = edge[0];
            int v = edge[1];

            adjlist[u].push_back(vals[v]);
            adjlist[v].push_back(vals[u]);
        }

        int ans = *max_element(vals.begin(), vals.end());

        for (int i=0; i<n; i++) {
            sort(adjlist[i].begin(), adjlist[i].end(), cmp);

            int sum = vals[i];
            int m = min(k,(int)adjlist[i].size());
            for (int j=0; j< m  ; j++) {
                if (adjlist[i][j] <= 0) {
                    break;
                }

                sum +=adjlist[i][j];
            }

            ans = max(ans, sum);
        }

        return ans;
        
    }
};