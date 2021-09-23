   int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n=position.size(), ans=1;
        vector<pair<int,double>> vp(n);
        for(int i=0;i<n;i++)
        {
            vp[i].first=position[i];
            vp[i].second=(double)(target-position[i])/(double)speed[i];
        }
        
        sort(vp.begin(),vp.end());
       /* for(int i=0;i<n;i++){
            cout<<vp[i].first<<" "<<vp[i].second<<"\n";
        }*/
        double slowest=vp[n-1].second;
        
        for(int i=n-2;i>=0;i--){
            if(slowest < vp[i].second)
            {
                ans++;
                slowest=vp[i].second;
            }
        }
        
        return ans;
    }