class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        // adjacency list: {neighbor, weight}
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: roads){
            int u = it[0], v=it[1], wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
         priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<>> pq;
       vector<long long> minTime(n, LLONG_MAX);
       vector<int> ways(n,0);
       minTime[0] = 0;
       ways[0]=1;
       pq.push({0,0});
       while(!pq.empty()){
         long long time = pq.top().first;
         int node = pq.top().second;
         pq.pop();

         if(time > minTime[node]) continue;
         for(auto &[nbr, wt] : adj[node]){
                long long newTime = time + wt;

                // found shorter path
                if(newTime< minTime[nbr]){
                    minTime[nbr] = newTime;
                    ways[nbr] = ways[node]; 
                    pq.push({newTime, nbr});
                }
                else if(newTime == minTime[nbr]){
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD;
                }
         }
       }
       return ways[n-1];
    }
};