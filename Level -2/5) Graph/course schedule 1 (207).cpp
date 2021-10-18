class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        int n=pre.size();
                
        vector<int> graph[numCourses+1];
        
        for(int i=0;i<n;i++)
        {
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        
        
        
        vector<int> indegree(numCourses);
        for(int i=0;i<indegree.size();i++)
        {
            for(auto it:graph[i])
            {
                indegree[it]++;
            }
        }
        
        
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        
        int count=0;
        
        while(!q.empty())
        {
            int node=q.front(); q.pop();
            count++;
            for(auto adj: graph[node])
            {
                indegree[adj]--;
                if(indegree[adj]==0)
                {
                    q.push(adj);
                }
            }
        }
        
        if(count==numCourses) return true;
        return false;
    }
};