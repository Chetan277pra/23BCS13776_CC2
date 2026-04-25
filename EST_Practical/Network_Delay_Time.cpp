class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>> adj(n+1);
        for(auto a : times){
            int u = a[0];
            int v = a[1];
            int time = a[2];
            adj[u].push_back({v , time});
        }
        vector<int> dist(n+1 , INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int , int>,
        vector<pair<int , int>>, greater<pair<int , int>>
        > q;
        q.push({0 , k});

        while(!q.empty()){
            auto aa = q.top(); q.pop();
            int node = aa.second;
            int di = aa.first;
            
            for(auto a : adj[node]){
                int tempnode = a.first;
                int tempdist = a.second;
                if( (( di + tempdist ) != INT_MAX )and 
                    ( di + tempdist ) < dist[tempnode]){
                    dist[tempnode] = di + tempdist;
                    q.push({di + tempdist , tempnode});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int a = dist[i];
            if(a == INT_MAX) return -1;
            ans = max(ans , a);
        }
        return ans;
    }
};
