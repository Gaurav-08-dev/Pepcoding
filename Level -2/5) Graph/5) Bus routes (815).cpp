 int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source==target)
        {
            return 0;
        }
        
        unordered_map<int,unordered_set<int>> m;
        
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++){
                
                m[routes[i][j]].insert(i);
            }
        }
        
        unordered_set<int> visited;
        queue<int> q;
        
        for(auto r: m[source])
        {
            // cout<<r<<" ";
            q.push(r);
            visited.insert(r);
        }
        
        int dist=1;
        
        while(q.size())
        {
            int size=q.size();
            
            // cout<<size<<"\n";
            for(int i=0;i<size;i++)
            {
                int route=q.front();q.pop();
                int start=-1;
                cout<<route<<"\n\n";
                for(auto bs: routes[route])
                {
                    cout<<bs;
                    // cout<<bs<<"\n";
                    if(start==-1)
                    {
                        start=bs;
                    }
                    else if(start==bs)
                    {
                        break;
                    }
                    
                    if(bs==target)
                    {
                        return dist;
                    }
                    
                    for(auto access_routes : m[bs])
                    {
                        if(!visited.count(access_routes))
                        {
                            // cout<<access_routes<<"\n";
                            visited.insert(access_routes);
                            q.push(access_routes);
                        }
                    }
                    cout<<"\n";
                }
                
            }
            dist++;
        }
        
        return -1;
        
    }