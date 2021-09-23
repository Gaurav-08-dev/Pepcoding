    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int total_sum=0,index=0,tank=0; 
        
        for(int i=0;i<gas.size();i++)
        {
            total_sum+= gas[i]-cost[i];
            tank+=gas[i]-cost[i];
            
            if(tank<0)
            {
                index=i+1;
                tank=0;
            }
        }
        
        return total_sum<0? -1:index;
    }