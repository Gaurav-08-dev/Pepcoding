struct node{
      
        int x,y,dist;
        
        bool operator()(node& a, node& b)
        {
            return a.dist > b.dist;
        }
    };
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        
        priority_queue<node,vector<node>,node> pq;
        
        int n=points.size(), result=0, edges=0, cur=0;
        vector<bool> visited(n);
        
        while(edges < n-1)
        {
            visited[cur]=true;
            edges++;
            
            for(int i=0;i<n;i++)
            {
                if(visited[i]) continue;
                
                int dist= abs(points[i][0] - points[cur][0]) + abs(points[i][1] - points[cur][1]);
                pq.push({i,cur,dist});
            }
            
            while(!pq.empty() and visited[pq.top().x]==true)
                pq.pop();
            
            node newEdge=pq.top(); pq.pop();
            cur=newEdge.x;
            result+=newEdge.dist;
        }
        
        return result;
                
    }