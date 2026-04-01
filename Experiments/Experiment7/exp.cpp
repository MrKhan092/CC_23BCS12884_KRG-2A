class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:flights){
            int u=i[0];
            int v=i[1];
            int c=i[2];
            adj[u].push_back({v,c});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto i=q.front();
            int st=i.first;
            int node=i.second.first;
            int cost=i.second.second;
            q.pop();
            if(st>k) continue;
            for(auto i:adj[node]){
                int next=i.first;
                int ncost=i.second;
                if(st<=k && cost+ncost<dist[next]){
                    dist[next]=cost+ncost;
                    q.push({st+1,{next,dist[next]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        else return dist[dst];
    }
};