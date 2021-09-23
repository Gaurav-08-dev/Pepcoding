/* approach 1 */

bool carPooling(vector<vector<int>>& trips, int capacity) {
    
    vector<pair<int,int>> v;
    for(int i=0;i<trips.size();i++)
    {
        v.push_back({trips[i][1],trips[i][0]});
        v.push_back({trips[i][2],-trips[i][0]});
    }
    
    sort(v.begin(),v.end());
    int passengers=0;
    for(int i=0;i<v.size();i++)
    {
        passengers+=v[i].second;
        if(passengers > capacity)
        {
            return false;
        }
    }
    
    return true;
}

/* approach 2 - without sorting*/

bool carPooling(vector<vector<int>>& trips, int capacity) {
        // looking for the extremes of my trip
		int tMin = INT_MAX, tMax = INT_MIN;
        for (vector<int> t: trips) {
            tMin = min(tMin, t[1]);
            tMax = max(tMax, t[2]);
        }
		// setting up an optimised travel array
        int tLen = tMax - tMin, travel[tLen], lmt;
        for (int &t: travel) t = 0;
        for (vector<int> t: trips) {
            lmt = t[2] - tMin;
            for (int i = t[1] - tMin; i < lmt; i++) {
                // increasing each slot in the trip t by the amount of transported passengers
                travel[i] += t[0];
                if (travel[i] > capacity) return false;
            }
        }
        return true;
    }