class Solution {
public:

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,vector<vector<int>>& friends,int id,
int level) {

        unordered_map<int, list<int>> adjlist;

        for(int i = 0; i<friends.size();i++){

            for(auto &friendI : friends[i]){
                adjlist[i].push_back(friendI);
            }
        }

        // BFS FOR LEVELS
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(id);
        visited[id] = true;

        int currLevel = 0;

        while(!q.empty() && currLevel < level) {

            int size=q.size();

            for(int i=0; i<size;i++){

                int node = q.front();
                q.pop();

                for(auto &nbr :adjlist[node]) {

                    if(!visited[nbr]){

                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }

            currLevel++;
        }


        unordered_map<string, int> freq;

        while(!q.empty()) {

            int person = q.front();
            q.pop();

            for(auto &video : watchedVideos[person]) {
                freq[video]++;
            }
        }


        vector<pair<int, string>> videos;

        for(auto &it: freq) {
            videos.push_back({it.second, it.first});
        }

        sort(videos.begin(), videos.end());

        vector<string> ans;

        for(auto &it :videos) {
            ans.push_back(it.second);
        }

        return ans;
    }
};